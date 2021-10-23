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

			string name, bDay, age, * parentName, parentData, spousName, spousData, * childName, childData, deathDay;
			int childCn = 0;
			parentName = new string[2];
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
			cout << "Enter mom`s name: ";
			cin.ignore();
			getline(cin, parentName[0]);
			//��� ����
			cout << "Enter dad`s name: ";
			cin.ignore();
			getline(cin, parentName[1]);
			//���������� � ���������
			cout << "Enter other parents data: ";
			cin.ignore();
			getline(cin, parentData);
			//��� �������(�)
			cout << "Enter the name of the spous: ";
			cin.ignore();
			getline(cin, spousName);
			//���������� � �������
			cout << "Enter data about spous: ";
			cin.ignore();
			getline(cin, spousData);
			//���������� �����
			cout << "Enter child quantity: ";
			cin >> childCn;
			//����� �����
			childName = new string[childCn];
			for (int i = 0; i < childCn; i++) {
				cout << "Enter the name of the " << i << " child: ";
				cin.ignore();
				getline(cin, childName[i]);
			}
			//���������� � �����
			cout << "Enter data about child: ";
			cin.ignore();
			getline(cin, childData);
			//���� ������
			cout << "Enter death date: ";
			cin >> deathDay;

			FamillyMember son(name, bDay, age, parentData, spousData, childData, deathDay);
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