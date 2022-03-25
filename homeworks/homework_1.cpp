#include <iostream>
#include <time.h>

const double EPSILON = 0.00001f;
const unsigned NUMBER_OF_GUESSES = 10;
const unsigned DIGITS_COUNT = 4;

//zad 0
double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

int compareDoubles(double a, double b) {
	//returns 0 if a and b are equal
	//returns 1 if a > b
	//returns -1 if b > a
	if (fabs(a - b) < EPSILON) return 0;
	if ((a - b) > EPSILON) return 1;

	return -1;
}

bool isInPink(double x, double y) {
	double a = areaOfTriangle(-0.001, 0, -2.827, -2.827, -2.827, 2.827);
	double a1 = areaOfTriangle(x, y, -0.001, 0, -2.827, -2.827);
	double a2 = areaOfTriangle(-2.827, -2.827, x, y, -2.827, 2.827);
	double a3 = areaOfTriangle(-2.827, 2.827, -0.001, 0, x, y);

	return (compareDoubles(a, a1 + a2 + a3) == 0);
}

bool isInPurple(double x) {
	return (compareDoubles(x, 2.828) == 1);
}

bool isInRed(double x, double y) {
	return ((compareDoubles(x, 0) == -1) && (compareDoubles(x, -2.828) == 1) && (compareDoubles(y, abs(x)) == 1));
}

bool isInGreen(double x, double y) {

	return ((compareDoubles(x, 0) == 1) && (compareDoubles(x, 2.828) == -1) && (compareDoubles(y, x) == 1));
}

bool isInBlue(double x, double y) {
	return ((compareDoubles(x, 0) == -1) && (compareDoubles(x, -2.828) == 1) && (compareDoubles(y, x) == -1));
}

bool isInYellow(double x, double y) {
	return ((compareDoubles(x, 0) == 1) && (compareDoubles(x, 2.828) == -1) && (compareDoubles(y, x) == -1));
}

void isInTheShapeController() {
	double x, y;
	std::cin >> x;
	std::cin >> y;
	if ((compareDoubles(x, -2) == 1) && (compareDoubles(x, 2) == -1) &&
		(compareDoubles(y, -7) == 1) && (compareDoubles(y, -6) == -1)) {
		std::cout << "is in the rectangle";
	}
	else {


		if (compareDoubles((x * x) + (y * y), 16) == -1) {
			if (isInPink(x, y)) { std::cout << "is in Pink"; }
			else if (isInRed(x, y)) { std::cout << "is in Red"; }
			else if (isInGreen(x, y)) { std::cout << "is in Green"; }
			else if (isInBlue(x, y)) { std::cout << "is in Blue"; }
			else if (isInYellow(x, y)) { std::cout << "is in Yellow"; }
			else if (isInPurple(x)) { std::cout << "is in Purple"; }
			else { std::cout << "is in the circle but it isn't in any color"; }
		}
		else {
			std::cout << "is not in any shape";
		}
	}

}
//end zad 0


//zad1
bool isEven(int n) {
	return !(n % 2);
}

void oddOrEvenFunctionController() {

	int x;
	std::cin >> x;
	for (int i = 2; i <= 35; i++)
	{
		if (isEven(x)) {
			x /= 2;
		}
		else {
			x = (3 * x) + 1;
		}
	}
	std::cout << x;

}
//end zad 1


//zad 2
void marmaladeFactoryController() {
	int blueberriesCounter = 0;
	int peachCounter = 0;
	int rosehipCounter = 0;

	int n;
	std::cin >> n;

	int countryCode = 0;
	int jamCode = 0;
	int fourDigitsToCheck = 0;
	int controlNumber = 0;
	while (n > 0) {
		for (int i = 1; i <= 3; i++)
		{
			std::cin >> countryCode;
			n--;
		}

		for (int i = 1; i <= 4; i++)
		{

			std::cin >> jamCode;
			fourDigitsToCheck = (fourDigitsToCheck * 10) + jamCode;
			n--;
		}

		if (fourDigitsToCheck % 7 == 0) {
			blueberriesCounter++;
		}
		if (fourDigitsToCheck % 13 == 0) {
			peachCounter++;
		}
		if (fourDigitsToCheck % 17 == 0) {
			rosehipCounter++;
		}

		fourDigitsToCheck = 0;
		std::cin >> controlNumber;
		n--;
	}

	std::cout << "Blueberries marmalade: " << blueberriesCounter << std::endl;
	std::cout << "Peach marmalade : " << peachCounter << std::endl;
	std::cout << "Rosehip marmalade: " << rosehipCounter << std::endl;

}
//end zad 2


