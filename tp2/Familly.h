#pragma once
#include "FamillyMember.h"

class Familly : public FamillyMember{
private:
	int id;
	FamillyMember left;
	FamillyMember right;
public:
	void Group(FamillyMember, FamillyMember);
};

