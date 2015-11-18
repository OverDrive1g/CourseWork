#include "function.h"
#include <sstream>
#include <Windows.h>
#include <iostream>

using std::cout;
using std::cin;

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

employee creationEmployee(){
	std::string	secName;
	unsigned int codePosition;
	std::string	subdivision;
	unsigned int hoursWorked;

	cout << "Введите имя: ";
	cin >> secName;
	cout << "Введите код должности: ";
	cin >> codePosition;
	cout << "Ввеите подраздеение: ";
	cin >> subdivision;
	cout << "Введите кол-во отработанных часов: ";
	cin >> hoursWorked;
	employee newEmpl(0, secName, codePosition, subdivision, hoursWorked);
	return newEmpl;
}

jobInfo creationJobInfo(){
	std::string	jobTitle;
	float salary;

	cout << "Введите наименование профессии: ";
	cin >> jobTitle;
	cout << "Введите З/П в час: ";
	cin >> salary;

	jobInfo newJobInfo(0, jobTitle, salary);

	return newJobInfo;
}

std::ostream & operator<<(std::ostream & o, const std::vector<employee>::iterator& empl){
	o << "+------------------------------------------------------------------------------+";
	o << "|ID:                        " << empl->id << "\n";
	o << "|Имя:                       " << empl->secName << "\n";
	o << "|Код должности:             " << empl->codePosition << "\n";
	o << "|Подразделение:             " << empl->subdivision << "\n";
	o << "|Кол-во отработанных часов: " << empl->hoursWorked << "\n";
	o << "+------------------------------------------------------------------------------+";
	return o;
}

std::ostream& operator << (std::ostream &o, const std::vector<jobInfo>::iterator& record) {
	o << "+------------------------------------------------------------------------------+";
	o << "ID:                     " << record->id << "\n";
	o << "Наименование должности: " << record->jobTitle << "\n";
	o << "З/П:                    " << record->salary << "\n";
	o << "+------------------------------------------------------------------------------+";
	
	return o;
}