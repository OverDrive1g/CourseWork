//
// Created by on 20.09.15.
// Copyright (c) 2015 Бедило Владислав. All rights reserved.
//
// Создайте программу введения базы данных "Сотрудники" научного учреждения "Прогресс". База данных состоит из двух файлов
// Файл №1 - список сотрудников: фамилия, код должности, подразделение. Файл №2 - справочник: наименование должности,
// зарплата за один час работы. Колличество отработанных часов для каждого сотрудника вводится с клавиатуры компьютера.
// 	 •ввод информации о сотрудниках и запись ее на диск?
//   •удаление ненужной информации с файлов на диске
//	 •корректирование записей базы данных?
//	  вывод расчетной ведомости для каждого подразделения
//	  сортировка по алфоиту в разрезе подразделения
// 	  расчет суммы выплаты заработной платы по институту в целом
//
// TODO стаж и все что с ним связано
//
//
//
// TODO for refactoring перименовать поля во всех классах!!!!
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

void showMenu(int iItem) {
	system("cls");
	cout << (iItem == 1 ? ">" : " ") << "Simple text" << endl;
	cout << (iItem == 2 ? ">" : " ") << "Simple text" << endl;
	cout << (iItem == 3 ? ">" : " ") << "Simple text" << endl;
	cout << (iItem == 4 ? ">" : " ") << "Simple text" << endl;
}

int main(){
	system("title DBMS");
	SetConsoleCP(1251); // настраиваем кодировку консоли (ввод)
	SetConsoleOutputCP(1251); // (вывод)
	setlocale(LC_ALL, ".1251");

	//a.reading();
	int iItem = 1;//Отвечает какой пункт меню активен в данный момент
	int nLast = 5;//Отвечает какой индекс у последнего пункта меню
	showMenu(iItem);
	while (TRUE)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (0 < iItem - 1)
				iItem = iItem - 1;
			else
				iItem = nLast;
			showMenu(iItem);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (iItem < nLast)
				iItem = iItem + 1;
			else
				iItem = 1;
			showMenu(iItem);
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			showMenu(iItem);
			switch (iItem)
			{
			case 1:
				printf("Run 1-st item of menu\n");
				break;
			case 2:
				printf("Run 2-nd item of menu\n");
				break;
			case 3:
				printf("Run 3-rd item of menu\n");
				break;
			case 4:
				printf("Run 4-th item of menu\n");
				break;
			case 5:
				printf("Run 5-th item of menu\n");
				break;
			}
		}
	}

	
	system("pause");
}