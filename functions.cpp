#include<iostream>


char toUpper(char a) {
	return a - 32;
}


int gcd(int a, int b) {
	if (b < a) {
		int temp = b;
		b = a;
		a = temp;
	}

	while (b !=0)
	{
		int rem = a % b;
		if (rem == 0) {
			return b;
		}
		a = b;
		b = rem;
	}
}

int lcd(int a, int b) {
	if (b < a) {
		int temp = b;
		b = a;
		a = temp;
	}

	for (int i = 2; i <= b; i++)
	{
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
	return 1;
}

int digitFromNumber(int n, int m) {
	for (int i = 0; i < m; i++)
	{
		n /= 10;
	}	
	return n % 10;
}

int size(int num) {
	int count = 0;

	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return count;
}


bool hasSameDigits(int num) {

	int copyOfNum = 0;

	while (num > 0)
	{
		int currentDigit = num % 10;
		num /= 10;
		copyOfNum = num;
		int sizeOfNum = size(num);
		for (int i = 0; i < sizeOfNum; i++) {
			if (currentDigit == copyOfNum % 10) {
				return 1;
			 }
			copyOfNum /= 10;
		}
	}
	return 0;

}

void allOrderedCopules(int n) {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			std::cout << "(" << i << ", " << j << ")" << std::endl;
		}
	}
}

void validateInput(int& num) {

	while (num  < 100)
	{
		std::cin >> num;
	}
}

int sumOfDigits(int num) {
	int sum = 0;
	int temp = 0;
	while (num != 0) {
		temp = num % 10;
		sum += temp;
		num /= 10;
	}
	return sum;
}

int productOfDigits(int num) {
	int product = 1;
	int temp = 0;
	while (num != 0) {
		temp = num % 10;
		product *= temp;
		num /= 10;
	}
	return product;
}

void checkIfNumbersInIntervalHaveSameSumAndProduct(int a, int b) {
	if (a > b) {
		int temp = b;
		b = a;
		a = temp;
	}


	for (int i = a; i <= b; i++)
	{
		if (sumOfDigits(i) == productOfDigits(i)) std::cout << i<<" ";
	}
}



int main() {

	checkIfNumbersInIntervalHaveSameSumAndProduct(1, 30);
	
}