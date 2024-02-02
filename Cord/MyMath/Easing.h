#pragma once

#include "Vec2.h"

#include <functional>

float Lerp(float t, float start, float end);
Vec2f Lerp(float t, const Vec2f& startPos, const Vec2f& endPos);

float EasingLerp(std::function<float(float)> easingFunc, float t, float start, float end);
Vec2f EasingLerp(std::function<float(float)> easingFunc, float t, const Vec2f& start, const Vec2f& end);

namespace Easing{
	float easeInSine(float x);
	float easeOutSine(float x);
	float easeInOutSine(float x);

	float easeInCubic(float x);
	float easeOutCubic(float x);

	float easeInQuart(float x);
	float easeOutQuart(float x);
}