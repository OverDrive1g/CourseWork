#include "employee.h"

#include <iostream>
#include "function.h"

using std::cout;

void print(const employee &employee) {
	cout << employee;
}

std::ostream& operator << (std::ostream &o, const employee& empl) {
	o << "+------------------------------------------------------------------------------+";
	o << "|ID:                        " << empl.id << "\n";
	o << "|���:                       " << empl.secName << "\n";
	o << "|��� ���������:             " << empl.codePosition << "\n";
	o << "|�������������:             " << empl.subdivision << "\n";
	o << "|���-�� ������������ �����: " << empl.hoursWorked << "\n";
	o << "+------------------------------------------------------------------------------+";
	return o;
}
