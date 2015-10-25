#include "Header.h"

typedef struct{
	double r;
	double i;
}complex;
complex* FFT(short* x, int length_current, int length_total);
complex* FFT(short* x, int length_current, int length_total, short* x1);
complex* REVERSE_FFT(complex* X, int length_current, int length_total);
complex* REVERSE_FFT(complex* X, int length_current, int length_total, complex* X1);
