#ifndef NEURON_H
#define NEURON_H

typedef struct Neuron Neuron;

struct Neuron {
	const float *inputs;
	const float *weights;
	int num_inputs;
	float *output;
	float bias;
};

void NR_set_inputs(Neuron* self, float* inputs, int num_inputs);
void NR_set_weights(Neuron* self, float* weights);
void NR_set_bias(Neuron* self, float bias);
void NR_set_output(Neuron* self, float* output);
void NR_compute(Neuron* self);

#endif
