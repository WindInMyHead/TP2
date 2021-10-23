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
		cout << "2.Print familly tree" << endl;
		cout << "3.Edit data" << endl;
		cout << "0.Exit to Windows " << endl;
		cin >> v;
		switch (v) {
		case 1:
		{
			string name, bDay, age, *parentName, parentData, * spousName, spousData, * childName, childData, deathDay;
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
			parentName = new string[2];
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
			spousName = new string[1];
			cout << "Enter the name of the spous: ";
			getline(cin, spousName[0]);
			//информация о супруге
			cout << "Enter data about spous: ";
			getline(cin, spousData);
			//количество детей
			cout << "Enter child quantity: ";
			cin >> childCn;
			//имена детей
			childName = new string[childCn];
			cin.ignore();
			for (int i = 0; i < childCn; i++) {
				cout << "Enter the name of the " << i+1 << " child: ";
				getline(cin, childName[i]);
			}
			//информация о детях
			cout << "Enter data about child: ";
			cin.ignore();
			getline(cin, childData);
			//дата смерти
			cout << "Enter death date: ";
			cin >> deathDay;

			FamillyMember son(name, bDay, age, parentName, parentData, spousName, spousData, deathDay, childName, childData, childCn);
			son.SaveToFile();
		}
		case 2:
		{
			string nameMemb;
			cout << "Entered name the familly member";
			cin.ignore();
			getline(cin, nameMemb);
			FamillyMember memb(nameMemb);

		}
		case 0:
		{
			return 0;
		}

		}
	}
}