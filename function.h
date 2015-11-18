#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <vector>
#include "employee.h"
#include "jobinfo.h"

std::string intToString(int);

std::string floatToString(float);

void SetColor(int text, int background);

void GotoXY(int X, int Y);

employee creationEmployee();

jobInfo creationJobInfo();

std::ostream& operator << (std::ostream &o, const std::vector<employee>::iterator& empl);

std::ostream& operator << (std::ostream &o, const std::vector<jobInfo>::iterator& record);

#endif