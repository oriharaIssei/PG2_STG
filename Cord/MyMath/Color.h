#pragma once

struct Color final{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	unsigned int alpha;

	void operator=(unsigned int color);
	unsigned int Int() const;
};

