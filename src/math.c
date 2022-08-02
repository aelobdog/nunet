#include "../includes/math.h"
#include <stdlib.h>
#include <stdio.h>

// @optimize
float MATH_dot(const float* a, const float* b, int len) {
	float output = 0;
	len--;
	for (; len>=0; len--) output = output + (a[len] * b[len]);
	return output;
}

// print a flat matrix in grid form
void MATH_matrix_print(float* a, int ra, int ca) {
	for (int i=0; i<ra; i++) {
		for (int j=0; j < ca; j++) {
			printf("%f ", a[(i*ca) + j]);
		}
		printf("\n");
	}
}

// simple matrix multiplication
float* MATH_matrix_make_multiply(float* a, int ra, int ca, float* b, int rb, int cb, int* rres, int* cres) {
	if (ca != rb) return (float*)0;
	float* res = (float*) malloc(sizeof(float) * ra * cb);
	
	for (int i=0; i<ra; i++) {
		for (int j=0; j < cb; j++) {
			res[(i*cb) + j] = 0;

			for (int k=0; k<ca; k++) {
				res[(i*cb) + j] += a[(i*ca) + k] * b[(k*cb) + j];
			}
		}
	}

	*rres = ra;
	*cres = cb;
	return res;
}

// simple matrix multiplication
int MATH_matrix_multiply(float* a, int ra, int ca, float* b, int rb, int cb, float* res) {
	if (ca != rb) return 1;
	
	for (int i=0; i<ra; i++) {
		for (int j=0; j < cb; j++) {
			res[(i*cb) + j] = 0;

			for (int k=0; k<ca; k++) {
				res[(i*cb) + j] += a[(i*ca) + k] * b[(k*cb) + j];
			}
		}
	}
	return 0;
}

float* MATH_matrix_make_add(float* a, float* b, int r, int c) {
	float* res = (float*) malloc(sizeof(float) * r * c);
	for (int i=0; i<r*c; i++) res[i] = a[i] + b[i];
	return res;
}

void MATH_matrix_add(float* a, float* b, int r, int c, float* res) {
	for (int i=0; i<r*c; i++) res[i] = a[i] + b[i];
}

float* MATH_matrix_alloc(int r, int c) {
	return (float*) malloc(sizeof(float) * r * c);
}
