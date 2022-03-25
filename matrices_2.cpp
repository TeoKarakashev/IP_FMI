#include <iostream>

const int ROWS = 4;
const int COLS = 4;
const int DEPTH = 3;

void plusFive(int* a) {
	*a += 5;
}

void iterMatrix(int matrix[ROWS][COLS], const int rows, const int cows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cows; j++)
		{
			std::cout << *(*(matrix + i) + j) << " ";	
		}
		std::cout << std::endl;
	}
}

void iterCube(int matrix[ROWS][COLS][DEPTH], const int rows, const int cows, const int depth) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cows; j++)
		{
			for (int k = 0; k < depth; k++)
			{
				std::cout << *(*(*(matrix + i) + j)+ k);
			}
		std::cout << std::endl;
		}
	}
}

void sumMatrixes(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], const int rows, const int cols) {
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++)
		{
			matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}

//[] [] []  //[] [] [] 
//[] [] []	//[] [] [] 	
//[] [] []  //[] [] []  


void multiplyMatrixes(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS], const int rows, const int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++){
			for (int  k = 0; k < rows; k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}



int main() {
	int firstMatrix[ROWS][COLS] = { {1, 2, 3, 0}, {4, 5, 6, 1}, {7, 8, 9, 2}, {7, 6, 39, 5} };
	int secondMatrix[ROWS][COLS] = { {10, 11, 12, 1}, {13, 14, 15, 3}, {0, 21, 22, 23}, {7, 8, 9, 2} };
	int result[ROWS][COLS] = { 0 };
	multiplyMatrixes(firstMatrix, secondMatrix, result, ROWS, COLS);

	iterMatrix(result, ROWS, COLS);
};
						
