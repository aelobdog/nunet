#include "./includes/math.h"
#include "./includes/neuron.h"
#include <stdio.h>

int main() {
	float a[] = {1.0, 2.0, 3.0};
	float b[] = {3.0, 2.0, 1.0};

	float c[] = {1.0, 4.0, 3.0};
	float d[] = {3.0, 2.0, 1.0};

	float x[2];
	Neuron n[2];

	NR_set_inputs(n, a, 3);
	NR_set_weights(n, b);
	NR_set_output(n, x);

	NR_set_inputs(n+1, c, 3);
	NR_set_weights(n+1, d);
	NR_set_output(n+1, x+1);

	NR_compute(n);
	NR_compute(n+1);

	printf("x[1]: %f\nx[2]: %f\n", *(n[0].output), *(n[1].output));

	return 0;
}
