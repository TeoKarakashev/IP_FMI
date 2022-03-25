#include <iostream>


void initMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

int digitsCount(int n) {
	int count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return count;
}

bool hasDigitMoreThanOnce(int n) {
	while (n > 0) {
		int temp = n;
		int currentNumber = temp % 10;
		temp /= 10;
		int digits = digitsCount(temp);
		for (int i = 0; i < digits; i++) {
			if (temp % 10 == currentNumber) {
				return true;
			}
			temp /= 10;
		}
		n /= 10;
	}
	return false;
}

void deleteMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}


//00 01 02 03
//10 11 12 13
//20 21 22 23
//30 31 32 33
int* collect() {
	int n = 3;
	int** matrix = new int* [n];
	initMatrix(matrix, n);
	int result[100];
	int index = 0;


	for (int i = n - 1; i > 0; i--) {
		for (int col = 0, row = i; row < n; col++, row++) {
			if (hasDigitMoreThanOnce(matrix[row][col])) {
				result[index++] = matrix[row][col];
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int row = 0, col = i; col < n; row++, col++) {
			if (hasDigitMoreThanOnce(matrix[row][col])) {
				result[index++] = matrix[row][col];
			}
		}
	}

	for (int i = 0; i < index; i++) {
		std::cout << result[i] << " ";
	}

	deleteMatrix(matrix, n);
	return result;
}

int main() {
	collect();


}
