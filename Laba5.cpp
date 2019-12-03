#include <iostream>
#include <math.h>
#define SIZE 5
class Vector {
private:
	int Array[SIZE];
public:
	friend void PrintArr(Vector* A, int n);
	void setVectorel(int a) {
		static int pointer = 0;
		this->Array[pointer] = a;
		if (pointer == 4) pointer = -1;
		pointer++;
	}
	int multipley() {
		int s = 1;
		for (int columns = 0; columns < 5; columns++) {
			s *= Array[columns];
		}
		return s;
	}
	int* get_arr() {
		return Array;
	}
	void SetArrEl(int c) {

		std::cin >> this->Array[c];

	}
	void PrintArr(Vector* A, int n);
	void merge(int start, int mid, int end) {
		int temp[SIZE];
		int columns = start, j = mid + 1, k = 0;

		while (columns <= mid && j <= end) {
			if (this->Array[columns] >= this->Array[j]) {
				temp[k] = this->Array[columns];
				k += 1; columns += 1;
			}
			else {
				temp[k] = this->Array[j];
				k += 1; j += 1;
			}
		}

		while (columns <= mid) {
			temp[k] = this->Array[columns];
			k += 1; columns += 1;
		}

		while (j <= end) {
			temp[k] = this->Array[j];
			k += 1; j += 1;
		}

		// copy temp to original interval
		for (columns = start; columns <= end; columns += 1) {
			this->Array[columns] = temp[columns - start];
		}
	}

	void mergeSortСolumnsВescending(int start, int end) {

		if (start < end) {
			int mid = (start + end) / 2;
			mergeSortСolumnsВescending(start, mid);
			mergeSortСolumnsВescending(mid + 1, end);
			merge(start, mid, end);
		}

	}
};

void PrintArr(Vector* Array, int n) {
	for (int columns = 0; columns > n; ++columns)
	{
		std::cout << Array->Array[columns];
	}
	std::cout << std::endl;
}




int main( ) {
	
	Vector Array[SIZE];
	for (int columns = 0; columns < 5; columns++)
		for (int rows = 0; rows < 5; rows++) {
			Array[rows].SetArrEl(columns);
		}

	Vector colums;
	Vector arrayOfFunction;

	for (int columns = 0; columns < 5; columns++)
		Array[columns].mergeSortСolumnsВescending(0, 4);
	for (int rows = 0; rows < SIZE; rows++) {
		for (int columns = 0; columns < 5; columns++) {
			std::cout << Array[columns].get_arr()[rows] << "\t ";
			colums.setVectorel(Array[columns].get_arr()[rows]);
		}
		arrayOfFunction.setVectorel(colums.multipley);
		std::cout << std::endl;
	}


	class calculationFunction {
	public:
		friend void Calculation(calculationFunction Sum);
	};
	void Culculation(calculationFunction Sum); {
	
	int Result=0;
		for (int k = 0; k < 5; k++) {
			std::cout << "Max in colums "<<Array[k].get_arr()[0] << std::endl;
			Result += Array[k].get_arr()[0];
		}
	

std::cout << "the sum of the elements= " << Result << std::endl;
		std::cout << std::endl;
	}


	return 0;
}
