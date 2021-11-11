#include "FamillyMember.h"

FamillyMember::FamillyMember(string name, string bDay, string age, string parentData, string spousData, string deathDay, string childData) {
	FamillyMember::SetName(name);
	FamillyMember::SetBDay(bDay);
	FamillyMember::SetAge(age);
	FamillyMember::SetParentData(parentData);
	FamillyMember::SetSpousData(spousData);
	FamillyMember::SetDeathDay(deathDay);
	FamillyMember::SetChildData(childData);
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
//void FamillyMember::SetParentName(int* data) {
//	this->idParent = new int[2];
//	this->idParent[0] = data[0];
//	this->idParent[1] = data[1];
//}
//int* FamillyMember::GetParentName() {
//	return this->idParent;
//}
//=====

//void FamillyMember::SetChildName(int * data) {
//	this->idChild = new int[GetChildCh()];
//	for (int i = 0; i < this->childCh; i++) {
//		this->idChild[i] = data[i];
//	}
//}
//int* FamillyMember::GetChildName() {
//	return this->idChild;
//}
////=====
//void FamillyMember::SetSpousName(int* data) {
//	this->idSpous = new int[1];
//	this->idSpous[0] = data[0];
//}
//int* FamillyMember::GetSpousName() {
//	return this->idSpous;
//}
//=====
//int* FamillyMember::NameToId(string* names) {
//	ifstream fin("fileFM.txt");
//	string tmp;
//	int id[2]{};
//	for (int i = 0; i < 2; i++) {
//		do {
//			getline(fin, tmp);
//		} while (tmp != names[i]);
//		int seek = names[i].size() + bitDepth(this->id) + 4;
//		fin.clear();
//		fin.seekg(- seek, ios::cur);
//		getline(fin, tmp);
//		id[i] = stoi(tmp);
//	}
//	return id;
//}
//
//string* FamillyMember::IdToName(int* id, int cnt) {
//	ifstream fin("fileFM.txt");
//	string * tmp = new string[cnt];
//	for (int i = 0; i < cnt; i++) {
//		do {
//			getline(fin, tmp[i]);
//		} while (stoi(tmp[i]) != id[i]);
//		getline(fin, tmp[i]);
//	}
//	return tmp;
//}

//int bitDepth(int num) {
//	int count = 0;
//	while (num != 0) {
//		count++;
//		num /= 10;
//	}
//	return count;
//}

//void FamillyMember::SaveToFile() {
//	ofstream fout("fileFm.txt", ios_base::app);
//	fout << this->id << endl << this->name << endl << this->bDay << endl << this->age << endl << this->parentData << endl << this->spousData;
//	fout << endl << this->childData << endl << this->deathDay << endl << this->idParent[0] << endl << this->idParent[1] << endl << this->childCh << endl;
//	for (int i = 0; i < GetChildCh(); i++) {
//		fout << this->idChild[i] << endl;
//	}
//	fout.close();
//	ofstream f("cnt.txt");
//	this->id;
//	f << this->id;
//	f.close();
//}