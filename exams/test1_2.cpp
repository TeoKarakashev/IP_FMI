#include<iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

bool isNumberGood(int n) {

	while (n > 0) {
		int lastDigit = n % 10;
		int secondLastDigit = n % 100;
		secondLastDigit /= 10;

		if (lastDigit == secondLastDigit) {
			return false;
		}

		n /= 10;
	}

	return true;
}

int mystery(int x)
{
	if (x == 0) return 0;
	if (x % 2) return 1 + mystery(x - 1);
	return 2 * mystery(x / 2);
}



int main(char* argv, int argc)
{

	std::cout << mystery(17);
	
}








	/*int a;
	int b;

	int biggestGoodNumber = INT_MIN;
	int smallestGoodNumber = INT_MAX;

	int count = 0;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;

	if (a > b) {
		swap(a, b);
	}

	for (int i = a; i <= b; i++){
		if (isNumberGood(i)) {
			count++;
			if (biggestGoodNumber < i) {
				biggestGoodNumber = i;
			}

			if (smallestGoodNumber > i) {
				smallestGoodNumber = i;
			}
		}
		
	}
	
	if (count > 0) {
		std::cout << biggestGoodNumber - smallestGoodNumber;
	}
	else {
		std::cout << "No adjacent numbers!";
	}*/
	
