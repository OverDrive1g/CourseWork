//
// Created by on 20.09.15.
// Copyright (c) 2015 ������ ���������. All rights reserved.
//
// �������� ��������� �������� ���� ������ "����������" �������� ���������� "��������". ���� ������ ������� �� ���� ������
// ���� �1 - ������ �����������: �������, ��� ���������, �������������. ���� �2 - ����������: ������������ ���������,
// �������� �� ���� ��� ������. ����������� ������������ ����� ��� ������� ���������� �������� � ���������� ����������.
// 	 ����� ���������� � ����������� � ������ �� �� ����?
//   ��������� �������� ���������� � ������ �� �����
//	 ���������������� ������� ���� ������?
//	  ����� ��������� ��������� ��� ������� �������������
//	  ���������� �� ������� � ������� �������������
// 	  ������ ����� ������� ���������� ����� �� ��������� � �����
//
// TODO ���� � ��� ��� � ��� �������
//
//
//
// TODO for refactoring ������������ ���� �� ���� �������!!!!
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
	SetConsoleCP(1251); // ����������� ��������� ������� (����)
	SetConsoleOutputCP(1251); // (�����)
	setlocale(LC_ALL, ".1251");

	//a.reading();
	int iItem = 1;//�������� ����� ����� ���� ������� � ������ ������
	int nLast = 5;//�������� ����� ������ � ���������� ������ ����
	showMenu(iItem);
	while (TRUE)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//�������� ������
			if (0 < iItem - 1)
				iItem = iItem - 1;
			else
				iItem = nLast;
			showMenu(iItem);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//�������� ������
			if (iItem < nLast)
				iItem = iItem + 1;
			else
				iItem = 1;
			showMenu(iItem);
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//�������� ������
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