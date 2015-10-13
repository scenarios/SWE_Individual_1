#include "lnumber.h"

int max(int a, int b){ return a > b ? a : b; }
lnumber::lnumber(char* input)
{
	number = input;
}
lnumber::lnumber(char* input, const int N)
{
	number = input;
	length = N;
}

lnumber lnumber::operator+(const lnumber &r)
{
	char *output = new char[max(length, r.length) + 1];
	int temp = 0;
	int i = max(length, r.length) - 1;
	int l = length - 1;
	int s = r.length - 1;
	
	for (; i >= 0; i--){
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
		else{
			output[i + 1] = temp;
		}
	}
	return lnumber(output);
	
}

lnumber::~lnumber()
{
}
