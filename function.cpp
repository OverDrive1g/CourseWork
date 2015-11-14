#include "function.h"
#include <sstream>
#include <Windows.h>

HANDLE hConsole, hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

std::string intToString(int num){
	std::string value;
	std::stringstream ss;
	ss << num;
	ss >> value;
	return value;
}

std::string floatToString(float num){
	std::string value;
	std::stringstream ss;
	ss << num;
	ss >> value;
	return value;
}

void SetColor(int text, int background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int X, int Y) {
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
