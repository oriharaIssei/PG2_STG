#include "DrawFunction.h"

#include "Novice.h"

void DrawQuad(const Vec2f& ltPos,
	const Vec2f& rtPos,
	const Vec2f& lbPos,
	const Vec2f& rbPos,
	const Vec2f& srcPos, const Vec2f& srcSize,
	int gh, unsigned int color) {
	Novice::DrawQuad(static_cast<int>(ltPos.x), static_cast<int>(ltPos.y),
		static_cast<int>(rtPos.x), static_cast<int>(rtPos.y),
		static_cast<int>(lbPos.x), static_cast<int>(lbPos.y),
		static_cast<int>(rbPos.x), static_cast<int>(rbPos.y),
		static_cast<int>(srcPos.x), static_cast<int>(srcPos.y),
		static_cast<int>(srcSize.x), static_cast<int>(srcSize.y),
		gh, color
	);
}

void DrawQuad(const Vec2f& centerPos, const Vec2f& size, const Vec2f& srcPos, const Vec2f& srcSize, int gh, unsigned int color) {
	DrawQuad(
		centerPos - (size / 2.0f),//LT
		centerPos + Vec2f(size.x / 2.0f, -size.y / 2.0f),//RT
		centerPos + Vec2f(-size.x / 2.0f, size.y / 2.0f),//LB
		centerPos + (size / 2.0f),//RB
		srcPos,
		srcSize,
		gh,
		color
	);
}

void DrawSquare(const Vec2f& pos, const float& size, unsigned int color) {
	Novice::DrawBox(
		static_cast<int>(pos.x),
		static_cast<int>(pos.y),
		static_cast<int>(size), static_cast<int>(size),
		0.0f,
		color,
		kFillModeSolid
	);
}

void DrawCircle(const Vec2f& pos, const float& radius, unsigned int color) {
	Novice::DrawEllipse(
		static_cast<int>(pos.x),
		static_cast<int>(pos.y),
		static_cast<int>(radius), static_cast<int>(radius),
		0.0f,
		color,
		kFillModeSolid
	);
}

void DrawBox(const Vec2f& ltPos, const Vec2f& size, unsigned int color) {
	Novice::DrawBox(
		static_cast<int>(ltPos.x),
		static_cast<int>(ltPos.y),
		static_cast<int>(size.x),
		static_cast<int>(size.y),
		0.0f,
		color,
		kFillModeSolid
	);
}