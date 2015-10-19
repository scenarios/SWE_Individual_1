#include "lnumber.h"
#pragma comment(lib,"winmm.lib") 
#include<windows.h>
#pragma comment(lib,"winmm.lib") 
void main(void){
	
	char *a = new char[7];
	char *b = new char[7];
	char *c = new char[2];
	
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
	memset(a, '3', 7);
	memset(b, '0', 7);
	memset(b, '2', 2);
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
	
//	lnumber A(a, 8, true), B(b, 8, true);
//	A = B + A;
	lnumber A(a, 7, true);
	lnumber B(b, 2, true);
	lnumber C;
	
	DWORD t1, t2;
	t1 = timeGetTime();
	(A/B).out();
	t2 = timeGetTime();
	cout << endl << (t2 - t1)*1.0 / 1000 << endl;
	
	//A = *A - *C;
	//A->out();
	system("Pause");
}