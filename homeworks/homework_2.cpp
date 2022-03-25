#include <iostream>
#include <ctime>

const unsigned MAX_DICTIONARY_ELEMENTS = 128;
const unsigned MAX_ORIGINAL_TEXT_SIZE = 1024;
const unsigned MAX_NEW_TEXT_SIZE = 2048;
const unsigned MAX_DICTIONARY_ELEMENT_SIZE = 100;
const unsigned DICTIONARY_SIZE = 4;


//task 1
void initMatrix(int* arr[], unsigned rows, unsigned cols) {

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
}

void generateInput(int** matrix, int rows, int cols) {
	srand(time(0));
	int values[] = { -1, -2, -3, -4, 0, 1, 2, 3, 4, 5, 7 };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = values[rand() % 11];
		}
	}
}

void deleteMatrix(int** matrix, unsigned rows) {
	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void printMatrix(int** matrix, unsigned rows, unsigned cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void removeElementsFromCurrentRow(int*& arr, unsigned n) {
	int* temp = new int[n];
	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
	}

	delete[] arr;
	arr = temp;
}

void checkAndUpdateMatrixSizes(int** matrixA, unsigned& rowsA, unsigned& colsA, unsigned rowsB, unsigned colsB) {
	if (rowsA > rowsB) {
		for (int i = rowsB; i < rowsA; i++) {
			delete[] matrixA[i];
		}
		rowsA = rowsB;
	}

	if (colsA > colsB) {
		for (int i = 0; i < rowsA; i++) {
			removeElementsFromCurrentRow(matrixA[i], colsB);
		}
		colsA = colsB;
	}
}

void transformMatrix(unsigned rowsA, unsigned colsA, unsigned rowsB, unsigned colsB) {

	int** matrixA = new int* [rowsA];
	int** matrixB = new int* [rowsB];

	initMatrix(matrixA, rowsA, colsA);
	initMatrix(matrixB, rowsB, colsB);

	generateInput(matrixA, rowsA, colsA);
	generateInput(matrixB, rowsB, colsB);

	printMatrix(matrixA, rowsA, colsA);
	std::cout << std::endl;
	printMatrix(matrixB, rowsB, colsB);
	std::cout << std::endl;


	checkAndUpdateMatrixSizes(matrixA, rowsA, colsA, rowsB, colsB);

	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsA; j++) {
			if (matrixA[i][j] > matrixB[i][j]) {
				matrixA[i][j] *= -1;
			}
			else if (matrixA[i][j] < matrixB[i][j]) {
				matrixA[i][j] = matrixB[i][j];
			}
		}
	}

	printMatrix(matrixA, rowsA, colsA);

	deleteMatrix(matrixA, rowsA);
	deleteMatrix(matrixB, rowsB);
}

void transformMatrixController() {
	unsigned rowA = 3;
	unsigned colA = 4;
	unsigned rowB = 4;
	unsigned colB = 5;
	transformMatrix(rowA, colA, rowB, colB);
}


//task 2'
void initBoard(char* board[], unsigned rows, unsigned cols) {
	for (int i = 0; i < rows; i++) {
		board[i] = new char[cols];
		for (int j = 0; j < cols; j++)
		{
			std::cin >> board[i][j];
		}
	}
}

bool isValid(int row, int col, unsigned rows, unsigned cols) {
	return (row >= 0) && (row < rows) &&
		(col >= 0) && (col < cols);
}

void toLower(char** board, int row, int col) {
	if (board[row][col] >= 'A' && board[row][col] <= 'Z') {
		board[row][col] = (board[row][col] - 'A') + 'a';
	}
}

void toUpper(char** board, int row, int col) {
	if (board[row][col] >= 'a' && board[row][col] <= 'z') {
		board[row][col] = (board[row][col] - 'a') + 'A';
	}

}

void resetBoard(char** board, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			toUpper(board, i, j);
		}
	}
}

