#include "lnumber.h"

void main(void){
	
	char a[4];
	char b[4];
	char c[2];
	a[0] = '1';
	a[1] = '9';
	a[2] = '3';
	a[3] = '2';
	b[0] = '9';
	b[1] = '2';
	b[2] = '3';
	b[3] = '4';
	c[0] = '3';
	c[1] = '2';
	/*
	char a[1];
	char b[1];
	char c[1];
	a[0] = '1';
	b[0] = '2';
	c[0] = '4';
	
	*/
	lnumber A(a, 4, true), B(b, 4, true), C(c, 2, true);
	(A - A - C + B - A).out();
	system("Pause");
}