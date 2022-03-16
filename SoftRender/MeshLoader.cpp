#include "MeshLoader.h"

#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

bool MeshLoader::Load(const char* filename)
{
	std::ifstream filestream;
	filestream.open(filename);
	std::map<std::string, int> verticesMap;
	

	if (!filestream.is_open())
	{
		return false;
	}
	std::string line;
	while (getline(filestream, line))
	{
		std::istringstream linestream(line);
		std::string keyword;
		linestream >> keyword;
		if (keyword.compare("v") == 0)
		{
			Vector3D position;
			linestream >> position.x;
			linestream >> position.y;
			linestream >> position.z;
			positions.push_back(position);
		}
		else if (keyword.compare("vt") == 0)
		{
			Vector2D texcoord;
			linestream >> texcoord.x;
			linestream >> texcoord.y;
			texcoords.push_back(texcoord);
		}
		else if (keyword.compare("vn") == 0)
		{
			Vector3D normal;
			linestream >> normal.x;
			linestream >> normal.y;
			linestream >> normal.z;
			normals.push_back(normal);
		}
		else if (keyword.compare("f") == 0)
		{
			Triangle triangle;
			int index = 0;
			//fÎ»ÓÚºó
			for (std::string para; linestream >> para && index < 3; index++)
			{
				if (verticesMap.find(para) == verticesMap.end())
				{
					Vertex vertex;
					std::string tmp = para;
					verticesMap.insert({ para, 0 });
					replace(tmp.begin(), tmp.end(), '/', ' ');
					std::istringstream paraStream(tmp);
					int i;
					paraStream >> i;
					vertex.position = positions[(i - 1)];
					paraStream >> i;
					vertex.texcoord = texcoords[(i - 1)];
					paraStream >> i;
					vertex.normal = normals[(i - 1)];
					verticesMap[para] = vertices.size();
					triangle.VertexIndex[index] = vertices.size();
					vertices.push_back(vertex);
				}
				else
				{
					triangle.VertexIndex[index] = verticesMap[para];
				}
			}
			triangles.push_back(triangle);
		}
	}

	return true;
}

std::vector<Vertex>& MeshLoader::GetVertices()
{
	return vertices;
}
std::vector<Triangle>& MeshLoader::GetTriangles()
{
	return triangles;
}