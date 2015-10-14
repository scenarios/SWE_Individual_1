#include "lnumber.h"

int max(int a, int b){ return a > b ? a : b; }
lnumber::lnumber(char* input)
{
	number = input;
	zero_bit = 0;
}
lnumber::lnumber(char* input, const int N)
{
	number = input;
	length = N;
	zero_bit = 0;
}

lnumber lnumber::operator+(const lnumber &r)
{
	char *output = new char[max(length, r.length) + 2];
	output[max(length, r.length) + 1] = '\0';
	int temp = 0;
	int i = max(length, r.length) - 1;
	int l = length - 1;
	int s = r.length - 1;
	
	for (; i >= -1; i--){
		if (l >= 0 && s >= 0){
			output[i + 1] = int(number[l] - '0' + r.number[s] - '0' + temp) % 10 + '0';
			temp = int(number[l] - '0' + r.number[s] - '0' + temp) / 10;
			l--;
			s--;
		}
		else if (l >= 0 && s < 0){
			output[i + 1] = int(number[l] - '0' + 0 + temp) % 10 + '0';
			temp = int(number[l] - '0' + 0 + temp) / 10;
			l--;
			s--;
		}
		else if (l < 0 && s >= 0){
			output[i + 1] = int(0 + r.number[s] - '0' + temp) % 10 + '0';
			temp = int(0 + r.number[s] - '0' + temp) / 10;
			l--;
			s--;
		}
		else if(l < 0 && s < 0){
			output[i + 1] = temp + '0';
			if (temp == 0)
				zero_bit += 1;
		}
	}
	return lnumber(output);
	
}

lnumber::~lnumber()
{
}
