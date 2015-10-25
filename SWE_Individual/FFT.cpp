#include "FFT.h"

complex* FFT(short* x, int length_current, int length_total)
{
	if (length_current == 1){
		complex* X = new complex[length_current];
/*		for (int k = 0; k <= length_total - 1; k++){
//			X[k].r = x[0] + cos(-2 * m_pi * k / length_current) * x[1];
//			X[k].i = sin(-2 * m_pi * k / length_current) * x[1];
			X[k].r = x[0];
			X[k].i = 0;
		}
		*/
		X[0].r = x[0];
		X[0].i = 0;
		return X;
	}
	else{
		complex *temp1;
		complex	*temp2;
		complex* X = new complex[length_current];
		short* x1 = new short[length_current / 2];
		short* x2 = new short[length_current / 2];
		int t1 = 0;
		int t2 = 0;
		for (int t = 0; t < length_current; t++){
			if (t % 2 == 0){
				x1[t1] = x[t];
				t1++;
			}
			else{
				x2[t2] = x[t];
				t2++;
			}
			
		}
		temp1 = FFT(x1, length_current / 2, length_total);
		temp2 = FFT(x2, length_current / 2, length_total);
		for (int k = 0; k < length_current / 2; k++){
			double W_c = cos(-2 * m_pi * k / length_current);
			double W_s = sin(2 * m_pi * k / length_current);
			X[k].r = temp1[k].r + W_c * temp2[k].r + W_s * temp2[k].i;
			//			X[k + length_current / 2].r = temp1[k].r + cos(-2 * m_pi * (k + length_current / 2) / length_current) * temp2[k].r + sin(2 * m_pi * (k + length_current / 2) / length_current) * temp2[k].i;
			X[k + length_current / 2].r = temp1[k].r - W_c * temp2[k].r - W_s * temp2[k].i;

			X[k].i = temp1[k].i + W_c * temp2[k].i - W_s * temp2[k].r;
			//			X[k + length_current / 2].i = temp1[k].i + cos(-2 * m_pi * (k + length_current / 2) / length_current) * temp2[k].i - sin(2 * m_pi * (k + length_current / 2) / length_current) * temp2[k].r;
			X[k + length_current / 2].i = temp1[k].i - W_c * temp2[k].i + W_s * temp2[k].r;
		}
		delete[] temp1;
		delete[] temp2;
		delete[] x1;
		delete[] x2;

		return X;
	}

}

complex* FFT(short* x, int length_current, int length_total, short* x1)
{
	if (length_current == 1){
		complex* X = new complex[length_current];
		/*		for (int k = 0; k <= length_total - 1; k++){
		//			X[k].r = x[0] + cos(-2 * m_pi * k / length_current) * x[1];
		//			X[k].i = sin(-2 * m_pi * k / length_current) * x[1];
		X[k].r = x[0];
		X[k].i = 0;
		}
		*/
		X[0].r = x[0];
		X[0].i = 0;
		return X;
	}
	else{
		complex *temp1;
		complex	*temp2;
		complex* X = new complex[length_current];
//		short* x1 = new short[length_current / 2];
		short* x2 = new short[length_current / 2];
		int t1 = 0;
		int t2 = 0;
		for (int t = 0; t < length_current; t++){
			if (t % 2 == 0){
				x1[t1] = x[t];
				t1++;
			}
			else{
				x2[t2] = x[t];
				t2++;
			}

		}
		temp1 = FFT(x1, length_current / 2, length_total, x1);
		temp2 = FFT(x2, length_current / 2, length_total, x2);
		for (int k = 0; k < length_current / 2; k++){
			double W_c_r = cos(-2 * m_pi * k / length_current) * temp2[k].r;
			double W_c_i = cos(-2 * m_pi * k / length_current) * temp2[k].i;
			double W_s_r = sin(2 * m_pi * k / length_current) * temp2[k].r;
			double W_s_i = sin(2 * m_pi * k / length_current) * temp2[k].i;
			X[k].r = temp1[k].r + W_c_r + W_s_i;
			//			X[k + length_current / 2].r = temp1[k].r + cos(-2 * m_pi * (k + length_current / 2) / length_current) * temp2[k].r + sin(2 * m_pi * (k + length_current / 2) / length_current) * temp2[k].i;
			X[k + length_current / 2].r = temp1[k].r - W_c_r - W_s_i;

			X[k].i = temp1[k].i + W_c_i - W_s_r ;
			//			X[k + length_current / 2].i = temp1[k].i + cos(-2 * m_pi * (k + length_current / 2) / length_current) * temp2[k].i - sin(2 * m_pi * (k + length_current / 2) / length_current) * temp2[k].r;
			X[k + length_current / 2].i = temp1[k].i - W_c_i  + W_s_r;
		}
		delete[] temp1;
		delete[] temp2;
//		delete[] x1;
		delete[] x2;

		return X;
	}

}


