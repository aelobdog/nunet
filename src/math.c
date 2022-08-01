#include "../includes/math.h"

// @optimize
float MATH_dot(const float* a, const float* b, int len) {
	float output = 0;
	len--;
	for (; len>=0; len--) output = output + (a[len] * b[len]);
	return output;
}
