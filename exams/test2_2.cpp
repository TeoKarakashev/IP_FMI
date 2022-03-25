#include<iostream>
#include <cstring>

int findLetterIndex(char letter, char* letters) {
	int lettersL = strlen(letters);
	for (int i = 0; i < lettersL; i++){
		if (letters[i] == letter) {
			return i;
		}
	}
	return -1;
}

int getValue(char letter, int* values, char* letters) {
	return values[findLetterIndex(letter, letters)];
}

int getAllProducts(int* values, char* letters, char* input) {
	int sumOfProducts = 0;
	int currentProduct = 0;
	int inputLength = strlen(input);
	for (int i = 0; i < inputLength; i++){
		currentProduct = 0;
		if (input[i] == '.') {
			currentProduct += (getValue(input[i - 1],  values, letters) * getValue(input[i + 1], values, letters));
			

			sumOfProducts = currentProduct;
		}
	}
	return sumOfProducts;
}

int addLettersThatAreNotInAProduct(int* values, char* letters, char* input) {
	int sum = 0;
	int inputLength = strlen(input);
	for (int i = 1; i < inputLength - 1; i++) {
		if (input[i - 1] == '+' && input[i + 1] == '+') {
			sum += getValue(input[i], values, letters);
		}
	}
	return sum;
}


void calculate(int* values, char* letters) {
	int sum = 0;		
	char input[] = "h.e.l.l.o+w.o.r.l.d";
	sum += getAllProducts( values,  letters, input);
	sum += addLettersThatAreNotInAProduct(values, letters, input);;
	
	std::cout << sum;
}
int main() {
	int values[] = { 1,2,3,1,2,1,7,8,0,10,11,12,13,14,15 };
	char letters[] = { 'a', 'b' , 'c', 'h', 'e', 'l','o', 'd', 'w', 'r' };
	calculate(values, letters);
}