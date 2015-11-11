#include "employee.h"

#include <iostream>

using std::cout;
using std::endl;

void print(const employee &employee) {
	cout << employee;
}

std::ostream& operator << (std::ostream &o, const employee& empl) {

	o << "ID: " << empl.id << "\n";
	o << "Имя: " << empl.secName << "\n";
	o << "Код должности: " << empl.codePosition << "\n";
	o << "Подразделение: " << empl.subdivision << "\n";
	return o;
}
