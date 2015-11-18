#ifndef DBMS_H
#define DBMS_H

#include <fstream>
#include <vector>
#include "employee.h"
#include "jobinfo.h"

class DBMS{
private:
	std::vector<employee>		empl;
	std::vector<jobInfo>		hb;
	void						addEmpl(const std::string & word);
	void						addHb(const std::string &word);
public:

	void						reading();
	void						recording();

	void						printEmpl();
	void						addEmpl();
	void						deleteEmpl();
	void						updateEmpl();

	void						printHb();
	void						addHb();
	void						deleteHb();
	void						updateHb();
};

#endif