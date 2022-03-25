#include <iostream>

const int MAX_SIZE = 1023;

bool isSubArrayInTheSecond(char firstArr[], char secondArr[], int size2) {
	for (int i = 0; i < size2; i++){
		if (firstArr[i] != secondArr[i]) {
			return false;
		}
	}
	return true;
}

void clear(char arr[], int size2) {
	for (int i = 0; i < size2; i++){
		arr[i] = 0;
	}
}

void rotateSecondArr(char arr[], int size ) {
	char lastEl = arr[size-1];
	char newChar[MAX_SIZE];
	newChar[0] = lastEl;
	for (int i = 1; i < size-1; i++){
		newChar[i] = arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = newChar[i];
	}
}

bool isSecondContainedInTheFirst(char firstArr[], char secondArr[], int size1, int size2) {
	
	char subArrayFromFirst[MAX_SIZE];

	for (int i = 0; i < (size1-size2)+1; i++){
		for (int j = i; j < size2; j++) {
			subArrayFromFirst[j] = firstArr[j];
		}
		if (isSubArrayInTheSecond(subArrayFromFirst, secondArr, size2)) {
			return true;
		}
		clear(subArrayFromFirst, size2);

	}

	return false;
}

int main() {
	char firstArr[MAX_SIZE];
	char secondArr[MAX_SIZE];

	int size1, size2;
	std::cout << "size1: ";
	std::cin >> size1;
	std::cout << "size2: ";
	std::cin >> size2;

	std::cout << "FirstArr: ";
	char element;
	for (int i = 0; i < size1; i++) {
		std::cin >> element;
		firstArr[i] = element;

	}
	std::cout << "SecondArr: ";
	for (int i = 0; i < size2; i++) {
		std::cin >> element;
		secondArr[i] = element;
	}

	for (int i = 0; i < size2-1; i++)
	{
		if (isSecondContainedInTheFirst(firstArr, secondArr, size1, size2)) {
			std::cout << "True";
			return 1;
		}
		else {
			rotateSecondArr(secondArr, size2);
	}


}