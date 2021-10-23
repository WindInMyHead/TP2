#pragma once
#include<iostream>
#include<string>
#include"FamillyMember.h"

using namespace std;

int Menu() {
	int v = 0, menu = 1;
	while (menu) {
		cout << "===Main menu====" << endl;
		cout << "1.Add family member" << endl;
		cout << "2.Read from file" << endl;
		cout << "3.Print familly tree" << endl;
		cout << "4.Edit data" << endl;
		cout << "0.Exit to Windows " << endl;
		cin >> v;
		switch (v) {
		case 1:
		{
			string name, bDay, age, parentName[2], parentData, spousName, spousData, * childName, childData, deathDay;
			int childCn = 0;
			cout << "===Add familly member====" << endl;
			cout << "!Press ENTER if there is no data !" << endl;
			//имя
			cout << "Enter name(Full name): ";
			cin.ignore();
			getline(cin, name);
			//дата рождения
			cout << "Enter birth date: ";
			cin >> bDay;
			//возраст
			cout << "Enter age: ";
			cin >> age;
			//имя мамы
			cout << "Enter mom`s name: ";
			cin.ignore();
			getline(cin, parentName[0]);
			//имя отца
			cout << "Enter dad`s name: ";
			getline(cin, parentName[1]);
			//информация о родителях
			cout << "Enter other parents data: ";
			getline(cin, parentData);
			//имя супруга(и)
			cout << "Enter the name of the spous: ";
			getline(cin, spousName);
			//информация о супруге
			cout << "Enter data about spous: ";
			getline(cin, spousData);
			//количество детей
			cout << "Enter child quantity: ";
			cin >> childCn;
			//имена детей
			childName = new string[childCn];
			for (int i = 0; i < childCn; i++) {
				cout << "Enter the name of the " << i << " child: ";
				cin.ignore();
				getline(cin, childName[i]);
			}
			//информация о детях
			cout << "Enter data about child: ";
			cin.ignore();
			getline(cin, childData);
			//дата смерти
			cout << "Enter death date: ";
			cin >> deathDay;

			FamillyMember son(name, bDay, age, parentName, parentData, spousName, spousData, deathDay);
			son.SaveToFile();
		}
		case 2:
		{

		}
		case 0:
		{
			return 0;
		}

		}
	}
}