#pragma once
#include "FamillyMember.h"

typedef struct Element {
	FamillyMember* data {};
	Element* pNext = 0;
} Element;

class List
{
public:
	List();
	~List();
	void Del_head();
	void DelAll();

	List& operator++();//добавление в конец

	void AddElem(Element* elem);

	List& Del();//удаление

	List& Edit();//редактирование элемента

	void Print();//Печать списка
	int GetCount();
	void SetCount(int);

	Element* GetHead();
	void SetHead(Element*);

	Element* GetTail();
	void SetTail(Element*);

	bool IsEmpty();
private:
	Element* Head;
	Element* Tail;
	int count;
};
