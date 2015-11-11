#include "employee.h"

#include <iostream>

using std::cout;
using std::endl;

void print(const employee &employee) {
	cout << employee;
}

std::ostream& operator << (std::ostream &o, const employee& empl) {

	o << "ID: " << empl.id << "\n";
	o << "���: " << empl.secName << "\n";
	o << "��� ���������: " << empl.codePosition << "\n";
	o << "�������������: " << empl.subdivision << "\n";
	return o;
}