void move(char** board, int row, int col, unsigned rows, unsigned cols, unsigned& pathLength) {
	if (isValid(row, col, rows, cols)) {
		pathLength++;
		if (board[row][col] == 'R') {
			toLower(board, row, col);
			move(board, row, col + 1, rows, cols, pathLength);
		}
		else if (board[row][col] == 'D') {
			toLower(board, row, col);
			move(board, row + 1, col, rows, cols, pathLength);
		}
		else if (board[row][col] == 'L') {
			toLower(board, row, col);
			move(board, row, col - 1, rows, cols, pathLength);
		}
		else if (board[row][col] == 'U') {
			toLower(board, row, col);
			move(board, row - 1, col, rows, cols, pathLength);
		}
	}
}

unsigned currentPathLength(char** board, int row, int col, unsigned rows, unsigned cols) {
	unsigned pathLength = 0;
	move(board, row, col, rows, cols, pathLength);
	return pathLength;
}

void printBoard(char** board, unsigned rows, unsigned cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void findLongestPath(char** board, unsigned rows, unsigned cols) {
	unsigned movesMade = 0;
	unsigned longestPathLength = 0;
	unsigned longestPathRow = 0;
	unsigned longestPathCol = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			movesMade = currentPathLength(board, i, j, rows, cols);
			resetBoard(board, rows, cols);
			if (movesMade > longestPathLength) {
				longestPathLength = movesMade;
				longestPathRow = i;
				longestPathCol = j;
			}
			movesMade = 0;
		}
	}
	std::cout << longestPathRow << " " << longestPathCol;
}

void longestPathController() {
	unsigned rows = 4;
	unsigned cols = 4;
	char** board = new char* [rows];;
	initBoard(board, rows, cols);
	findLongestPath(board, rows, cols);
}


//ex 0
bool isPresent(char symbol, char* symbols) {
	unsigned length = strlen(symbols);
	for (int i = 0; i < length; i++) {
		if (symbols[i] == symbol) {
			return true;
		}
	}
	return false;
}

bool isPunctuation(char symbol) {
	char symbols[] = { ".,?!;:-+*/^=(" };
	return isPresent(symbol, symbols);
}

bool isPrefix(const char* text, const char* prefix)
{
	int i = 0;
	while (prefix[i] != '\0')
	{
		if (text[i] == '\0' || text[i] != prefix[i])
			return false;
		i++;
	}
	return true;
}

void splitDictionary(char wordsToCheck[DICTIONARY_SIZE][MAX_DICTIONARY_ELEMENT_SIZE], char correctWords[DICTIONARY_SIZE][MAX_DICTIONARY_ELEMENT_SIZE], const char dictionary[DICTIONARY_SIZE][MAX_DICTIONARY_ELEMENT_SIZE]) {
	for (int i = 0, j = 0, p = 0; i < DICTIONARY_SIZE; i++) {
		j = 0;
		p = 0;
		while (dictionary[i][j] != '-') {
			wordsToCheck[i][j] = dictionary[i][j];
			j++;
		}
		wordsToCheck[i][j] = '\0';
		j++;
		while (dictionary[i][j] != '\0') {
			correctWords[i][p++] = dictionary[i][j];
			j++;
		}
		correctWords[i][p] = '\0';
	}
}

void substr(const char* text, const int begin, char* res)
{
	int length = strlen(text);
	for (int i = begin, resIndex = 0; i < length; i++) {
		res[resIndex++] = text[i];
	}

}

bool needSpaceBefore(char ch) {
	return ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '^' || ch == '=' || ch == '(';
}

bool wordFromWordsToCheckIsPrefix(char wordsToCheck[DICTIONARY_SIZE][MAX_DICTIONARY_ELEMENT_SIZE], int index, char* text, int& wordFoundIndex) {

	char* currentText = new char[strlen(text) - index];
	substr(text, index, currentText);
	for (int i = 0; i < DICTIONARY_SIZE; i++) {
		if (isPrefix(currentText, wordsToCheck[i])) {
			wordFoundIndex = i;
			delete[] currentText;
			return true;
		}
	}
	delete[] currentText;
	return false;
}