complex* REVERSE_FFT(complex* X, int length_current, int length_total)
{
	if (length_current == 1){
		complex* x = new complex[length_current];
		/*		for (int n = 0; n <= length_total - 1; n++){
		//			x[n].r = 1.0 / length_total * (X[0].r + cos(2 * m_pi * n / length_current) * X[1].r - sin(2 * m_pi * n / length_current) * X[1].i);
		//			x[n].i = 1.0 / length_total * (X[0].i + sin(2 * m_pi * n / length_current) * x[1].r + cos(2 * m_pi * n / length_current) * X[1].i);
		x[n].r = 1.0 / length_total * X[0].r;
		x[n].i = 1.0 / length_total * X[0].i;

		}
		*/
		x[0].r = 1.0 / length_total * X[0].r;
		x[0].i = 1.0 / length_total * X[0].i;
		return x;
	}
	else{
		complex *temp1;
		complex	*temp2;
		complex* x = new complex[length_current];
		complex* X1 = new complex[length_current / 2];
		complex* X2 = new complex[length_current / 2];
		int t1 = 0;
		int t2 = 0;
		for (int t = 0; t < length_current; t++){
			if (t % 2 == 0){
				X1[t1] = X[t];
				t1++;
			}
			else{
				X2[t2] = X[t];
				t2++;
			}

		}
		temp1 = REVERSE_FFT(X1, length_current / 2, length_total);
		temp2 = REVERSE_FFT(X2, length_current / 2, length_total);
		for (int n = 0; n < length_current / 2; n++){
			double W_c = cos(2 * m_pi * n / length_current);
			double W_s = sin(2 * m_pi * n / length_current);
			x[n].r = temp1[n].r + W_c * temp2[n].r - W_s * temp2[n].i;
			x[n + length_current / 2].r = temp1[n].r - W_c * temp2[n].r + W_s * temp2[n].i;
			x[n].i = temp1[n].i + W_c * temp2[n].i + W_s * temp2[n].r;
			x[n + length_current / 2].i = temp1[n].i - W_c * temp2[n].i - W_s * temp2[n].r;
		}
		delete[] temp1;
		delete[] temp2;
		delete[] X1;
		delete[] X2;

		return x;
	}
}


complex* REVERSE_FFT(complex* X, int length_current, int length_total, complex* X1)
{
	if (length_current == 1){
		complex* x = new complex[length_current];
		/*		for (int n = 0; n <= length_total - 1; n++){
		//			x[n].r = 1.0 / length_total * (X[0].r + cos(2 * m_pi * n / length_current) * X[1].r - sin(2 * m_pi * n / length_current) * X[1].i);
		//			x[n].i = 1.0 / length_total * (X[0].i + sin(2 * m_pi * n / length_current) * x[1].r + cos(2 * m_pi * n / length_current) * X[1].i);
		x[n].r = 1.0 / length_total * X[0].r;
		x[n].i = 1.0 / length_total * X[0].i;

		}
		*/
		x[0].r = 1.0 / length_total * X[0].r;
		x[0].i = 1.0 / length_total * X[0].i;
		return x;
	}
	else{
		complex *temp1;
		complex	*temp2;
		complex* x = new complex[length_current];
		//		complex* X1 = new complex[length_current / 2];
		complex* X2 = new complex[length_current / 2];
		int t1 = 0;
		int t2 = 0;
		for (int t = 0; t < length_current; t++){
			if (t % 2 == 0){
				X1[t1] = X[t];
				t1++;
			}
			else{
				X2[t2] = X[t];
				t2++;
			}

		}
		temp1 = REVERSE_FFT(X1, length_current / 2, length_total, X1);
		temp2 = REVERSE_FFT(X2, length_current / 2, length_total, X2);
		for (int n = 0; n < length_current / 2; n++){
			double W_c_i = cos(2 * m_pi * n / length_current) * temp2[n].i;
			double W_c_r = cos(2 * m_pi * n / length_current) * temp2[n].r;
			double W_s_i = sin(2 * m_pi * n / length_current) * temp2[n].i;
			double W_s_r = sin(2 * m_pi * n / length_current) * temp2[n].r;
			x[n].r = temp1[n].r + W_c_r - W_s_i;
			x[n + length_current / 2].r = temp1[n].r - W_c_r + W_s_i;
			x[n].i = temp1[n].i + W_c_i + W_s_r;
			x[n + length_current / 2].i = temp1[n].i - W_c_i - W_s_r;
		}
		delete[] temp1;
		delete[] temp2;
		//		delete[] X1;
		delete[] X2;

		return x;
	}
}