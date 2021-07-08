#pragma once

typedef float Point[3];

class AABB
{
	Point min_;
	Point max_;
public:
	AABB(float min_x, float min_y, float min_z,
		float max_x, float max_y, float max_z) {
		min_[0] = min_x;
		min_[1] = min_y;
		min_[2] = min_z;
		max_[0] = max_x;
		max_[1] = max_y;
		max_[2] = max_z;
	}

	static bool isCollide(const AABB& a, const AABB& b);
};

