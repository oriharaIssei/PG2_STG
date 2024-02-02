#pragma once
#include "Vec2.h"

void DrawQuad(
	const Vec2f& ltPos,
	const Vec2f& rtPos,
	const Vec2f& lbPos,
	const Vec2f& rbPos,
	const Vec2f& srcPos, 
	const Vec2f& srcSize,
	int gh,
	unsigned int color
);

void DrawQuad(
	const Vec2f& centerPos,
	const Vec2f& size,
	const Vec2f& srcPos,
	const Vec2f& srcSize,
	int gh,
	unsigned int color
);

void DrawSquare(
	const Vec2f& pos,
	const float& size,
	unsigned int color
);

void DrawCircle(
	const Vec2f& pos, 
	const float& radius,
	unsigned int color
);

void DrawBox(
	const Vec2f& ltPos,
	const Vec2f& size,
	unsigned int color
);