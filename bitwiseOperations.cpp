#include<iostream>


void getBitwiseRepresenation(int n) {
	
	for (int i = 31; i >= 0; i--) {
		std::cout << ((n & (1 << i)) != 0);
	}
	
}

void flipFourthBit(int n) {
	std::cout << (n ^ 8);
}

int countOfZeros(int n) {

	int count = 0;
	for (int i = 31; i >= 0; i--) {
		if ((n & (1 << i)) == 0) {
			count++;
		}
	}
	return count;

}

int setBit(int n, int bitPosition, bool newBitValue) {
	if (!(n >> bitPosition ^ newBitValue)) {
		return n;
	}
	return n ^ (1 << bitPosition);
}

void changeSign(int n) {
	std::cout << ~n + 1;
}

int main() {
	
	changeSign(10);
	std::cout << setBit(10, 2, 1);
}

