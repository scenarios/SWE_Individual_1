#include "lnumber.h"

int max(int a, int b){ return a > b ? a : b; }
lnumber::lnumber()
{
	input_ = new char[1];
	input_[0] = '0';
	number_ = input_;
	number_[0] = 0;
	zero_bit_ = 0;
	out_symbol_ = true;
	pattern_ = 0;

}

lnumber::lnumber(int input, const int suffix_N, bool symbol)
{
	if (input_ != NULL)
		delete[] input_;
	int i = 0;
	int temp;
	temp = input / 10;
	while (temp != 0){
		i++;
		temp = temp / 10;
	}
	input_ = new char[i + 1 + suffix_N];
	memset(input_, '0', i + 1 + suffix_N);

	for (int j = i; j >= 0; j--){
		input_[j] = input % 10 + '0';
		input /= 10;
	}

	number_ = input_;
	length_ = i + 1 + suffix_N;
	zero_bit_ = 0;
	out_symbol_ = symbol;
	pattern_ = 0;
}

lnumber::lnumber(short* input, const int N, const int e_length, bool symbol)
{
	e_length_ = e_length;
	number_s_ = new short[e_length_];
//	memset(number_s_, 0, e_length_ * sizeof(number_s_));
	for (int i = e_length_ - 1; i > N - 1; i--)
		number_s_[i] = 0;
	for (int i = N - 1; i >= 0; i--)
		number_s_[i] = input[i];
	delete[] input;
	length_ = N;
	zero_bit_ = 0;
	out_symbol_ = symbol;
	pattern_ = 0;
}

lnumber::lnumber(char* input, const int N, bool symbol)
{
	if (input_ != NULL)
		delete[] input_;
	input_ = input;
	number_ = input_;
	length_ = N;
	zero_bit_ = 0;
	out_symbol_ = symbol;
	pattern_ = 0;
}

lnumber::lnumber(char* input, const int N, const int zero_bit, bool out_symbol)
{
	if (input_ != NULL)
		delete[] input_;
	input_ = input;
	length_ = N - zero_bit;
	if (length_ != 0)
		number_ = input_ + zero_bit;
	else
		number_ = input_ + zero_bit - 1;
	zero_bit_ = 0;
	out_symbol_ = out_symbol;
	pattern_ = 0;
}

lnumber::lnumber(char* input_q, char* input_r, const int N_q, const int N_r)
{
	quotient = input_q;
	remainder = input_r;
	length_q_ = N_q;
	length_r_ = N_r; 
	zero_bit_ = 0;
	out_symbol_ = true;
	pattern_ = 0;
}

lnumber lnumber::mul_V_C(char num_c)
{
	short num = num_c - '0';
	char* mul_result = new char[length_ + 1];
	short temp = 0;
	short carry = 0;;
	for (int i = length_ - 1; i >= 0; i--){
		temp = (number_[i] - '0') * num + carry;
		mul_result[i+1] = temp % 10 + '0';
		carry = temp / 10;
	}
	mul_result[0] = carry + '0';
	if (mul_result[0] == '0') return lnumber(mul_result, length_, 1, true);
	else return lnumber(mul_result, length_ + 1, 0, true);
}

void lnumber::operator=(const lnumber &r)
{
	if (input_ != NULL)
		delete[] input_;
	number_ = r.number_;
	length_ = r.length_;
	zero_bit_ = r.zero_bit_;
	out_symbol_ = r.out_symbol_;
	pattern_ = r.pattern_;
	input_ = r.input_;
	quotient = r.quotient;
	remainder = r.remainder;
	length_q_ = r.length_q_;
	length_r_ = r.length_r_;
}

