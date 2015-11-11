#ifndef JOBINFO_H
#define JOBINFO_H

#include <string>

struct jobInfo {
	unsigned int			id;
	std::string				jobTitle;
	float					salary;

	jobInfo(unsigned int id, const std::string &jobTitle, float salary) :id(id), jobTitle(jobTitle), salary(salary) {}
};
void print(const jobInfo &record);

std::ostream& operator << (std::ostream &o, const jobInfo& record);

#endif