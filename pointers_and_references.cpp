#include <iostream>


void remove(int* arr, int& size, int index) {

	for (int i = index; i < size - 1; i++)
	{
		 arr[i] = arr[i + 1];
		
	}
	arr[size - 1] = -1;
	size--;
}

int biggestRowIndex(int** matrix, int rows, int cols) {
	int biggestRowIndex = 0;
	int biggestSum = INT_MIN;
	for (int row = 0; row < rows; row++){
		int currentSum = 0;
		for (int col = 0; col < cols; col++){
			currentSum += matrix[row][col];
		}
		if (currentSum > biggestSum) {
			biggestSum = currentSum;
			biggestRowIndex = row;
		}
	}
	return biggestRowIndex;
}

void initMatrix(int* matrix[], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void initArray(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void removeRowFromMatrix(int** matrix, int k, int& rows) {
	delete[] matrix[k];
	for (int i = k; i < rows - 1; i++)
		matrix[i] = matrix[i + 1];
	--rows;
}


void shift(int* arr, int n) {
	int lastEl = arr[0];
	for (int i = 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}
	arr[n - 1] = lastEl;
}

void cycle(int* arr, int n, int k) {
	if (k >= n) {
		k % n;
	}
	for (int i = 0; i < k; i++)
	{
		shift(arr, n);
	}

}


int main() {

	int n;
	std::cin >> n;
	int* arr = new int[n];
	initArray(arr, n);
	cycle(arr, n, 4);
	for (int i = 0; i < n; i++)
	{
	std::cout << arr[i]<< " ";
	}

	delete arr;
	/*int** matrix = new int* [n];
	initMatrix(matrix, n, m);*/


	/*for (int i = 0; i < n; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;*/



}