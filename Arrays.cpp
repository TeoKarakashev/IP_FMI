#include<iostream>
#include<math.h>


int sumBetweenTwoNumbers(int n, int m) {
	if (n > m) {
		int temp = m;
		m = n;
		n = temp;
	}
	int sum = 0;
	for (int i = n; i <= m; i++) {
		sum += i;
	}
	return sum;
}

int numberToThePower(int n, int m) {
	int sum = n;
	for (int i = 1; i < m; i++) {
		sum *= n;
	}
	return sum;
}


int absoluteValue(int n) {
	return n < 0 ? n * (-1) : n;
}

double findDistance(int x1, int y1, int x2, int y2) {
	return sqrt(numberToThePower(x2 - x1, 2) + numberToThePower(y2 - y1, 2));
}

double perimeter(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (findDistance(x1, y1, x2, y2) + findDistance(x1, y1, x3, y3) + findDistance(x2, y2, x3, y3));
}

bool isNumber(char n) {
	return n >= 48 && n <= 57 ? true : false;
}

int factorial(int n) {
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		sum *= i;
	}
	return sum;
}


int main() {

	char n;
	std::cin >> n;
	std::cout<<isNumber(n);
}