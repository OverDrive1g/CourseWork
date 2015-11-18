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
	o << "|Имя:                       " << empl.secName << "\n";
	o << "|Код должности:             " << empl.codePosition << "\n";
	o << "|Подразделение:             " << empl.subdivision << "\n";
	o << "|Кол-во отработанных часов: " << empl.hoursWorked << "\n";
	o << "+------------------------------------------------------------------------------+";
	return o;
}