lnumber lnumber::operator+(const lnumber &r)
{
	int zero_bit = zero_bit_;
	if (pattern_ == N_N){
		char *output = new char[max(length_, r.length_) + 2];
		output[max(length_, r.length_) + 1] = '\0';
		int carry = 0;
		int i = max(length_, r.length_) - 1;
		int l = length_ - 1;
		int s = r.length_ - 1;

		for (; i >= -1; i--){
			if (l >= 0 && s >= 0){
				int te = int(number_[l] - '0' + r.number_[s] - '0' + carry);
				output[i + 1] = te % 10 + '0';
				carry = te / 10 ;
				l--;
				s--;
			}
			else if (l >= 0 && s < 0){
				int te = int(number_[l] - '0' + carry);
				output[i + 1] = te % 10 + '0';
				carry = te / 10 ;
				l--;
				s--;
			}
			else if (l < 0 && s >= 0){
				int te = int(r.number_[s] - '0' + carry);
				output[i + 1] = te % 10 + '0';
				carry = te / 10 ;
				l--;
				s--;
			}
			else if (l < 0 && s < 0){
				output[i + 1] = carry + '0';
				if (carry == 0)
					zero_bit += 1;
			}
		}
	//	delete[] input_;
		//delete[] r.input_;
		return lnumber(output, max(length_, r.length_) + 1, zero_bit, false);

	}
			
	else if (pattern_ == P_N){
		bool flag_left_large = true;
		if (length_ > r.length_)
			flag_left_large = true;
		else if (length_ < r.length_)
			flag_left_large = false;
		else{
			for (int i = 0; i < length_; i++){
				if ((number_[i] - '0') >(r.number_[i] - '0')){
					flag_left_large = true;
					break;
				}
				else if ((number_[i] - '0') < (r.number_[i] - '0')){
					flag_left_large = false;
					break;
				}
				else{}
			}
		}

		char *output = new char[max(length_, r.length_) + 1];
		output[max(length_, r.length_)] = '\0';
		int carry = 0;
		int i = max(length_, r.length_) - 1;
		int l = length_ - 1;
		int s = r.length_ - 1;
		int temp;




		switch (flag_left_large)
		{
		case true:
			for (; i >= 0; i--){
				if (l >= 0 && s >= 0){
					temp = int(number_[l] - '0' - (r.number_[s] - '0')+ carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit += 1;
						else
							zero_bit = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else if (l >= 0 && s < 0){
					temp = int(number_[l] - '0' + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit += 1;
						else
							zero_bit = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
		//	delete[] input_;
		//	delete[] r.input_;
			return lnumber(output, max(length_, r.length_), zero_bit, true);
			break;

		case false:
			for (; i >= 0; i--){
				if (l >= 0 && s >= 0){
					temp = int(r.number_[s] - '0' - (number_[l] - '0') + carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit += 1;
						else
							zero_bit = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else if (l < 0 && s >= 0){
					temp = int(r.number_[s] - '0' + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit += 1;
						else
							zero_bit = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
	//		delete[] input_;
	//		delete[] r.input_;
			return lnumber(output, max(length_, r.length_), zero_bit, false);
			break;
		}


	}
	else if(pattern_ == N_P){
		bool flag_left_large = true;
		if (length_ > r.length_)
			flag_left_large = true;
		else if (length_ < r.length_)
			flag_left_large = false;
		else{
			for (int i = 0; i < length_; i++){
				if ((number_[i] - '0') >(r.number_[i] -'0')){
					flag_left_large = true;
					break;
				}
				else if ((number_[i] - '0') < (r.number_[i] - '0')){
					flag_left_large = false;
					break;
				}
				else{}
			}
		}

		char *output = new char[max(length_, r.length_) + 1];
		output[max(length_, r.length_)] = '\0';
		int carry = 0;
		int i = max(length_, r.length_) - 1;
		int l = length_ - 1;
		int s = r.length_ - 1;
		int temp;




		switch (flag_left_large)
		{
		case true:
			for (; i >= 0; i--){
				if (l >= 0 && s >= 0){
					temp = int(number_[l] - '0' - (r.number_[s] -'0') + carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit += 1;
						else
							zero_bit = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else if (l >= 0 && s < 0){
					temp = int(number_[l] - '0' + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit += 1;
						else
							zero_bit = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
	//		delete[] input_;
	//		delete[] r.input_;
			return lnumber(output, max(length_, r.length_), zero_bit, false);
			break;

		case false:
			for (; i >= 0; i--){
				if (l >= 0 && s >= 0){
					temp = int(r.number_[s] - '0' - (number_[l] - '0') + carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit += 1;
						else
							zero_bit = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else if (l < 0 && s >= 0){
					temp = int(r.number_[s] - '0' + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit += 1;
						else
							zero_bit = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
	//		delete[] input_;
	//		delete[] r.input_;
			return lnumber(output, max(length_, r.length_), zero_bit, true);
			break;
		}
	}
	else{
		char *output = new char[max(length_, r.length_) + 2];
		output[max(length_, r.length_) + 1] = '\0';
		int carry = 0;
		int i = max(length_, r.length_) - 1;
		int l = length_ - 1;
		int s = r.length_ - 1;

		for (; i >= -1; i--){
			if (l >= 0 && s >= 0){
				int te = int(number_[l] - '0' + r.number_[s] - '0' + carry);
				output[i + 1] = te % 10 + '0';
				carry = te / 10;
				l--;
				s--;
			}
			else if (l >= 0 && s < 0){
				int te = int(number_[l] - '0' + carry);
				output[i + 1] = te % 10 + '0';
				carry = te / 10 ;
				l--;
				s--;
			}
			else if (l < 0 && s >= 0){
				int te = int(r.number_[s] - '0' + carry);
				output[i + 1] = te % 10 + '0';
				carry = te / 10 ;
				if (carry == 0 && (te % 10) == 0)
					zero_bit += 1;
				l--;
				s--;
			}
			else if (l < 0 && s < 0){
				output[i + 1] = carry + '0';
				if (carry == 0)
					zero_bit += 1;
			}
		}
//		delete[] input_;
//		delete[] r.input_;
		return lnumber(output, max(length_, r.length_) + 1, zero_bit, true);

	}
}

lnumber lnumber::operator-(const lnumber &r){
	
	if (out_symbol_ == true && r.out_symbol_ == true){
		pattern_ = P_N;
		return operator+(r);
	}
	else if (out_symbol_ == false && r.out_symbol_ == true){
		pattern_ = N_N;
		return operator+(r);
	}
	else if (out_symbol_ == true && r.out_symbol_ == false){
		pattern_ = P_P;
		return operator+(r);
	}
	else {
		pattern_ = N_P;
		return operator+(r);
	}
	
}
/*
lnumber lnumber::operator*(const lnumber &r){
	if (length_ >= r.length_){
		lnumber ac;
		for (int i = r.length_ - 1; i >= 0; i--){
			for (int j = length_ - 1; j >= 0; j--){

				char temp_char = (r.number_[i] - '0') * (number_[j] - '0');
				if (temp_char / 10 != 0){
					int length = (r.length_ - 1 - i) + (length_ - 1 - j) + 2;
					char *temp = new char[length];
					memset(temp, '0', length);
					temp[0] = temp_char / 10 + '0';
					temp[1] = temp_char % 10 + '0';
					lnumber mulresult(temp, length, true);
					ac = ac + mulresult;
				}
				else{
					int length = (r.length_ - 1 - i) + (length_ - 1 - j) + 1;
					char *temp = new char[length];
					memset(temp, '0', length);
					temp[0] = temp_char + '0';
					lnumber mulresult(temp, length, true);
					ac = ac + mulresult;
				}

			}
		}
		return ac;
	}
	else{
		lnumber ac;
		for (int j = length_ - 1; j >= 0; j--){
			for (int i = r.length_ - 1; i >= 0; i--){

				char temp_char = (r.number_[i] - '0') * (number_[j] - '0');
				if (temp_char / 10 != 0){
					int length = (r.length_ - 1 - i) + (length_ - 1 - j) + 2;
					char *temp = new char[length];
					memset(temp, '0', length);
					temp[0] = temp_char / 10 + '0';
					temp[1] = temp_char % 10 + '0';
					lnumber mulresult(temp, length, true);
					ac = ac + mulresult;
				}
				else{
					int length = (r.length_ - 1 - i) + (length_ - 1 - j) + 1;
					char *temp = new char[length];
					memset(temp, '0', length);
					temp[0] = temp_char + '0';
					lnumber mulresult(temp, length, true);
					ac = ac + mulresult;
				}

			}
		}
		return ac;
	}
}
*/

lnumber lnumber::operator*(lnumber &r){
	complex* f1;
	complex* f2;
	complex* result;
	
	f1 = FFT(r.number_s_, e_length_, e_length_);
	f2 = FFT(number_s_, e_length_, e_length_);
	
	complex* f = new complex[e_length_];
	for (int k = 0; k < e_length_; k++){
		f[k].r = f1[k].r * f2[k].r - f1[k].i * f2[k].i;
		f[k].i = f1[k].r * f2[k].i + f1[k].i * f2[k].r;
	}

	result = REVERSE_FFT(f, e_length_, e_length_);
	
	lnumber temp;
	lnumber ac;
/*	for(int i = 0; i < e_length_; i++){
		temp = lnumber(round(result[i].r), i, true);
		ac = ac + temp;
	}
*/	return ac;
	/*
	lnumber ac;
	lnumber temp;
	for (int i = length_ - 1; i >= 0; i--){
		temp = r.mul_V_C(number_[i]);
		ac = ac + temp;
		r.time_10_();
	}
	
	return ac;
	*/
	}

lnumber lnumber::operator/(lnumber &r){
	
	char* number_copy = new char[length_];
	memcpy(number_copy, number_, length_);
	lnumber ac;
	lnumber ac_temp;
	lnumber temp(number_copy, length_, zero_bit_, out_symbol_);
	short countl;
	int circ = length_ - r.length_;
	if (length_ < r.length_){
		char* quotient;
		quotient = new char[1];
		quotient[0] = 0;
		return lnumber(quotient, number_, 1, length_);
	}
	else{
		r.time_N_(length_ - r.length_);
		for (int i = 0; i <= circ; i++){
			countl = 0;
			temp = temp - r;
			while (temp.out_symbol_){
				countl++;
				temp = temp - r;
			}
			
			char* ac_temp_number;
			ac_temp_number = new char[circ - i + 1];
			memset(ac_temp_number, '0', circ - i + 1);
			ac_temp_number[0] = countl + '0';
			ac_temp = lnumber(ac_temp_number, circ - i + 1, true);
			ac = ac + ac_temp;
			
			temp.out_symbol_ = true;
			temp = r - temp;
			r.time_1_10_();
		}
		return lnumber(ac.number_, temp.number_, ac.length_, temp.length_);
	}
}

void lnumber::out(){
	if (quotient == NULL)
	{
		
		printf("%c%s", out_symbol_ == true ? ' ' : '-', number_);
	}
	else{
		printf("%c%s, %c%s", out_symbol_ == true ? ' ' : '-', quotient, out_symbol_ == true ? ' ' : '-', remainder);
	}
}

lnumber::~lnumber(){
	
}
