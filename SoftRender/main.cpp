#include <Windows.h>
#include <iostream>
#include <string>

#include "MeshLoader.h"
#include "TextureSampler.h"
#include "Timer.h"

TextureSampler* pTextureSampler;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc, hdcMem;
	HBITMAP hBitmap;
	int i;
	switch (msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		hdcMem = CreateCompatibleDC(hdc);
		hBitmap = CreateBitmap(pTextureSampler->width, pTextureSampler->height, 1, 32, pTextureSampler->rawData);
		i = GetLastError();
		SelectObject(hdcMem, hBitmap);
		BitBlt(hdc, 0, 0, pTextureSampler->width, pTextureSampler->height, hdcMem, 0, 0, SRCCOPY);
		DeleteDC(hdcMem);

		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int main()
{

	MeshLoader meshLoader;
	//meshLoader.Load("D://Files//CodeProject//SoftRender//SoftRender//resource//test.obj");
	meshLoader.Load("C://Users//21166//Desktop//Work//CodeProjects//SoftRender//SoftRender//resource//test.obj");

	TextureSampler textureSampler;
	//textureSampler.LoadDDSTexture(L"D://Files//CodeProject//SoftRender//SoftRender//resource//sample_1920¡Á1280.dds");
	textureSampler.LoadDDSTexture(L"C://Users//21166//Desktop//Work//CodeProjects//SoftRender//SoftRender//resource//sample_1920¡Á1280.dds");
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
	wr.right = 1920 + wr.left;
	wr.top = 100;
	wr.bottom = 1280 + wr.top;
	AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

	HWND hWnd = CreateWindow(
		wndName, "SoftRender", WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
		nullptr, nullptr, hInstance, nullptr
	);

	ShowWindow(hWnd, SW_SHOWDEFAULT);

	MSG msg = {};
	Timer timer;
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SetWindowText(hWnd, std::to_string(1.0f / timer.TimeTick()).c_str());
		}
		
	}

	return 0;

}