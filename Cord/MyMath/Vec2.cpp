#include "Vec2.h"

Vec2f Normalize(const Vec2f& a) {
	float length = a.Length();
	if (length == 0) {
		return a;
	}
	Vec2f result = a;
	return (result / length);
}