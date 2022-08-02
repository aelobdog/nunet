#include "../includes/neuron.h"
#include "../includes/math.h"

void NR_set_inputs(Neuron* self, float* inputs, int num_inputs) {
	self->inputs = inputs;
	self->num_inputs = num_inputs;
}

void NR_set_weights(Neuron* self, float* weights) {
	self->weights = weights;
}

void NR_set_bias(Neuron* self, float bias) {
	self->bias = bias;
}

void NR_set_output(Neuron* self, float* output) {
	self->output = output;
}

void NR_compute(Neuron* self) {
	*(self->output) = MATH_dot(
			self->inputs, 
			self->weights, 
			self->num_inputs);
	*(self->output) += self->bias;
}

