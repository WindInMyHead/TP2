#pragma once
#include<iostream>
#include<string>
#include"List.h"

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
			list.SaveToFile();
			break;
		}
		case 3:
		{
			list.ReadFromFile();
			break;
		}
		case 4:
		{
			list.Print();
			break;
		}
		case 5:
		{
			list.Edit();
			break;
		}
		case 6:
		{
			list.Del();
			break;
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