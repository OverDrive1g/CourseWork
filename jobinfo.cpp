#include "jobinfo.h"
#include <iostream>

using std::cout;
using std::endl;

void print(const jobInfo & record){
	cout << record;
}

std::ostream& operator << (std::ostream &o, const jobInfo& record) {
	o << "ID: " << record.id << "\n";
	o << "Наименование должности: " << record.jobTitle << "\n";
	o << "З/П: " << record.salary << "\n";
	return o;
}
