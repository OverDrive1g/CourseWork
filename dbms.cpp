#include "DBMS.h"

#include <algorithm>
#include <iostream>
#include <conio.h>
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

	ifstream finHb("handbook.txt");
	finHb >> buff;
	while (buff[0] != 'E'){
		addHb(buff);
		finHb >> buff;
	}
	finHb.close();
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

void DBMS::addHb(const std::string &record){

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

	employee newEmpl = creationEmployee();
	
	if (empl.empty()) {
		newEmpl.id = 0;
		empl.push_back(newEmpl);
	}
	else{
		newEmpl.id = empl.back().id + 1;
		empl.push_back(newEmpl);
	}
	system("cls");
}

void DBMS::deleteEmpl(){
	system("cls");

	std::vector<employee>::iterator i = empl.begin();
	
	int key;

	while (true){
		system("cls");
		cout << i;
		cout << "Управление: \n <- предыдуща запись\n -> следущая запись\n Enter Удалить\n Esc Вернуться в меню";
		key = _getch();
		if (key == 13) {
			empl.erase(i);
			continue;
		}
		else if (key == 52) {
			if (i > empl.begin()) i--;
			else continue;
		}
		else if (key == 54) {
			if (i < empl.end()-1) i++;
			else continue;
		}
		else if (key == 27) {
			return;
		}
	}
}

void DBMS::updateEmpl() {
	system("cls");

	std::vector<employee>::iterator i = empl.begin();

	int key;

	while (true) {
		system("cls");
		cout << i;
		cout << "Управление: \n <- предыдуща запись\n -> следущая запись\n Enter Выбрать\n Esc Вернуться в меню";
		key = _getch();
		if (key == 13) {
			system("cls");
			employee newEmployee = creationEmployee();
			system("cls");

			newEmployee.id = i->id;

			auto equal_to_our_id = [=](const employee &e) {return e.id == i->id;};
			auto old_employee = std::find_if(empl.begin(), empl.end(), equal_to_our_id);

			if (old_employee != empl.end()) {
				*old_employee = newEmployee;
				cout << "Изменение успешно!" << endl;
			}
			else {
				cout << "Изменение не удалось!" << endl;
			}

			continue;
		}
		else if (key == 52) {
			if (i > empl.begin()) i--;
			else continue;
		}
		else if (key == 54) {
			if (i < empl.end() - 1) i++;
			else continue;
		}
		else if (key == 27) {
			return;
		}

	}
}

void DBMS::printHb(){
	system("cls");
	for (const auto &jobTile : hb) { print(jobTile); }
	system("pause");
}

void DBMS::addHb(){
	system("cls");
	
	jobInfo newJobInfo = creationJobInfo();

	system("cls");
	if (hb.empty()) {
		newJobInfo.id = 0;
		hb.push_back(newJobInfo);
	}
	else {
		newJobInfo.id = hb.back().id + 1;
		hb.push_back(newJobInfo);
	}
	
}

void DBMS::deleteHb(){
	system("cls");
	
	std::vector<jobInfo>::iterator i = hb.begin();

	int key;

	while (true) {
		system("cls");
		cout << i;
		cout << "Управление: \n <- предыдуща запись\n -> следущая запись\n Enter Удалить\n Esc Вернуться в меню";
		key = _getch();
		if (key == 13) {
			hb.erase(i);
			continue;
		}
		else if (key == 52) {
			if (i > hb.begin()) i--;
			else continue;
		}
		else if (key == 54) {
			if (i < hb.end() - 1) i++;
			else continue;
		}
		else if (key == 27) {
			return;
		}
	}
}

void DBMS::updateHb(){
	system("cls");

	std::vector<jobInfo>::iterator i = hb.begin();

	int key;

	while (true) {
		system("cls");
		cout << i;
		cout << "Управление: \n <- предыдуща запись\n -> следущая запись\n Enter Выбрать\n Esc Вернуться в меню";
		key = _getch();
		if (key == 13) {
			system("cls");
			
			jobInfo newJobInfo = creationJobInfo();

			newJobInfo.id = i->id;

			auto equal_to_our_id = [=](const jobInfo &e) {return e.id == i->id;};
			auto old_jobInfo = std::find_if(hb.begin(), hb.end(), equal_to_our_id);

			if (old_jobInfo != hb.end()) {
				*old_jobInfo = newJobInfo;
				cout << "Изменение успешно!" << endl;
			}
			else {
				cout << "Изменение не удалось!" << endl;
			}

			continue;
		}
		else if (key == 52) {
			if (i > hb.begin()) i--;
			else continue;
		}
		else if (key == 54) {
			if (i < hb.end() - 1) i++;
			else continue;
		}
		else if (key == 27) {
			return;
		}
	}
}