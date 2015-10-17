#include "lnumber.h"

int max(int a, int b){ return a > b ? a : b; }
lnumber::lnumber()
{
	input_ = new char[1];
	number_ = input_;
	number_[0] = '0';
	zero_bit_ = 0;
	out_symbol_ = true;
	pattern_ = 0;

}

lnumber::lnumber(char* input, const int N, bool symbol)
{
	input_ = input;
	number_ = input_;
	length_ = N;
	zero_bit_ = 0;
	out_symbol_ = symbol;
	pattern_ = 0;
}
lnumber::lnumber(char* input, const int N, const int zero_bit, bool out_symbol)
{
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
lnumber lnumber::operator+(const lnumber &r)
{
	if (pattern_ == N_N){
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
		delete[] input_;
		//delete[] r.input_;
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
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			delete[] input_;
		//	delete[] r.input_;
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
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			delete[] input_;
			delete[] r.input_;
	//		return lnumber(output, max(length_, r.length_), zero_bit_, false);
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
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			delete[] input_;
	//		delete[] r.input_;
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
						output[i] = temp + 10 + '0';
						carry = -1;
					}

					l--;
					s--;
				}
				else{}
			}
			delete[] input_;
	//		delete[] r.input_;
			return lnumber(output, max(length_, r.length_), zero_bit_, true);
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
		delete[] input_;
//		delete[] r.input_;
		return lnumber(output, max(length_, r.length_) + 1, zero_bit_, true);

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

				short temp_short = (r.number_[i] - '0') * (number_[j] - '0');
				if (temp_short / 10 != 0){
					int length = (r.length_ - 1 - i) + (length_ - 1 - j) + 2;
					char *temp = new char[length];
					memset(temp, '0', length);
					temp[0] = temp_short / 10 + '0';
					temp[1] = temp_short % 10 + '0';
					lnumber mulresult(temp, length, true);
					ac = ac + mulresult;
				}
				else{
					int length = (r.length_ - 1 - i) + (length_ - 1 - j) + 1;
					char *temp = new char[length];
					memset(temp, '0', length);
					temp[0] = temp_short + '0';
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

				short temp_short = (r.number_[i] - '0') * (number_[j] - '0');
				if (temp_short / 10 != 0){
					int length = (r.length_ - 1 - i) + (length_ - 1 - j) + 2;
					char *temp = new char[length];
					memset(temp, '0', length);
					temp[0] = temp_short / 10 + '0';
					temp[1] = temp_short % 10 + '0';
					lnumber mulresult(temp, length, true);
					ac = ac + mulresult;
				}
				else{
					int length = (r.length_ - 1 - i) + (length_ - 1 - j) + 1;
					char *temp = new char[length];
					memset(temp, '0', length);
					temp[0] = temp_short + '0';
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
	lnumber ac;
	for (int i = length_ - 1; i >= 0; i--){
		
		for (int j = 0; j < int(number_[i] - '0'); j++){
			ac = ac + r;
		}
		r.time_10_();
	}
	
	return ac;
}

lnumber::~lnumber(){
	
}
