#pragma once
#include <string>
#include "MyException.h"
#include "List.h"

using namespace std;

int Menu(List list) {
	int v = 0, menu = 1;
	while (menu) {
		cout << "===Main menu====" << endl;
		cout << "1.Add family member" << endl;
		cout << "2.Save to file" << endl;
		cout << "3.Read from file" << endl;
		cout << "4.Print familly tree" << endl;
		cout << "5.Edit data" << endl;
		cout << "6.Delete familly member" << endl;
		cout << "0.Exit to Windows " << endl;
		cin >> v;
		switch (v) {
		case 1:
		{
			++list;
			break;
		}
		case 2:
		{
			try {
				list.SaveToFile();
				break;
			}
			catch (MyException& exception) {
				cout << exception.what() << endl;
				return Menu(list);
			}
		}
		case 3:
		{
			try {
				list.ReadFromFile();
				break;
			}
			catch (MyException& exception) {
				cout << exception.what() << endl;
				return Menu(list);
			}
		}
		case 4:
		{
			try {
				list.Print();
				break;
			}
			catch (MyException& exception) {
				cout << exception.what() << endl;
				return Menu(list);
			}
		}
		case 5:
		{
			try {
				list.Edit();
				break;
			}
			catch (MyException& exception) {
				cout << exception.what() << endl;
				return Menu(list);
			}
		}
		case 6:
		{
			try {
				list.Del();
				break;
			}
			catch (MyException& exception) {
				cout << exception.what() << endl;
				return Menu(list);
			}
		}
		case 0:
		{
			menu = 0;
		}

		}
	}
	return 0;
}

//Korotkin Anton
//09.01.2002
//19
//korotkina natalya nikolaevna, Korotkin sergey Aleksandrovich
//Kuznetsova Irina Andreevna
//no
//no