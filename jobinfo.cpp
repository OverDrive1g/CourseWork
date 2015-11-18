#include "jobinfo.h"
#include <iostream>

using std::cout;

void print(const jobInfo & record){
	cout << record;
}

std::ostream& operator << (std::ostream &o, const jobInfo& record) {
	o << "+------------------------------------------------------------------------------+";
	o << "ID:                     " << record.id << "\n";
	o << "������������ ���������: " << record.jobTitle << "\n";
	o << "�/�:                    " << record.salary << "\n";
	o << "+------------------------------------------------------------------------------+";
	return o;
}
