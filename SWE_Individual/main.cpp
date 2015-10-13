#include "lnumber.h"

void main(void){
	char a[4];
	char b[3];
	a[0] = '1';
	a[1] = '3';
	a[2] = '3';
	a[3] = '2';
	b[0] = '2';
	b[1] = '3';
	b[2] = '4';
	
	
	lnumber A(a, 4), B(b, 3);
	(A + B).out();
	system("Pause");
}