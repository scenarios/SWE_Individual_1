#include "lnumber.h"

int max(int a, int b){ return a > b ? a : b; }
lnumber::lnumber(char* input, bool symbol)
{
	number_ = input;
	zero_bit_ = 0;
	out_symbol_ = symbol;
}
lnumber::lnumber(char* input, const int N, bool symbol)
{
	number_ = input;
	length_ = N;
	zero_bit_ = 0;
	out_symbol_ = symbol;
}
lnumber::lnumber(char* input, const int N, const int zero_bit, bool out_symbol)
{
	
	length_ = N - zero_bit;
	if (length_ != 0)
		number_ = input + zero_bit;
	else
		number_ = input + zero_bit - 1;
	zero_bit_ = 0;
	out_symbol_ = out_symbol;
}
lnumber lnumber::operator+(const lnumber &r)
{
	

	if (pattern_ == P_P){
		char *output = new char[max(length_, r.length_) + 2];
		output[max(length_, r.length_) + 1] = '\0';
		int carry = 0;
		int i = max(length_, r.length_) - 1;
		int l = length_ - 1;
		int s = r.length_ - 1;

		for (; i >= -1; i--){
			if (l >= 0 && s >= 0){
				output[i + 1] = int(number_[l] - '0' + r.number_[s] - '0' + carry) % 10 + '0';
				carry = int(number_[l] - '0' + r.number_[s] - '0' + carry) / 10;
				l--;
				s--;
			}
			else if (l >= 0 && s < 0){
				output[i + 1] = int(number_[l] - '0' + 0 + carry) % 10 + '0';
				carry = int(number_[l] - '0' + 0 + carry) / 10;
				l--;
				s--;
			}
			else if (l < 0 && s >= 0){
				output[i + 1] = int(0 + r.number_[s] - '0' + carry) % 10 + '0';
				carry = int(0 + r.number_[s] - '0' + carry) / 10;
				l--;
				s--;
			}
			else if (l < 0 && s < 0){
				output[i + 1] = carry + '0';
				if (carry == 0)
					zero_bit_ += 1;
			}
		}
		return lnumber(output, max(length_, r.length_) + 1, zero_bit_, true);

	}


	else if (pattern_ == N_N){
		char *output = new char[max(length_, r.length_) + 2];
		output[max(length_, r.length_) + 1] = '\0';
		int carry = 0;
		int i = max(length_, r.length_) - 1;
		int l = length_ - 1;
		int s = r.length_ - 1;

		for (; i >= -1; i--){
			if (l >= 0 && s >= 0){
				output[i + 1] = int(number_[l] - '0' + r.number_[s] - '0' + carry) % 10 + '0';
				carry = int(number_[l] - '0' + r.number_[s] - '0' + carry) / 10;
				l--;
				s--;
			}
			else if (l >= 0 && s < 0){
				output[i + 1] = int(number_[l] - '0' + 0 + carry) % 10 + '0';
				carry = int(number_[l] - '0' + 0 + carry) / 10;
				l--;
				s--;
			}
			else if (l < 0 && s >= 0){
				output[i + 1] = int(0 + r.number_[s] - '0' + carry) % 10 + '0';
				carry = int(0 + r.number_[s] - '0' + carry) / 10;
				l--;
				s--;
			}
			else if (l < 0 && s < 0){
				output[i + 1] = carry + '0';
				if (carry == 0)
					zero_bit_ += 1;
			}
		}
		return lnumber(output, max(length_, r.length_) + 1, zero_bit_, false);

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
					temp = int(number_[l] - '0' - (r.number_[s] - '0') + carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

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
					temp = int(number_[l] - '0' - 0 + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i + 1] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			return lnumber(output, max(length_, r.length_), zero_bit_, true);
			break;

		case false:
			for (; i >= 0; i--){
				if (l >= 0 && s >= 0){
					temp = int(r.number_[s] - '0' - (number_[l] - '0') + carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

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
					temp = int(r.number_[s] - '0' - 0 + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i + 1] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			return lnumber(output, max(length_, r.length_), zero_bit_, false);
			break;
		}


	}
	else{
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
					temp = int(number_[l] - '0' - (r.number_[s] - '0') + carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

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
					temp = int(number_[l] - '0' - 0 + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i + 1] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			return lnumber(output, max(length_, r.length_), zero_bit_, false);
			break;

		case false:
			for (; i >= 0; i--){
				if (l >= 0 && s >= 0){
					temp = int(r.number_[s] - '0' - (number_[l] - '0') + carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

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
					temp = int(r.number_[s] - '0' - 0 + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i + 1] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			return lnumber(output, max(length_, r.length_), zero_bit_, true);
			break;
		}
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
	
	
	
	/*
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
					temp = int(number_[l] - '0' - (r.number_[s] - '0') + carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

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
					temp = int(number_[l] - '0' - 0 + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i + 1] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			return lnumber(output, max(length_, r.length_), zero_bit_, true);
			break;

		case false:
			for (; i >= 0; i--){
				if (l >= 0 && s >= 0){
					temp = int(r.number_[s] - '0' - (number_[l] - '0') + carry);
					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

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
					temp = int(r.number_[s] - '0' - 0 + carry);

					if (temp >= 0){
						if (temp == 0)
							zero_bit_ += 1;
						else
							zero_bit_ = 0;

						output[i] = temp + '0';
						carry = 0;
					}
					else{
						output[i + 1] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			return lnumber(output, max(length_, r.length_), zero_bit_, false);
			break;
		}

*/
	
}

lnumber::~lnumber(){

}
