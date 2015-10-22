#include "Header.h"

typedef struct{
	double r;
	double i;
}complex;
complex* FFT(short* x, int length_current, int length_total);
complex* REVERSE_FFT(complex* x, int length_current, int length_total);