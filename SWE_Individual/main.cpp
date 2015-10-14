#include "lnumber.h"

void main(void){
	char a[4];
	char b[4];
	a[0] = '1';
	a[1] = '9';
	a[2] = '3';
	a[3] = '2';
	b[0] = '9';
	b[1] = '2';
	b[2] = '3';
	b[3] = '4';
	
	lnumber A(a, 4), B(b, 4);
	(A + B).out();
	system("Pause");
}