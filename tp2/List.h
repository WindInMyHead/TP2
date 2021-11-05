#pragma once
#include "FamillyMember.h"
#include <string>

#pragma once


typedef struct Element
{
	FamillyMember data;
	Element* pNext = 0;
}Element;

class List
{
public:
	List();
	~List();
	void Del_head();
	void DelAll();

	List& operator++();//���������� � �����

	void AddElem(Element* elem);

	List& Del();//��������

	List& Edit();//�������������� ��������

	void Print();//������ ������
	int GetCount();

	void SaveToFile();

	List& ReadFromFile();
private:
	Element* Head;
	Element* Tail;
	int count;
};
