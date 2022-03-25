#include <iostream>

int flip(int number) {
	int result = 0;
	while (number > 0)
	{
		result = number % 10;
		result *= 10;
		number /= 10;
	}
	result /= 10;
	return result;
}

bool isKInN(int n, int k) {
	int nCopy = n;
	int kCopy = k;
	int kCounter = 0;
	while (kCopy) {
		std::cout << kCopy << " ";
		kCopy /= 10;
		kCounter++;
	}
	//std::cout << kCounter;
	int nToCheck = 0;
	

	for (int i = 0; i < kCounter; i++)
	{
		nToCheck = nCopy % 10;
		nCopy /= 10;
		nToCheck *= 10;
	}

	 nToCheck = flip(nToCheck);

	// std::cout << nToCheck;
	
	if (nToCheck = k) {
		return true;
	}
}

int main() {

	int n;
	int k;

	std::cout << "N:";
	std::cin >> n;
	std::cout << "K:";
	std::cin >> k;

	std::cout << isKInN(n, k);
}