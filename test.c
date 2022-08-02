#include "./includes/math.h"
#include "./includes/neuron.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	{
		printf("\nTEST 1\n");
		float a[] = {1.0, 2.0, 3.0};
		float b[] = {3.0, 2.0, 1.0};

		float c[] = {1.0, 4.0, 3.0};
		float d[] = {3.0, 2.0, 1.0};

		float x[2];
		Neuron n[2];

		NR_set_inputs(n, a, 3);
		NR_set_weights(n, b);
		NR_set_bias(n, 0);
		NR_set_output(n, x);

		NR_set_inputs(n+1, c, 3);
		NR_set_weights(n+1, d);
		NR_set_bias(n+1, 0);
		NR_set_output(n+1, x+1);

		NR_compute(n);
		NR_compute(n+1);

		printf("x[1]: %f\nx[2]: %f\n", *(n[0].output), *(n[1].output));
	}

	{
		printf("\nTEST 2\n");
		float m1[] = {1, 1, 1, 1, 1, 1};
		float m3[] = {3, 3, 3, 3, 3, 3};
		int rm1 = 3;
		int cm1 = 2;

		float m2[] = {2, 2, 2, 2};
		int rm2 = 2;
		int cm2 = 2;

		printf("multiplying:\nA =\n");
		MATH_matrix_print(m1, rm1, cm1);
		printf("\nB =\n");
		MATH_matrix_print(m2, rm2, cm2);
		printf("\n(A x B) =\n");

		int rres, cres;
		float* res = MATH_matrix_make_multiply(m1, rm1, cm1, m2, rm2, cm2, &rres, &cres);
		MATH_matrix_print(res, rres, cres);

		printf("\nC =\n");
		MATH_matrix_print(m3, rm1, cm1);
		MATH_matrix_add(m3, res, rm1, cm1, res);
		printf("\n(A x B) + C =\n");
		MATH_matrix_print(res, rres, cres);
		free(res);
	}
	return 0;
}