//zad 3
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int digitsCount(int n) {
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return count;
}

bool isNumberInteresting(int n) {

	int lastDigit = 0;
	int secondLastDigit = 0;
	int count = digitsCount(n);
	while (n != 0) {
		if (count == 1) return true;
		lastDigit = n % 10;
		n /= 10;
		secondLastDigit = n % 10;
		if ((lastDigit % 2) == (secondLastDigit % 2)) {
			return false;
		}

		count--;
	}

	return true;
}

void interestingController() {
	int a;
	int b;
	int sum = 0;
	std::cin >> a;
	std::cin >> b;

	if (a > b)  swap(a, b);

	for (int i = a; i <= b; i++) {
		if (isNumberInteresting(i))
			sum += i;
	}
	std::cout << sum;
}
//end zad 3


//zad 4
bool containsDigit(const int arr[], int num) {

	for (unsigned i = 0; i < DIGITS_COUNT; i++)
	{
		if (arr[i] == num) {
			return true;
		}
	}
	return false;
}

void generate(int arr[]) {
	srand(time(NULL));
	int n = 0;
	int number = 0;

	while (n != DIGITS_COUNT)
	{
		number = (rand() % 9) + 1;
		if (!containsDigit(arr, number)) {
			arr[n++] = number;
		}
	}


}

void convertToArray(int arr[],int number) {
	for (int i = DIGITS_COUNT-1; i >= 0; i--)
	{
		arr[i] = number % 10;
		number /= 10;
	}
}

bool onlyDiffrentDigits(int number) {
	int arr[DIGITS_COUNT];
	convertToArray(arr, number);
	for (unsigned i = 0; i < DIGITS_COUNT; i++)
	{
		for (unsigned j = i + 1; j < DIGITS_COUNT; j++)
		{
			if (arr[i] == arr[j])return false;
		}
	}
	return true;
}

bool containsZero(int number) {
	while (number != 0)
	{
		int last = number % 10;
		number /= 10;
		if (last == 0)return false;
	}
	return true;
}

void userInput(int arr[]) {
	int number;
	std::cin >> number;

	while (digitsCount(number) != DIGITS_COUNT || !onlyDiffrentDigits(number) || !containsZero(number))
	{
		std::cout << "Please enter a valid number with 4 diffrent digts! Zeros are not allowed!" << std::endl;
		std::cin >> number;

	}

	convertToArray(arr, number);

}

int getBulls(const int numberToGuess[], const int userNumber[]) {
	int count = 0;
	for (unsigned i = 0; i < DIGITS_COUNT; i++)
	{
		if (numberToGuess[i] == userNumber[i])
			count++;
	}
	return count;
}

int getCows(const int numberToGuess[], const int userNumber[], int bulls) {
	int count = 0;
	for (unsigned i = 0; i < DIGITS_COUNT; i++)
	{
		if (containsDigit(numberToGuess, userNumber[i]))
			count++;
	}
	return count - bulls;
}

void getBullsAndCows(const int numberToGuess[], const int userNumber[], int& bulls, int& cows) {
	bulls = getBulls(numberToGuess, userNumber);
	cows = getCows(numberToGuess, userNumber, bulls) ;
}

void printArr(int arr[]) {
	for (unsigned i = 0; i < DIGITS_COUNT; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

void bullsAndCowsController() {

	int numberToGuess[DIGITS_COUNT];

	generate(numberToGuess);

	int bulls = 0;
	int cows = 0;

	int userNumber[DIGITS_COUNT];

	for (unsigned i = 0; i < NUMBER_OF_GUESSES; i++)
	{
		userInput(userNumber);

		getBullsAndCows(numberToGuess, userNumber, bulls, cows);

		if (bulls == 4) {
			std::cout << "Congratulations, you guessed the number! The number was: ";
			printArr(numberToGuess);
			return;
		}
		std::cout << "bulls: " << bulls << " cows: " << cows << std::endl;
	}

	std::cout << "Sorry, you are out of guesses. The number was: ";
	printArr(numberToGuess);
}
//end zad 4


int main() {
	//isInTheShapeController();				//zad 0
	//oddOrEvenFunctionController();		//zad 1
	//marmaladeFactoryController();			//zad 2
	//interestingController();				//zad 3
	//bullsAndCowsController();				//zad 4


}
