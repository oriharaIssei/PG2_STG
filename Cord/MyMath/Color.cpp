#include "Color.h"

void Color::operator=(unsigned int color) {
	red = (color >> 24) & 0xFF;
	green = (color >> 16) & 0xFF;
	blue = (color >> 8) & 0xFF;
	alpha = color & 0xFF;
}

unsigned int Color::Int() const {
	return(red << 24) + (green << 16) + (blue << 8) + alpha;
}
