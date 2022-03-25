#include <iostream>
#include <cstring>

bool isValid(int index, unsigned length) {
	return (index >= 0) && (index < length);
}

int findNextGreenIndex(char* road, int index, unsigned length) {
	for (int i = index; i < length; i++) {
		if (road[i] == 'g') {
			return i;
		}
	}
	return length;
}

int findLongestPath(char* road) {
	unsigned longestPathFound = 0;
	unsigned currentPathFound = 0;
	unsigned longestIndex = 0;
	unsigned length = strlen(road);
	for (int i = 0; i < length; i++) {
		currentPathFound = 0;
		for (int j = i; j < length; j++) {
			if (j != i) {
				currentPathFound++;
			}
			if (road[j] == 'r') {
				break;
			}
			else if (road[j] == 'g') {

				continue;
			}
			else if (road[j] == 'y') {
				j = findNextGreenIndex(road, j, length);
				if (j < length) {
					currentPathFound++;
				}
			}
		}
		if (currentPathFound > longestPathFound) {
			longestPathFound = currentPathFound;
			longestIndex = i;
		}
	}
	std::cout << longestIndex << " ";
	return longestPathFound;
}

bool isPrefix(char* prefix, char* expr,int index) {

	int i = 0;
	while (prefix[i] != '\0'){
		if (expr[index] != prefix[i]) {
			return false;
		}
		i++;
		index++;
	}
	return true;

}

bool operatorsArePrefix(char* expr, int index, char operators[][6]) {
	for (int i = 0; i < 2; i++) {
		if (isPrefix(operators[i], expr, index)) {
			return true;
		}
	}
	return false;
}

int extractCurrentNumber(char* expr, char numbers[][6], int& index) {
	for (int i = 0; i < 10; i++){
		if (isPrefix(numbers[i], expr, index)) {
			index += strlen(numbers[i]);
			return i;
		}
	}
	return -1;
}

int getOperatorsCount(char* expr,unsigned length) {
	int count = 0;
	for (int i = 0; i < length; i++){
		if (expr[i] == 'p' || expr[i] == 'm') {
			count++;
		}
	}
	return count;
}

char getCurrentOperator(char* expr, int& index) {
	if (expr[index] = 'p') {
		index += 4;
		return '+';
	}
	else {

	}
}


int calculateExpr(char* expr) {
	int result = 0;
	int index = 0;
	int number = 0;
	char numbers[][6] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char operators[][6] = { "plus", "minus" };
	unsigned exprLength = strlen(expr);
	int operatorsCount = getOperatorsCount(expr, exprLength);
	int* numbersArray = new int[operatorsCount];
	while (index < strlen(expr)) {
		for (int i = 0; i <= operatorsCount; i++) {
			while (!operatorsArePrefix(expr, index, operators)) {
				number *= 10;
				number += extractCurrentNumber(expr, numbers, index);
			}
			char operand = getCurrentOperator(expr, index);
			result += number;
		}
	}
	delete[] numbersArray;
	return result;
}

int main() {
	char expr[] = { "rgyrggrygr" };
	std::cout << findLongestPath(expr) << std::endl;
	char expr2[] = { "ggrrgyrgyr" };
	std::cout << findLongestPath(expr2);
}