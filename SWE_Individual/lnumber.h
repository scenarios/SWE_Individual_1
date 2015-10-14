#pragma once
#include "Header.h"
class lnumber
{
public:
	lnumber(char* input);
	lnumber(char* input, const int N);
	void out(){ { printf("%s", number + zero_bit); } }
	~lnumber();
	lnumber operator +(const lnumber &r);

private:
	char* number;
	int length;
	int zero_bit;
};

