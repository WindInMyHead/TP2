#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class FamillyMember{
private:
	int id;
	int childCh;
	int *idParent;
	int *idChild;
	int *idSpous;
	string name;
	string bDay;
	string age;
	string parentData;
	string spousData;
	string childData;
	string deathDay;
public:
	FamillyMember(string name = NULL, string bDay = NULL, string age = NULL, string* parentName = NULL, string parentData = NULL, string* spousName = NULL,
		string spousData = NULL, string deathDay = NULL, string* childName = NULL, string childData = NULL, int childCn = 0);

	void SaveToFile();

	void SetName(string name);
	string GetName();

	void SetParentData(string data);
	string GetParentData();

	void SetSpousData(string data);
	string GetSpousData();

	void SetChildData(string data);
	string GetChildData();

	void SetBDay(string data);
	string GetBDay();

	void SetDeathDay(string data);
	string GetDeathDay();

	void SetAge(string data);
	string GetAge();

	void SetParentName(int* data);
	int * GetParentName();

	void SetChildCh(int data);
	int GetChildCh();

	void SetChildName(int* data);
	int * GetChildName();

	void SetSpousName(int* data);
	int GetSpousName();

	int* NameToId(string* names);
};

int bitDepth(int num);
