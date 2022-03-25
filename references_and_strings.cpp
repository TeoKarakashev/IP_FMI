#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
bool isPalindrome(const char* str) {
	unsigned strLength = strlen(str);
	for (unsigned i = 0; i < strLength/2; i++)
	{
		if (str[i] != str[strLength - i - 1])
			return false;
	}
	return true;
}

void toUpper(char* str) {
	unsigned strLength = strlen(str);

	for (unsigned i = 0; i < strLength; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 32;
		}
	}
}

void getAllWords(const char* str) {
	unsigned strLength = strlen(str);
	for (unsigned i = 0; i < strLength; i++)
	{
		if (str[i] != ' ') {
			std::cout << str[i];
		}
		else {
			std::cout << std::endl;
		}
	}
}

void clearUnnecessarySpaces(char* str) {
	unsigned strLength = strlen(str);
	unsigned tempIndex = 0;
	bool isSpace = false;
	char temp[100];
	for (unsigned i = 0 ; i < strLength; i++)
	{
		if (str[i] != ' ') {
			temp[tempIndex++] = str[i];
			isSpace = false;
		}
		else if(!isSpace){
			temp[tempIndex++] = str[i];
			isSpace = true;
		}		
	}
	temp[tempIndex] = '\0';
	strcpy(str, temp);
}

void encrypt(char& c, int offset) {
	if (offset < 0) offset = 26 + offset % 26;
	if (c >= 'a' && c <= 'z') {
		c = (std::abs( ((c - 'a') + offset) % 26)) + 'a';
	}
	else if (c >= 'A' && c <= 'Z') {
		c = (std::abs(((c - 'A') + offset) % 26)) + 'A';
	}
}

void crypt(char* str, int offset) {
	unsigned strLength = strlen(str);
	for (unsigned i = 0; i < strLength; i++)
	{
		encrypt(str[i], offset);
	}
}

void decrypt(char* str, int offset) {
	crypt(str, -offset);
}



int main() {
	char str[] = "Lorem zipsum dolor sit amet";

	

}