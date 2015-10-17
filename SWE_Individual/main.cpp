#include "lnumber.h"
#pragma comment(lib,"winmm.lib") 
#include<windows.h>
#pragma comment(lib,"winmm.lib") 
void main(void){
	
	char *a = new char[3];
	char *b = new char[8];
	char *c = new char[2];
	/*
	a[0] = '1';
	a[1] = '2';
	a[2] = '3';
	a[3] = '4';
	a[4] = '1';
	a[5] = '0';
	a[6] = '0';
	a[7] = '2';
	b[0] = '9';
	b[1] = '0';
	b[2] = '2';
	b[3] = '4';
	b[4] = '9';
	b[5] = '0';
	b[6] = '2';
	b[7] = '4';
	c[0] = '3';
	c[1] = '2';
	*/
	
	/*
	char a[1];
	char b[1];
	char c[1];
	a[0] = '1';
	b[0] = '2';
	c[0] = '4';
	
	*/
	//char *s = new char[3];
	memset(a, '9', 3);
	memset(b, '7', 8);
	


	/*
	
	lnumber *A = new lnumber(a, 8, true);
	lnumber *B = new lnumber(b, 8, true);
	lnumber *C = new lnumber(a, 2, true);
	*/
	
//	lnumber A(a, 8, true), B(b, 8, true);
//	A = B + A;
	lnumber A(a, 3, true), B(b, 3, true), C(c, 2, true);
	DWORD t1, t2;
	t1 = timeGetTime();
	(A*B).out();
	t2 = timeGetTime();
	cout << endl << (t2 - t1)*1.0 / 1000 << endl;
	
	//A = *A - *C;
	//A->out();
	system("Pause");
}