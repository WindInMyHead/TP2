#include "FamillyMember.h"

FamillyMember::FamillyMember(string name = NULL, string bDay = NULL, string age = NULL, string parentData = NULL, string spousData = NULL,
	string childData = NULL, string deathDay = NULL, int* idParent, int childCh, int* idChild) {
	ifstream fin("cnt.txt");
	FamillyMember::SetName(name);
	FamillyMember::SetBDay(bDay);
	FamillyMember::SetAge(age);
	FamillyMember::SetParentData(parentData);
	FamillyMember::SetSpousData(spousData);
	FamillyMember::SetChildData(childData);
	FamillyMember::SetDeathDay(deathDay);
	FamillyMember::SetParentName(idParent);
	FamillyMember::SetChildCh(childCh);
	FamillyMember::SetChildName(idChild);
	if (fin.peek() != EOF) {
		fin >> FamillyMember::cnt;
	}
	else FamillyMember::cnt = 0;
	fin.close();
	FamillyMember::id = FamillyMember::cnt;
}

void FamillyMember::SaveToFile() {
	ofstream fout("fileFm.txt", ios_base::app);
	fout << this->id << endl << this->name << endl << this->bDay << endl << this->age << endl << this->parentData << endl << this->spousData;
	fout << endl << this->childData << endl << this->deathDay << endl << this->idParent[0] << endl << this->idParent[1] << endl << this->childCh << endl;
	for (int i = 0; i < GetChildCh(); i++) {
		fout << this->idChild[i] << endl;
	}
	fout.close();
	ofstream f("cnt.txt");
	this->cnt++;
	f << this->cnt;
	f.close();
}

void FamillyMember::SetName(string name) {
	this->name = name;
}
string FamillyMember::GetName() {
	return this->name;
}
//=====
void FamillyMember::SetParentData(string data) {
	this->parentData = data;
}
string FamillyMember::GetParentData() {
	return this->parentData;
}
//=====
void FamillyMember::SetSpousData(string data) {
	this->spousData = data;
}
string FamillyMember::GetSpousData() {
	return this->spousData;
}
//=====
void FamillyMember::SetChildData(string data) {
	this->childData = data;
}
string FamillyMember::GetChildData() {
	return this->childData;
}
//=====
void FamillyMember::SetBDay(string data) {
	this->bDay = data;
}
string FamillyMember::GetBDay() {
	return this->bDay;
}
//=====
void FamillyMember::SetDeathDay(string data) {
	this->deathDay = data;
}
string FamillyMember::GetDeathDay() {
	return this->deathDay;
}
//=====
void FamillyMember::SetAge(string data) {
	this->age = data;
}
string FamillyMember::GetAge() {
	return this->age;
}
//=====
void FamillyMember::SetParentName(int* data) {
	this->idParent[0] = data[0];
	this->idParent[1] = data[1];
}
int* FamillyMember::GetParentName() {
	return this->idParent;
}
//=====
void FamillyMember::SetChildCh(int data) {
	this->childCh = data;
}
int FamillyMember::GetChildCh() {
	return this->childCh;
}
//=====
void FamillyMember::SetChildName(int * data) {
	this->idChild = new int[GetChildCh()];
	for (int i = 0; i < this->childCh; i++) {
		this->idChild[i] = data[i];
	}
}
int* FamillyMember::GetChildName() {
	return this->idChild;
}

int NameToId(string * names) {
	ifstream fin("fileFM");
	int id = 0;
	return id;
}