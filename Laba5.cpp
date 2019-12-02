#include <iostream>
#include <math.h>

class Vector {
private:
	int A[5];
public:
	friend void PrintArr(Vector* A, int n);
	void setVectorel(int a) {
		static int ptr = 0;
		this->A[ptr] = a;
		if (ptr == 4) ptr = -1;
		ptr++;
	}
	int mul() {
		int s = 1;
	for (int i = 0; i < 5; i++) {
			s *= A[i];
		}
		return s;
	}
	int* get_arr() {
		return A;
	}
	void SetArrEl(int c) {

		std::cin >> this->A[c];

	}
	 void PrintArr(Vector* A, int n);
	void merge(int start, int mid, int end) {
		int temp[5];
		int i = start, j = mid + 1, k = 0;

		while (i <= mid && j <= end) {
			if (this->A[i] >= this->A[j]) {
				temp[k] = this->A[i];
				k += 1; i += 1;
			}
			else {
				temp[k] = this->A[j];
				k += 1; j += 1;
			}
		}

		while (i <= mid) {
			temp[k] = this->A[i];
			k += 1; i += 1;
		}

		while (j <= end) {
			temp[k] = this->A[j];
			k += 1; j += 1;
		}

		// copy temp to original interval
		for (i = start; i <= end; i += 1) {
			this->A[i] = temp[i - start];
		}
	}

	void mergeSort(int start, int end) {

		if (start < end) {
			int mid = (start + end) / 2;
			mergeSort(start, mid);
			mergeSort(mid + 1, end);
			merge(start, mid, end);
		}

	}
};

 void PrintArr(Vector* A, int n) {
	 for (int i = 0; i > n; ++i)
	{
		std::cout << A->A[i];
	}
	std::cout << std::endl;
}




int main() {
	Vector A[5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			A[j].SetArrEl(i);
		}

	Vector R;
	Vector Fs;
	
	for (int i = 0; i < 5; i++)
		A[i].mergeSort(0, 4);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << A[j].get_arr()[i] << "\t ";
			R.setVectorel(A[j].get_arr()[i]);
		}
		Fs.setVectorel(R.mul());
		std::cout << std::endl;
	}


	class Calc {
	public:
		friend void Calcul(Calc Sum);
	};
	void Culcul(Calc Sum); {//Ця функція просто лютий колхоз,сорі япотім її перероблю)))
		int Sum = 0;
	
			std::cout << "f[i] :" << A[0].get_arr()[0] << std::endl;

			std::cout << "f[i] :" << A[0].get_arr()[1] << std::endl;

			std::cout << "f[i] :" << A[2].get_arr()[2] << std::endl;
			std::cout << "f[i] :" << A[2].get_arr()[3] << std::endl;
			std::cout << "f[i] :" << A[1].get_arr()[4] << std::endl;

		
		
			Sum = A[0].get_arr()[0]+ A[0].get_arr()[1]+ A[2].get_arr()[2]+ A[2].get_arr()[3]+ A[1].get_arr()[4];
		
	
		std::cout << "F(f[i]) :" << Sum << std::endl;

		std::cout << std::endl;
}


	return 0;
}