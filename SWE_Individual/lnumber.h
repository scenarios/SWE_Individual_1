#pragma once
#include "Header.h"
class lnumber
{
public:
	lnumber();
	lnumber(char* input, const int N, bool symbol);
	lnumber(char* input, const int N, const int zero_bit, bool out_symbol);
	lnumber(char* quotient, char* remainder, const int N_q, const int N_r);
	void out();
	~lnumber();
	void operator =(const lnumber &r);
	lnumber operator +(const lnumber &r);
	lnumber operator -(const lnumber &r);
	lnumber operator *(lnumber &r);
	lnumber operator /(lnumber &r);

private:
	char* number_ = NULL;
	int length_ = NULL;
	int zero_bit_ = NULL;
	bool out_symbol_ = NULL;
	short pattern_ = NULL;
	char* input_ = NULL;
	char* quotient = NULL;
	char* remainder = NULL;
	int length_q_ = NULL;
	int length_r_ = NULL;

private:
	void time_10_(){ number_[length_] = '0'; length_++; }
	void time_N_(int N){ length_ += N; }
	void time_1_10_(){ length_--; }
};

