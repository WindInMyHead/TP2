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
			//���
			cout << "Enter name(Full name): ";
			cin.ignore();
			getline(cin, name);
			//���� ��������
			cout << "Enter birth date: ";
			cin >> bDay;
			//�������
			cout << "Enter age: ";
			cin >> age;
			//��� ����
			parentName = new string[2];
			cout << "Enter mom`s name: ";
			cin.ignore();
			getline(cin, parentName[0]);
			//��� ����
			cout << "Enter dad`s name: ";
			getline(cin, parentName[1]);
			//���������� � ���������
			cout << "Enter other parents data: ";
			getline(cin, parentData);
			//��� �������(�)
			spousName = new string[1];
			cout << "Enter the name of the spous: ";
			getline(cin, spousName[0]);
			//���������� � �������
			cout << "Enter data about spous: ";
			getline(cin, spousData);
			//���������� �����
			cout << "Enter child quantity: ";
			cin >> childCn;
			//����� �����
			childName = new string[childCn];
			cin.ignore();
			for (int i = 0; i < childCn; i++) {
				cout << "Enter the name of the " << i+1 << " child: ";
				getline(cin, childName[i]);
			}
			//���������� � �����
			cout << "Enter data about child: ";
			cin.ignore();
			getline(cin, childData);
			//���� ������
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