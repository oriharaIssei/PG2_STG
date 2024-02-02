#include "Easing.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define float_cast static_cast<float>

float Lerp(float t, float start, float end) {
	return (1.0f - t) * start + t * end;
}

Vec2f Lerp(float t, const Vec2f& startPos, const Vec2f& endPos) {
	Vec2f lerp;
	lerp.x = Lerp(t, startPos.x, endPos.x);
	lerp.y = Lerp(t, startPos.y, endPos.y);

	return lerp;
}

float EasingLerp(std::function<float(float)> easingFunc, float t, float start, float end) {
	return Lerp(easingFunc(t), start, end);
}

Vec2f EasingLerp(std::function<float(float)> easingFunc, float t, const Vec2f& start, const Vec2f& end) {
	return Lerp(easingFunc(t), start, end);
}

float Easing::easeInSine(float x) {
	return 1.0f - cosf((x * float_cast(M_PI)) / 2.0f);
}

float Easing::easeOutSine(float x) {
	return sinf((x * float_cast(M_PI)) / 2);
}

float Easing::easeInOutSine(float x) {
	return -(cosf(float_cast(M_PI) * x) - 1) / 2;
}

float Easing::easeInCubic(float x) {
	return x * x * x;
}

float Easing::easeOutCubic(float x) {
	return 1.0f - powf(1 - x, 3);
}

float Easing::easeInQuart(float x) {
	return x * x * x * x;
}

float Easing::easeOutQuart(float x) {
	return 1 - powf(1.0f - x, 4);
}