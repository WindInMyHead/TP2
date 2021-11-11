#pragma once
#include<iostream>
#include <string>
#include "MyException.h"

using namespace std;

class FamillyMember{
private:
	string name;
	string bDay;
	string age;
	string parentData;
	string spousData;
	string childData;
	string deathDay;
public:
	FamillyMember() { };
	FamillyMember(string name = NULL, string bDay = NULL, string age = NULL, string parentData = NULL, string spousData = NULL, string deathDay = NULL, string childData = NULL);

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
};
