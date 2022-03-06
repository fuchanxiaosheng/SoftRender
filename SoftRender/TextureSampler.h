#pragma once

class PixelColor
{
public:
	union
	{
		int x;
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	};
};

class TextureSampler
{

};
