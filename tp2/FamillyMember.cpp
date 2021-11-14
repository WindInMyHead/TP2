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