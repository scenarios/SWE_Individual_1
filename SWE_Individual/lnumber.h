#pragma once
#include "Header.h"
class lnumber
{
public:
	lnumber(char* input, bool symbol);
	lnumber(char* input, const int N, bool symbol);
	lnumber(char* input, const int N, const int zero_bit, bool out_symbol);
	void out(){ { printf("%c%s",  out_symbol_ == true?' ':'-', number_ ); } }
	~lnumber();
	lnumber operator +(const lnumber &r);
	lnumber operator -(const lnumber &r);

private:
	char* number_;
	int length_;
	int zero_bit_;
	bool out_symbol_;
	short pattern_;
};

