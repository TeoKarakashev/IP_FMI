#include <iostream>

bool isEven(int n) {
	return (n % 2) == 0;
}

void plusFive(int& n) {
	n += 5;
}

void map(int* arr, int length, void (*map)(int&)) {
	for (size_t i = 0; i < length; i++) {
		map(arr[i]);
	}
}

void filter(int* arr, int  length, bool (*predicate)(int)) {
	for (size_t i = 0; i < length; i++) {
		if (!predicate(arr[i])) {
			arr[i] = -1;
		}
	}
}

int replace(int n) {
	if (n < 10) {
		if (n == 5) {
			return 8;
		}
		return n;
	}
	int digit = n % 10;
	if (digit == 5) {
		digit = 8;
	}
	return replace(n / 10) * 10 + digit;
}

bool binarySearch(int* arr, int length, int n) {
	if (length == 0) {
		return false;
	}

	int mid = length / 2;

	if (arr[mid] == n) {
		return true;
	}

	if (arr[mid] > n) {
		return binarySearch(arr, mid, n);
	}
	return binarySearch(arr + mid + 1, length - mid - 1, n);
}

bool isInBorder(int row, int col, int n, int m) {
	return row >= 0 && row < n && col >= 0 && col < m;
}

bool hasPath(bool board[][5], int n, int m, int row, int col, int endIndexRow, int endIndexCow) {
	if (!isInBorder(row, col, n, m)) {
		return false;
	}
	if (board[row][col] == 1) {
		return false;
	}
	if (row == endIndexRow && col == endIndexCow) {
		return true;
	}
	board[row][col] = 1;
	return hasPath(board, n, m, row + 1, col, endIndexRow, endIndexCow) ||
		hasPath(board, n, m, row - 1, col, endIndexRow, endIndexCow) ||
		hasPath(board, n, m, row, col + 1, endIndexRow, endIndexCow) ||
		hasPath(board, n, m, row, col - 1, endIndexRow, endIndexCow);
}

int main() {
	bool board[5][5] = { {0, 0, 0, 1, 1},
						{0, 1, 1, 1, 1},
						{0, 0, 1, 0, 1},
						{0, 1, 1, 0, 1},
						{0, 0, 0, 0, 1} };
	std::cout << hasPath(board, 5, 5, 0, 0, 3, 3);
}