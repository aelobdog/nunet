#ifndef CMATH_H
#define CMATH_H

float MATH_dot(const float* a, const float* b, int len);

float* MATH_matrix_make_multiply(float* a, int ra, int ca, float* b, int rb, int cb, int* rres, int* cres);
float* MATH_matrix_make_add(float* a, float* b, int r, int c);

// unsafe : passing in a 'res' with inadequate size will result in segfaults
// returns 0 on success, 1 on failure
int MATH_matrix_multiply(float* a, int ra, int ca, float* b, int rb, int cb, float* res);
void MATH_matrix_add(float* a, float* b, int r, int c, float* res);

void MATH_matrix_print(float* a, int ra, int ca);
float* MATH_matrix_alloc(int r, int c);

#endif
