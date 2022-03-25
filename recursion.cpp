#include <iostream>

int fact(int n) {
	if (n == 0) {
		return 1;
	}
	return n * fact(n - 1);
}

double power(int n, int k) {

	if (k < 0) {
		return 1 / power(n, -k);
	}

	if (k == 0) {
		return 1;
	}

	if (k % 2 == 1) {
		return n * power(n, k - 1);
	}
	else {
		int temp = power(n, k / 2);
		return temp * temp;
	}
}


int sumOfDigits(int n) {
	if (n / 10 == 0) {
		return n % 10;
	}

	return  n % 10 + sumOfDigits(n / 10);
}

int product(int n, int m) {
	if (m == 0 || n == 0) {
		return 0;
	}
	
	return n + product(n, m - 1);
}

int reverse(int n, int sum = 0) {
	if (n > 0) {
		int rem = n % 10;
		sum = sum * 10 + rem;
		reverse(n / 10, sum);
	}
	else {
		return sum;
	}
}


bool isPrime(int n, int i = 2)
{
	if (n <= 2)
		return (n == 2);
	if (n % i == 0)
		return false;
	if (i * i > n)
		return true;

	return isPrime(n, i + 1);
}

int toBinary(int n) {
	if (n == 0) {
		return 0;
	}
	return n % 2 + 10 * toBinary(n / 2);
}

int allVector(int n) {
	if(n == 0)
}

int main() {
	std::cout<< toBinary(127);
}