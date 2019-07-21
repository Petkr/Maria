#include "Geometry.hpp"

bool empty(const Vector& v)
{
	return v.x == 0 && v.y == 0;
}

Vector size(const Rectangle& r)
{
	return { r.width, r.height };
}

Vector position(const Rectangle& r)
{
	return { r.left, r.top };
}