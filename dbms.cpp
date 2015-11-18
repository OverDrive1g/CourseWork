#include "DBMS.h"

#include <algorithm>
#include <iostream>
#include "function.h"

using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;

void DBMS::reading(){
	std::string buff;

	ifstream finEmpl("employees.txt");
	finEmpl >> buff;
	while (buff[0] != 'E'){
		addEmpl(buff);
		finEmpl >> buff;
	}
	finEmpl.close();

	ifstream finHB("handbook.txt");
	finHB >> buff;
	while (buff[0] != 'E'){
		addHB(buff);
		finHB >> buff;
	}
	finHB.close();
}

void DBMS::recording(){
	std::string buff;
	ofstream foutEmpl("employees.txt");
	for (const auto &employee : empl) {
		buff += intToString(employee.id) + ":";
		buff += employee.secName + ":";
		buff += intToString(employee.codePosition) + ":";
		buff += employee.subdivision + ":";
		buff += intToString(employee.hoursWorked);
		foutEmpl << buff << "\n";
		buff = "";
	}
	foutEmpl << "END";
	ofstream foutHb("handbook.txt");
	for (const auto &jobTile : hb) {
		buff += intToString(jobTile.id) + ":";
		buff += jobTile.jobTitle + ":";
		buff += floatToString(jobTile.salary);
		foutHb << buff << "\n";
		buff = "";
	}
	foutHb << "END";
}

void DBMS::addEmpl(const std::string &record){

	std::string	ID;
	std::string	secName;
	std::string	codePosition;
	std::string	subdivision;
	std::string hoursWorked;

	int k = 0;
	int j = 0;

	for (size_t i = 0; i < record.size(); i++){
		if (record[i] == ':') k++;
		else if (k == 0) {
			ID += record[i];
		}
		else if (k == 1) {
			secName += record[i];
		}
		else if (k == 2) {
			codePosition += record[i];
		}
		else if (k == 3) {
			subdivision += record[i];
		}
		else if (k == 4) {
			hoursWorked += record[i];
		}
	}
	employee newEmpl(std::stoi(ID), secName, std::stoi(codePosition), subdivision, std::stoi(hoursWorked));
	empl.push_back(newEmpl);
}

void DBMS::addHB(const std::string &record){

	std::string ID;
	std::string	jobTitle;
	std::string	Salary;

	int k = 0;

	for (size_t i = 0; i < record.size(); i++){

		if (record[i] == ':') k++;
		else if (k == 0) {
			ID += record[i];
		}
		else if (k == 1) {
			jobTitle += record[i];
		}
		else if (k == 2) {
			Salary += record[i];
		}
	}
	jobInfo newJobInfo(std::stoi(ID), jobTitle, std::stof(Salary));
	hb.push_back(newJobInfo);
}

void DBMS::printEmpl(){
	GotoXY(0,0);
	system("cls");
	for(const auto &employee : empl) { print(employee);}
	system("pause");
	system("cls");
}

void DBMS::addEmpl() {
	system("cls");
	GotoXY(0,0);
	std::string	secName;
	unsigned int codePosition;
	std::string	subdivision;
	unsigned int hoursWorked;

	cout << "Введите имя: ";
	cin >> secName;
	cout << "Введите код должности: ";
	cin >> codePosition;
	cout << "Ввеите подраздеение: ";
	cin >> subdivision;
	cout << "Введите кол-во отработанных часов: ";
	cin >> hoursWorked;
	if (empl.empty()) {
		employee newEmpl(0, secName, codePosition, subdivision, hoursWorked);
		empl.push_back(newEmpl);
	}
	else{
		employee newEmpl(empl.back().id+1, secName, codePosition, subdivision, hoursWorked);
		empl.push_back(newEmpl);
	}
	system("cls");
}

void DBMS::deleteEmpl(){
	unsigned int id = 0;
	cout << "Введите id";
	cin >> id;
	auto equal_to_our_id = [=](const employee &e) {return e.id == id;};
	std::remove_if(empl.begin(), empl.end(), equal_to_our_id);
}

void DBMS::updateEmpl(){
	std::string	secName;
	unsigned int codePosition;
	std::string	subdivision;
	unsigned int hoursWorked;

	unsigned int id = 0;
	cout << "Введите id";
	cin >> id;

	cout << "Введите измененное имя: ";
	cin >> secName;
	cout << "Введите измененный код должности: ";
	cin >> codePosition;
	cout << "Введите измененное подразделение: ";
	cin >> subdivision;
	cout << "Введите кол-во отработанных часов: ";
	cin >> hoursWorked;
	system("cls");

	employee newEmployee(id, secName, codePosition, subdivision, hoursWorked);
	auto equal_to_our_id = [=](const employee &e) {return e.id == id;};
	auto old_employee = std::find_if(empl.begin(), empl.end(), equal_to_our_id);

	if (old_employee!=empl.end()){
		*old_employee = newEmployee;
		cout << "Изменение успешно!" << endl;
	}
	else {
		cout << "Изменение не удалось!" << endl;
	}
}

void DBMS::printHB(){
	for (const auto &jobTile : hb) { print(jobTile); }
}

void DBMS::addHB(){
	std::string	jobTitle;
	float salary;

	cout << "Введите наименование профессии: ";
	cin >> jobTitle;
	cout << "Введите З/П в час: ";
	cin >> salary;
	system("cls");
	if (hb.empty()) {
		jobInfo newJobInfo(0, jobTitle, salary);
		hb.push_back(newJobInfo);
	}
	else {
		jobInfo newJobInfo(hb.back().id + 1, jobTitle, salary);
		hb.push_back(newJobInfo);
	}
	
}

void DBMS::deleteHB(){
	unsigned int id = 0;
	cout << "Введите id";
	cin >> id;

	auto equal_to_our_id = [=](const jobInfo &e) {return e.id == id;};
	std::remove_if(hb.begin(), hb.end(), equal_to_our_id);
}

void DBMS::updateHB(){

	std::string	jobTitle;
	float	Salary;

	unsigned int id = 0;
	cout << "Введите id";
	cin >> id;

	cout << "Введите название профессии: ";
	cin >> jobTitle;
	cout << "Введите З/П в час: ";
	cin >> Salary;
	jobInfo newJobInfo(id,jobTitle, Salary);
	auto equal_to_our_id = [=](const jobInfo &e) {return e.id == id;};
	auto old_jobInfo = std::find_if(hb.begin(), hb.end(), equal_to_our_id);

	if (old_jobInfo != hb.end()) {
		*old_jobInfo = newJobInfo;
		cout << "Изменение успешно!" << endl;
	}
	else {
		cout << "Изменение не удалось!" << endl;
	}
}