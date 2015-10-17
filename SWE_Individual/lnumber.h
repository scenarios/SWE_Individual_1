#pragma once
#include "Header.h"
class lnumber
{
public:
	lnumber();
	lnumber(char* input, const int N, bool symbol);
	lnumber(char* input, const int N, const int zero_bit, bool out_symbol);
	void out(){ { printf("%c%s",  out_symbol_ == true?' ':'-', number_); } }
	~lnumber();
	lnumber operator +(const lnumber &r);
	lnumber operator -(const lnumber &r);
	lnumber operator *(lnumber &r);

private:
	char* number_;
	int length_;
	int zero_bit_;
	bool out_symbol_;
	short pattern_;
	char* input_;

private:
	void time_10_(){ number_[length_] = '0'; length_++; }
};

