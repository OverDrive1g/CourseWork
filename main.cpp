//
// Created by on 20.09.15.
// Copyright (c) 2015 ������ ���������. All rights reserved.
//
// �������� ��������� �������� ���� ������ "����������" �������� ���������� "��������". ���� ������ ������� �� ���� ������
// ���� �1 - ������ �����������: �������, ��� ���������, �������������. ���� �2 - ����������: ������������ ���������,
// �������� �� ���� ��� ������. ����������� ������������ ����� ��� ������� ���������� �������� � ���������� ����������.
// 	 ����� ���������� � ����������� � ������ �� �� ����
//   ��������� �������� ���������� � ������ �� �����
//	 ���������������� ������� ���� ������
//	  ����� ��������� ��������� ��� ������� �������������
//    ����� ���������������� ������ � ������� �������������
// 	  ������ ����� ������� ���������� ����� �� ��������� � �����
//

//
// TODO ������������ ���� �� ���� �������!!!!
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
	for (size_t i = 0; i < 25; i++) {
		GotoXY(2, i); cout << " ";
	}
	GotoXY(2, choice); cout << ">";
}

void pressEnter(int choice) {
	switch (choice) {
	case 1:
		a.printEmpl();
		break;

	case 2:
		a.printPayslip();
		break;

	case 3:
		a.addEmpl();
		break;

	case 4:
		a.deleteEmpl();
		break;

	case 5:
		a.updateEmpl();
		break;

	case 6:
		a.printHb();
		break;

	case 7:
		a.addHb();
		break;

	case 8:
		a.deleteHb();
		break;

	case 9:
		a.updateHb();
		break;

	case 10:
		a.recording();
		exit(0);
		break;
	default:
		break;
	}
}

int main() {
	system("title DBMS");
	SetConsoleCP(1251); // ����������� ��������� ������� (����)
	SetConsoleOutputCP(1251); // (�����)
	setlocale(LC_ALL, ".1251");

	a.reading();

	short choice = 1;
	short maxChoice = 10;
	while (true) {
		system("cls");
		GotoXY(3, 1); cout << "����� ���� �����������" << endl;
		GotoXY(3, 2); cout << "����� ����������� �� �������������" << endl;
		GotoXY(3, 3); cout << "�������� ������ ����������" << endl;
		GotoXY(3, 4); cout << "������� ������ ����������" << endl;
		GotoXY(3, 5); cout << "�������� ������ ����������" << endl;

		GotoXY(3, 6); cout << "����� ���� ���������" << endl;
		GotoXY(3, 7); cout << "�������� ������ ���������" << endl;
		GotoXY(3, 8); cout << "������� ������ ���������" << endl;
		GotoXY(3, 9); cout << "�������� ������ ���������" << endl;

		GotoXY(3, 10); cout << "�����" << endl;
		drawMenu(choice);
		switch (_getch()) {
		case 56: 
			if(choice - 1 > 0)
				choice--;
			else choice = maxChoice;
			break;
		case 50: 
			if (choice < maxChoice) choice++;
			else choice = 1;
			break;
		case 13: pressEnter(choice);
			break;
		}
	}
	system("pause");
}