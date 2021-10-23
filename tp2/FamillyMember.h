#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class FamillyMember{
private:
	int cnt;
	int id;
	int idParent[2];
	int childCh;
	int *idChild;
	string name;
	string bDay;
	string age;
	string parentData;
	string spousData;
	string childData;
	string deathDay;
public:
	FamillyMember(string, string, string, string*, string, string, string, string);

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

	int* NameToId(string* names);
};

int bitDepth(int num);
