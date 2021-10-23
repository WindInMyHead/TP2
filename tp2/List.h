#pragma once
#include"FamillyMember.h"

class List : public FamillyMember{
private:
	int size;
	FamillyMember** prevElem;
	FamillyMember** nextElem;
public:
	void Add(FamillyMember);
	void Del(FamillyMember);
};