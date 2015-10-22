#pragma once
#include "Header.h"
#include "FFT.h"

class lnumber
{
public:
	lnumber();
	lnumber(int input, const int suffix_N, bool symbol);
	lnumber(short* input, const int N, const int e_length, bool symbol);
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
	short* number_s_ = NULL;
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
	int e_length_ = NULL;
private:
	void time_10_(){ number_[length_] = '0'; length_++; }
	void time_N_(int N){ length_ += N; }
	void time_1_10_(){ length_--; }
	lnumber mul_V_C(char num_c);
	
private:
	friend complex* FFT(short* x, int length_current, int length_total);
};

