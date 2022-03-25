#include <iostream>
#include <time.h>
const int MATRIX_SIZE = 4;

void init(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	srand(time(NULL));

	for (unsigned row = 0; row < MATRIX_SIZE; row++)
	{
		for (unsigned col = 0; col < MATRIX_SIZE; col++)
			 matrix[row][col] = (rand() % 9) + 1;
	}
}

void print(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	for (unsigned row = 0; row < MATRIX_SIZE; row++)
	{
		for (unsigned col = 0; col < MATRIX_SIZE; col++) {
			std::cout << matrix[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

int sumOfALlEvenNumbersBelowMainDiagonal(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	int sum = 0;
	for (int row = 0; row < MATRIX_SIZE; row++){
		for (int col = 0; col < row ; col++){
			if (matrix[row][col] % 2 == 0) {
				sum += matrix[row][col];
			}
		}
	}
	return sum;
}

int sumOfALlOddNumbersAboveMainDiagonal(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	int sum = 0;
	for (int row = 0; row < MATRIX_SIZE; row++) {
		for (int col = MATRIX_SIZE - 1; col >= row; col--) {
			if (matrix[row][col] % 2 == 1) {
				sum += matrix[row][col];
			}
		}
	}
	return sum;
}

void powerTheNumbersOnTheSecondDiagonal(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {	
	for (int row = 0; row < MATRIX_SIZE; row++) {
			matrix[row][MATRIX_SIZE -1 - row]*= matrix[row][MATRIX_SIZE - 1 - row];
	}	
}


void turnMatrixRight(int matrix[MATRIX_SIZE][MATRIX_SIZE], int cpyMatrix[MATRIX_SIZE][MATRIX_SIZE]) {
	int cpyRow = 0;
	int cpyCol = 0;
	for (int col = 0; col < MATRIX_SIZE; col++) {
		for (int row = MATRIX_SIZE - 1; row >= 0; row--) {
			if (cpyCol == MATRIX_SIZE) {
				cpyCol = 0;
				cpyMatrix[++cpyRow][cpyCol++] = matrix[row][col];
			}
			else {	
				cpyMatrix[cpyRow][cpyCol++] = matrix[row][col];
			}
		}
	}
}

void turnMatrixLeft(int matrix[MATRIX_SIZE][MATRIX_SIZE], int cpyMatrix[MATRIX_SIZE][MATRIX_SIZE]) {
	int cpyRow = 0;
	int cpyCol = 0;
	for (int col = MATRIX_SIZE - 1; col >=0; col--) {
		for (int row = 0; row < MATRIX_SIZE; row++) {
			if (cpyCol == MATRIX_SIZE) {
				cpyCol = 0;
				cpyMatrix[++cpyRow][cpyCol++] = matrix[row][col];
			}
			else {
				cpyMatrix[cpyRow][cpyCol++] = matrix[row][col];
			}
		}
	}
}

void flipMatrixByDiagonal(int matrix[MATRIX_SIZE][MATRIX_SIZE], int cpyMatrix[MATRIX_SIZE][MATRIX_SIZE]) {
	for (int row = 0; row < MATRIX_SIZE; row++) {
		for (int col = 0; col < MATRIX_SIZE; col++) {
				cpyMatrix[col][row] = matrix[row][col];
		}
	}
}

//[0,0] [0,1] [0,2] [0,3]
//[1,0] [1,1] [1,2] [1,3]
//[2,0] [2,1] [2,2] [2,3]
//[3,0] [3,1] [3,2] [3,3]

int main() {
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
	int matrixCpy[MATRIX_SIZE][MATRIX_SIZE];
	init(matrix);
	print(matrix);
	std::cout << std::endl;
	turnMatrixLeft(matrix, matrixCpy);
	print(matrixCpy);

}