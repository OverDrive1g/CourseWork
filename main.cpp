//
// Created by on 20.09.15.
// Copyright (c) 2015 Бедило Владислав. All rights reserved.
//
// Создайте программу введения базы данных "Сотрудники" научного учреждения "Прогресс". База данных состоит из двух файлов
// Файл №1 - список сотрудников: фамилия, код должности, подразделение. Файл №2 - справочник: наименование должности,
// зарплата за один час работы. Колличество отработанных часов для каждого сотрудника вводится с клавиатуры компьютера.
// 	 •ввод информации о сотрудниках и запись ее на диск?//   •удаление ненужной информации с файлов на диске
//	 •корректирование записей базы данных?//	 вывод расчетной ведомости для каждого подразделения
// 	расчет суммы выплаты заработной платы по институту в целом
//

//
// TODO перименовать поля во всех классах!!!!
//
#include <sstream>
#include <windows.h>
#include <iostream> 
#include <fstream>
#include <conio.h>
#include "DBMS.h"
#include "function.h"

using std::cin;
using std::cout;
using std::endl;

DBMS a;

enum ConsoleColor { Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15 };

void drawMenu(short choice) {
	for (size_t i = 0; i < 25; i++){
			GotoXY(2, i); cout << " ";
	}
	GotoXY(2, choice); cout << "+";
}

void pressEnter(int choice) {
	switch (choice){
		case 1: 
			a.printEmpl();
			break;
		case 2:
			a.addEmpl();
			break;
		case 3:
			a.deleteEmpl();
			break;
		case 4: 
			a.updateEmpl();
			break;
		case 5: 
			a.recording();
			exit(0);
			break;
		default:
			break;
		}
	}

int main(){
	system("title DBMS");
	SetConsoleCP(1251); // настраиваем кодировку консоли (ввод)
	SetConsoleOutputCP(1251); // (вывод)
	setlocale(LC_ALL, ".1251");

	a.reading();

	short choice = 1;
	while (true) {

	GotoXY(3, 1); cout << "Вывод всех сотрудников" << endl;
	GotoXY(3, 2); cout << "Добавить запись сотрудника" << endl;
	GotoXY(3, 3); cout << "Удалить запись сотрудника" << endl;
	GotoXY(3, 4); cout << "Изменить запись сотрудника" << endl;
	GotoXY(3, 5); cout << "Выход" << endl;
	drawMenu(choice);
	switch (_getch()) {
		case 56: choice--;
			break;
		case 50: choice++;
			break;
		case 13: pressEnter(choice);
			break;
		default:
			break;
		}
	}
	system("pause");
}