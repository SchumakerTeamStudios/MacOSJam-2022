// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Vec2d.hpp"
#include <math.h>

Vec2d::Vec2d(): x(0.0f), y(0.0f) {}
Vec2d::Vec2d(float x, float y): x(x), y(y) {}

void Vec2d::Add(const Vec2d& v) {
	x += v.x;
	y += v.y;
}

void Vec2d::Sub(const Vec2d& v) {
	x -= v.x;
	y -= v.y;
}

void Vec2d::Scale(const float n) {
	x *= n;
	y *= n;
}

Vec2d Vec2d::Rotate(const float angle) const {
	Vec2d result;
	result.x = x * cos(angle) - y * sin(angle);
	result.y = x * sin(angle) + y * cos(angle);
	return result;
}

float Vec2d::Magnitude() const {
	return sqrtf(x * x + y * y);
}

float Vec2d::MagnitudeSquared() const {
	return (x * x + y * y);
}

Vec2d& Vec2d::Normalize() {
	float length = Magnitude();
	if (length != 0.0f) {
		x /= length;
		y /= length;
	}
    return *this;
}

Vec2d Vec2d::UnitVector() const {
	Vec2d result = Vec2d(0, 0);
	float length = Magnitude();
	if (length != 0.0) {
		result.x = x / length;
		result.y = y / length;
	}
    return result;
}

Vec2d Vec2d::Normal() const {
	return Vec2d(y, -x).Normalize();
}

float Vec2d::Dot(const Vec2d& v) const {
    return (x * v.x) + (y * v.y);
}

float Vec2d::Cross(const Vec2d& v) const {
	return (x * v.y) - (y * v.x);
}

Vec2d& Vec2d::operator = (const Vec2d& v) {
	x = v.x;
	y = v.y;
	return *this;
}

bool Vec2d::operator == (const Vec2d& v) const {
	return x == v.x && y == v.y;
}

bool Vec2d::operator != (const Vec2d& v) const {
	return !(*this == v);
}

Vec2d Vec2d::operator + (const Vec2d& v) const {
	Vec2d result;
	result.x = x + v.x;
	result.y = y + v.y;
	return result;
}

Vec2d Vec2d::operator - (const Vec2d& v) const {
	Vec2d result;
	result.x = x - v.x;
	result.y = y - v.y;
	return result;
}

Vec2d Vec2d::operator * (const float n) const {
	Vec2d result;
	result.x = x * n;
	result.y = y * n;
	return result;
}

Vec2d Vec2d::operator / (const float n) const {
	Vec2d result;
	result.x = x / n;
	result.y = y / n;
	return result;
}

Vec2d& Vec2d::operator += (const Vec2d& v) {
	x += v.x;
	y += v.y;
	return *this;
}

Vec2d& Vec2d::operator -= (const Vec2d& v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

Vec2d& Vec2d::operator *= (const float n) {
	x *= n;
	y *= n;
    return *this;
}

Vec2d& Vec2d::operator /= (const float n) {
	x /= n;
	y /= n;
    return *this;
}

Vec2d Vec2d::operator - () {
	Vec2d result;
	result.x = x * -1;
	result.y = y * -1;
	return result;
}
