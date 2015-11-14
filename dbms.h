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
	void						addHB(const std::string &word);
public:
	DBMS();

	void						reading();
	void						recording();

	void						printEmpl();
	void						addEmpl();
	void						deleteEmpl(unsigned int ID);
	void						updateEmpl(unsigned int ID);

	void						printHB();
	void						addHB();
	void						deleteHB(unsigned int ID);
	void						updateHB(unsigned int ID);

	auto getEndVec() {
		return empl.end();
	}
};

#endif