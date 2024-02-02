#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

//=====================================
// x&yをもつ単位
//=====================================
template <typename T>
struct Vec2 final {
	T x;
	T y;

	// コンストラクタ
	Vec2(T xValue, T yValue) : x(xValue), y(yValue) {}
	Vec2(T* x_ptr, T* y_ptr) : x(*x_ptr), y(*y_ptr) {}
	Vec2(const Vec2<T*>& ptr) : x(*(ptr.x)), y(*(ptr.y)) {}
	Vec2() : x(T()), y(T()) {}

	// ベクトルの長さを計算
	T Length()const;
	T Length(const Vec2<T>& another);

	T Dot()const;
	T Dot(const Vec2<T>& another);

	Vec2<T> operator+(const Vec2<T>& other) const {
		return Vec2<T>(x + other.x, y + other.y);
	}
	void operator+=(const Vec2<T>& other) {
		x += other.x;
		y += other.y;
	}

	Vec2<T> operator-(const Vec2<T>& other) const {
		return Vec2<T>(x - other.x, y - other.y);
	}
	Vec2<T> operator-()const;
	void operator-=(const Vec2<T>& other) {
		x -= other.x;
		y -= other.y;
	}

	Vec2<T> operator*(const T& scalar) const {
		return Vec2<T>(x * scalar, y * scalar);
	}
	void operator*=(const T& scalar) {
		x *= scalar;
		y *= scalar;
	}

	Vec2<T> operator/(const T& scalar) const {
		if (scalar != 0) {
			return Vec2<T>(x / scalar, y / scalar);
		} else {
			// ゼロで割る場合の処理を追加
			return Vec2<T>(0.0f, 0.0f);
		}
	}
	void operator/=(const T& scalar) {
		if (scalar != 0) {
			x /= scalar;
			y /= scalar;
		} else {
			// ゼロで割る場合の処理を追加
			x = 0;
			y = 0;
		}
	}

	// 等号演算子のオーバーロード
	bool operator==(const Vec2<T>& other) const {
		return (x == other.x && y == other.y);
	}

	// 不等号演算子のオーバーロード
	bool operator!=(const Vec2<T>& other) const {
		return !(*this == other);
	}

	// Vec2fpからconst Vec2への変換
	operator Vec2<const T>() const {
		return Vec2<const T>(x, y);
	}

	template <typename anotherT>
	operator Vec2<anotherT>() {
		return Vec2<anotherT>(static_cast<anotherT>(x), static_cast<anotherT>(y));
	}
};


using  Vec2f = Vec2<float>;
using  Vec2fp = Vec2<float*>;
using  Vec2d = Vec2<int>;

Vec2f Normalize(const Vec2f& a);

template<typename T>
inline T Vec2<T>::Length() const {
	return static_cast<T>(sqrt(x * x + y * y));
}

template<typename T>
inline T Vec2<T>::Length(const Vec2<T>& another) {
	return sqrtf(this->x * another.x + this->y * another.y);
}

template<typename T>
inline T Vec2<T>::Dot() const {
	return x * x + y * y;
}

template<typename T>
inline T Vec2<T>::Dot(const Vec2<T>& another) {
	return (this->x * another.x) + (this->y * another.y);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator-() const {
	return Vec2<T>(x * static_cast<T>(-1), y * static_cast<T>(-1));
}