#include <Windows.h>
#include <iostream>
#include <string>

#include "MeshLoader.h"
#include "TextureSampler.h"
#include "Timer.h"
#include "PrimitiveConstructor.h"

TextureSampler* pTextureSampler;
PrimitiveConstructor* pContructor;
static HDC g_phdc = NULL;
Timer* g_pTimer;

Matrix4x4* pWorld;
Matrix4x4* pView;
Matrix4x4* pProject;

void DrawPixel(int x, int y, PixelColor c)
{
	if (x < 0 || y < 0)
		return;
	SetPixel(g_phdc, x, y, RGB(c.r, c.g, c.b));
}

void DrawBitmap(int x, int y, int width, int height, const void* bits)
{
	HBITMAP hBitmap = CreateBitmap(width, height, 1, 32, bits);
	HDC hdcMemDC = CreateCompatibleDC(g_phdc);
	SelectObject(hdcMemDC, hBitmap);
	BitBlt(g_phdc, x, y, width, height, hdcMemDC, 0, 0, SRCCOPY);
	DeleteDC(hdcMemDC);
	DeleteObject(hBitmap);
}

PixelShaderIn MyVertexShader(VertexShaderIn vIn, void* object)
{
	PixelShaderIn vOut;
	PrimitiveConstructor* p = (PrimitiveConstructor*)object;
	vOut.vertexPosition = Vec3Transform(vIn.position, p->matrixs[0]);
	vOut.color.x = vIn.color.x;
	vOut.color.y = vIn.color.y;
	vOut.color.z = vIn.color.z;
	vOut.color.w = 1;
	vOut.texCoord = vIn.texCoord;
	vOut.normal = vIn.normal;
	return vOut;
}

PixelColor MyPixelShader(PixelShaderIn pIn, void* object)
{
	PixelColor color;
	PrimitiveConstructor* p = (PrimitiveConstructor*)object;
	int x = pIn.texCoord.x * (p->samplers[0]->width - 1);
	int y = pIn.texCoord.y * (p->samplers[0]->height - 1);
	color = p->samplers[0]->rawData[y * p->samplers[0]->width + x];

	return color;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdcMem;
	HBITMAP hBitmap;
	int i;
	switch (msg)
	{
	case WM_PAINT:
		g_phdc = BeginPaint(hWnd, &ps);
		//g_phdc = GetDC(hWnd);
		/*hdcMem = CreateCompatibleDC(g_phdc);
		hBitmap = CreateBitmap(pTextureSampler->width, pTextureSampler->height, 1, 32, pTextureSampler->rawData);
		i = GetLastError();
		SelectObject(hdcMem, hBitmap);
		BitBlt(g_phdc, 0, 0, pTextureSampler->width, pTextureSampler->height, hdcMem, 0, 0, SRCCOPY);
		DeleteDC(hdcMem);*/
		SetWindowText(hWnd, std::to_string(g_pTimer->TimeTick()).c_str());
		//*pWorld = (*pWorld) * MatrixRotationY(g_pTimer->TimeMask());
		pContructor->matrixs[0] = (*pProject) * ((*pView) * (*pWorld));
		pContructor->ExecVertexSahder();
		pContructor->BackCull();
		pContructor->Clip();
		pContructor->PersDivide();
		pContructor->LineDraw();
		pContructor->TriangleDraw();
		

		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void GetProjectPath()
{

}

int main()
{
	/*char szFileName[256];
	memset(szFileName, '0', sizeof(szFileName));
	GetModuleFileName(NULL, szFileName, sizeof(szFileName));
	std::string path = szFileName;
	std::string projectPath = path.substr(0, path.find("SoftRender") + 10);
	std::string textureFilePath = projectPath + std::string("\\SoftRender\\resource\\sample.dds");
	std::string objPath = projectPath + std::string("\\SoftRender\\resource\\test.obj");

	TextureSampler textureSampler;
	int len = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)textureFilePath.c_str(), -1, NULL, 0);
	wchar_t* wszUtf8 = new wchar_t[len + 1];
	memset(wszUtf8, 0, len * 2 + 2);
	MultiByteToWideChar(CP_ACP, 0, (LPCSTR)textureFilePath.c_str(), -1, (LPWSTR)wszUtf8, len);
	std::wstring wPath = wszUtf8;
	delete[] wszUtf8;
	textureSampler.LoadDDSTexture(wPath.c_str());
	pTextureSampler = &textureSampler;*/

	TextureSampler textureSampler;
	textureSampler.LoadDDSTexture(L"resource\\sample.dds");
	pTextureSampler = &textureSampler;


	const char *const wndName = "SoftRender";
	HINSTANCE hInstance = GetModuleHandle(nullptr);
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = wndName;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	RECT wr;
	wr.left = 100;
	wr.right = 1024 + wr.left;
	wr.top = 100;
	wr.bottom = 768 + wr.top;
	AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

	HWND hWnd = CreateWindow(
		wndName, "SoftRender", WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
		nullptr, nullptr, hInstance, nullptr
	);

	ShowWindow(hWnd, SW_SHOWDEFAULT);

	MeshLoader meshLoader;
	meshLoader.Load("resource\\test.obj");

	PrimitiveConstructor p;
	pContructor = &p;
	p.viewport.wh = VectorInt2D(1024, 768);
	p.viewport.nf = Vector2D(0.01f, 1000.0f);
	p.setPixel = DrawPixel;
	p.drawBitmap = DrawBitmap;
	p.VertexShader = MyVertexShader;
	p.PixelShader = MyPixelShader;
	p.SetVertexBuffer(meshLoader.GetVertices());
	p.SetIndexBuffer(meshLoader.GetTriangles());  

	Matrix4x4 mWorld = MatrixIdentity();
	//mWorld = mWorld * MatrixTranslation({ 0, 0, 0 });
	//mWorld = mWorld * MatrixRotationY(0.0f);
	pWorld = &mWorld;
	Matrix4x4 mView = MatrixLookAtLH(
		Vector3D(0, 1, -5),
		Vector3D(0, 1, 0),
		Vector3D(0, 1, 0)
	).Transpose();
	pView = &mView;
	Matrix4x4 mProjection = MatrixPerspectiveFovLH(1.57f, 1024 / (float)768, 0.01f, 1000.0f).Transpose();
	pProject = &mProjection;
	Matrix4x4 mvpMat = mProjection * (mView * mWorld);
	p.matrixs.push_back(mvpMat);
	p.samplers.push_back(&textureSampler);


	MSG msg = {};
	Timer timer;
	g_pTimer = &timer;
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
		}
	}

	return 0;

}