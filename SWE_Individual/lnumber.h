#pragma once
#include "Header.h"
class lnumber
{
public:
	lnumber(char* input);
	lnumber(char* input, const int N);
	void out(){ printf("%c %c %c %c %c", number[0], number[1], number[2], number[3], number[4]); }
	~lnumber();
	lnumber operator +(const lnumber &r);

private:
	char* number;
	int length;
};

