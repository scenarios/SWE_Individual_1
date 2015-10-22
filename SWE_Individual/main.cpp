#include "lnumber.h"
#pragma comment(lib,"winmm.lib") 
#include<windows.h>
#pragma comment(lib,"winmm.lib") 
void main(void){
	
	
	short *y = new short[600000];
	short *x = new short[600000];
	int e_l = pow(2, floor(log2(1200000)) + 1);
	
	for (int i = 0; i < 600000; i++){
		x[i] = i % 10;
		y[i] = i % 10;
	}
	
	
	/*
	short* x = new short[8];
	short* y = new short[8];
	x[0] = 8;
	x[1] = 7;
	x[2] = 6;
	x[3] = 0;
	x[4] = 0;
	x[5] = 0;
	x[6] = 0;
	x[7] = 0;
	y[0] = 2;
	y[1] = 3;
	y[2] = 4;
	y[3] = 0;
	y[4] = 0;
	y[5] = 0;
	y[6] = 0;
	y[7] = 0;
	complex* f1;
	complex* f2;
	complex* result;
	int e_length;
	e_length = pow(2, floor(log2(3 + 3)) + 1);
	f1 = FFT(x, 8, 8);
	f2 = FFT(y, 8, 8);

	complex* f = new complex[e_length];
	for (int k = 0; k < e_length; k++){
		f[k].r = f1[k].r * f2[k].r - f1[k].i * f2[k].i;
		f[k].i = f1[k].r * f2[k].i + f1[k].i * f2[k].r;
	}
	for (int i = 0; i < 8; i++)
		cout << f1[i].r << ' ' << f1[i].i << endl;
	result = REVERSE_FFT(f, e_length, e_length);
	for (int i = 0; i < 8; i++)
		cout << result[i].r << ' ' << result[i].i << endl;
	*/
//	a[0] = 8;
//	a[1] = 8;
	//a[2] = 8;
	//a[3] = 4;
	//a[4] = 1;
	//a[5] = 0;
	//a[6] = '0';
	//a[7] = '2';
//	b[0] = 2;
//	b[1] = 0;
//	b[2] = 0;
//	b[3] = 0;
//	b[4] = 0;
//	b[5] = 0;
//	b[6] = 0;
//	b[7] = 0;
//	b[4] = 0;
	
//	b[5] = '0';
//	b[6] = '2';
//	b[7] = '4';
//	c[0] = '3';
//	c[1] = '2';
//	cout << a[0] << a[1] << a[2];
	
	/*
	char a[1];
	char b[1];
	char c[1];
	a[0] = '1';
	b[0] = '2';
	c[0] = '4';
	
	*/
	//char *s = new char[3];
//	memset(a, '1', 60000);
//	memset(b, '1', 120002);
//	memset(b, '6', 2);
//	memset(b, 2, 3);
	/*
	for (int i = 0; i < 60000; i++)
		a[i] = 1;
	for (int i = 0; i < 120001; i++)
		b[i] = 0;
	for (int i = 0; i < 60000; i++)
		b[i] = 1;
*/
//	cout << a[0] << a[1] << a[2];
//	cout << b[0] << b[1];
	
	
	/*
	lnumber *A = new lnumber(a, 8, true);
	lnumber *B = new lnumber(b, 8, true);
	lnumber *C = new lnumber(a, 2, true);
	*/
	
	lnumber A(x, 600000, e_l, true), B(y, 600000, e_l, true), C;

	DWORD t1, t2;
	t1 = timeGetTime();
	A*B;
	t2 = timeGetTime();
	cout << endl << (t2 - t1)*1.0 / 1000 << endl;



/*	lnumber A(a, 60000, true);
	lnumber B(b, 60000, true);
	lnumber C;
	
	DWORD t1, t2;
	t1 = timeGetTime();
	A*B;
	t2 = timeGetTime();
	cout << endl << (t2 - t1)*1.0 / 1000 << endl;
	
	//A = *A - *C;
	//A->out();*/
	system("Pause");
}