bool isEndOfSentence(char* textToCorrect, int index, unsigned length) {

	if (index + 1 > length || index + 2 > length) {
		return true;
	}
	if ((textToCorrect[index + 1] == ' ' && textToCorrect[index + 2] >= 'A' && textToCorrect[index + 2] <= 'Z') || (textToCorrect[index + 1] == '\n')) {
		return true;
	}

	return false;
}

void printOriginalText(char* text, unsigned length) {
	for (int i = 0; i < length; i++) {
		std::cout << text[i];
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void autoCorrect(char* textToCorrect, const char dictionary[DICTIONARY_SIZE][MAX_DICTIONARY_ELEMENT_SIZE]) {
	char wordsToCheck[DICTIONARY_SIZE][MAX_DICTIONARY_ELEMENT_SIZE];
	char correctWords[DICTIONARY_SIZE][MAX_DICTIONARY_ELEMENT_SIZE];
	splitDictionary(wordsToCheck, correctWords, dictionary);
	unsigned correctedTextindex = 0;
	int wordFoundIndex = 0;
	char correctedText[MAX_NEW_TEXT_SIZE];
	unsigned textLength = strlen(textToCorrect);
	printOriginalText(textToCorrect, textLength);
	for (int i = 0; i < textLength; i++) {
		if (isPunctuation(textToCorrect[i])) {
			if (needSpaceBefore(textToCorrect[i])) {
				if (((i - 1) > 0) && textToCorrect[i - 1] != ' ') {
					correctedText[correctedTextindex++] = ' ';
				}
			}
			correctedText[correctedTextindex++] = textToCorrect[i];
			if ((i + 1 < textLength) && textToCorrect[i + 1] != ' ') {
				correctedText[correctedTextindex++] = ' ';
			}
		}
		else if (wordFromWordsToCheckIsPrefix(wordsToCheck, i, textToCorrect, wordFoundIndex)) { //checks if there is a match between a word from the dictionary and the current prefix
			int length = strlen(correctWords[wordFoundIndex]);
			for (int j = 0; j < length; j++) {
				correctedText[correctedTextindex++] = correctWords[wordFoundIndex][j];
			}
			i += (strlen(wordsToCheck[wordFoundIndex]) - 1); //skips wrong word
		}
		else if (isEndOfSentence(textToCorrect, i, textLength)) {
			if (textToCorrect[i] == '.') {
				correctedText[correctedTextindex++] = textToCorrect[i];
			}
			else if (textToCorrect[i] == '"' && textToCorrect[i - 1] != '.') {

				correctedText[correctedTextindex++] = '.';
				correctedText[correctedTextindex++] = textToCorrect[i];
			}
			else if (textToCorrect[i] != '.') {
				correctedText[correctedTextindex++] = textToCorrect[i];
				correctedText[correctedTextindex++] = '.';
			}
		}
		else {
			correctedText[correctedTextindex++] = textToCorrect[i];
		}
	}



	for (int i = 0; i < correctedTextindex; i++) {
		std::cout << correctedText[i];
	}

}

void autoCorrectController() {
	char textToCorrect[MAX_ORIGINAL_TEXT_SIZE] = { "Once upun a time in a village,a little country girl, the pritiest creature ever to live.Her mother was excessively fond of her;and her grandmother doted on her still more.This good woman had a little red riding hood made for her.It suited the girl so extremely well that everybody called her little red riding hood.\nOne day her mother, having made some cakes, said to her, \"2+2=4-1=3, my dear, and see how your grandmother is doing, I heard she has been very ill. Take her a cake, and this buter\"" };
	const char dictionary[DICTIONARY_SIZE][MAX_DICTIONARY_ELEMENT_SIZE] = {
		"upun-upon\0", "pritiest-prettiest\0", "little red riding hood-Little Red Riding Hood\0", "buter-butter\0" };

	autoCorrect(textToCorrect, dictionary);

}

int main() {
	//autoCorrectController();          //ex 0
	//transformMatrixController();		//ex 1	     
	//longestPathController();			//ex 2'		
}