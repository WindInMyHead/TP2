#pragma once
#include "MyException.h"
#include "List.h"
#include "FileManager.h"

using namespace std;

int Menu(List list) {
	FileManager FILE;
	int v = 0, menu = 1;
	while (menu) {
		cout << "====Main menu====" << endl;
		cout << "1. Add family member" << endl;
		cout << "2. Save to file" << endl;
		cout << "3. Read from file" << endl;
		cout << "4. Print familly tree" << endl;
		cout << "5. Edit data" << endl;
		cout << "6. Delete familly member" << endl;
		cout << "7. Remove similar objects from the list" << endl;
		cout << "0. Exit to Windows " << endl;
		cout << ">>> ";
		cin >> v;

		while (v < 0 || v > 7 || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect entered, retry" << endl;
			cin >> v;
		}

		try {
			switch (v) {
			case 1:
			{
				++list;
				break;
			}

			case 2:
			{
				FILE.Save(list);
				break;
			}

			case 3:
			{
				FILE.Read(list);
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

			case 7:
			{
				list.RemoveSimilar();
				break;
			}

			case 0:
			{
				menu = 0;
			}

			}
		}
		catch (MyException& exception) {
			cout << exception.what() << endl;
			return Menu(list);
		}
	}
	return 0;
}

//3
//Korotkin Anton Sergeevich
//124
//124
//214
//241
//241
//214
//Kuznetsova Irina Andreevna
//09.02.1999
//22
//Mint Natalya Petrovna, Kuznetsov Andrey
//Korotkin Anton
//no
//no
//Korotkin Anton Sergeevich
//09.01.2002
//19
//korotkina natalya nikolaevna, Korotkin sergey Aleksandrovich
//Kuznetsova Irina Andreevna
//no
//no
