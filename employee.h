#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

struct employee {
	unsigned int			id = 0;
	std::string				secName;
	unsigned int			codePosition = 0;
	std::string				subdivision ;
	unsigned int 			hoursWorked = 0;

	employee(unsigned int id, const std::string &secName, unsigned int codePosition,
		const std::string &subdivision) :id(id), secName(secName), codePosition(codePosition),
		subdivision(subdivision) {}

};
void print(const employee &employee);

std::ostream& operator << (std::ostream &o, const employee& empl);


#endif