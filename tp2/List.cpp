#include "List.h"
#include <iostream>

using namespace std;

List::List(){
    Head = Tail = NULL;
    count = 0;
}

List::~List(){
    DelAll();
}

int List::GetCount(){
    return count;
}

List& List::operator++() {
    Element* temp = new Element[1];
    string name, bDay, age, parentData, spousData, childData, deathDay;
    cout << "===Add familly member====" << endl;
    cout << "!Press ENTER if there is no data !" << endl;
    //имя
    cout << "Enter name(Full name): ";
    cin.ignore();
    getline(cin, name);
    //дата рождения
    cout << "Enter birth date: ";
    cin >> bDay;
    //возраст
    cout << "Enter age: ";
    cin >> age;
    //информация о родителях
    cout << "Enter parents data: ";
    cin.ignore();
    getline(cin, parentData);
    //информация о супруге
    cout << "Enter data about spous: ";
    getline(cin, spousData);
    //информация о детях
    cout << "Enter data about child: ";
    getline(cin, childData);
    //дата смерти
    cout << "Enter death date: ";
    cin >> deathDay;
    FamillyMember memb(name, bDay, age, parentData, spousData, deathDay, childData);
    temp->data = memb;
    temp->pNext = NULL;

    if (count == 0){
        temp->pNext = nullptr;
        Head = Tail = temp;
    }
    else {
        Element* p = Head;
        while (p->pNext != NULL) p = p->pNext;
        p->pNext = temp;
    }
    count++;
    return *this;
}

void List::AddElem(Element *elem) {
    Element* temp = elem;
    if (count == 0) {
        temp->pNext = nullptr;
        Head = Tail = temp;
    }
    else {
        Element* p = Head;
        while (p->pNext != NULL) p = p->pNext;
        p->pNext = temp;
    }
    count++;
}

List& List::Del() {
    if (count == 0) {
        cout << "List is empty" << endl;
    }
    else if (count == 1) {
        Element* temp = Head;
        delete temp;
        Head = Tail = NULL;
        cout << "Now this list is empty" << endl;
    }
    else {
        List reserve;
        int cnt = 0;
        Element* temp = Head;
        cout << "Which family member do you want to remove?" << endl;
        while (cnt != count) {
            cout << cnt + 1 << ". " << temp->data.GetName();
            temp = temp->pNext;
        }
        cin >> cnt;
        cnt -= 1;
        temp = Head;
        for (int i = 0; i < cnt; i++) {
            reserve.AddElem(temp);
            temp = temp->pNext;
        }
        temp = temp->pNext;
        for (int i = cnt + 1; i < count; i++) {
            reserve.AddElem(temp);
            temp = temp->pNext;
        }
        this->Head = reserve.Head;
    }
    count--;
    return *this;
}

List& List::Edit() {
    List reserve;
    int cnt = 0;
    Element* temp = Head;
    cout << "Which family member do you want to edit?" << endl;
    while (cnt != count) {
        cout << cnt + 1 << ". " << temp->data.GetName();
        temp = temp->pNext;
    }
    cin >> cnt;
    cnt -= 1;
    temp = Head;
    for (int i = 0; i < cnt; i++) {
        reserve.AddElem(temp);
        temp = temp->pNext;
    }
    int v;
    cout << "===EDIT MENU===" << endl;
    cout << "Which parameter do you want to edit?" << endl;
    cout << "1. Name" << endl;
    cout << "2. bDay" << endl;
    cout << "3. Age" << endl;
    cout << "4. Parent data" << endl;
    cout << "5. Spous data" << endl;
    cout << "6. Child data" << endl;
    cout << "7. Death day" << endl;
    cout << "0. Exit" << endl;
    cin >> v;
    switch (v) {
    case 1:
    {
        string name;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, name);
        temp->data.SetName(name);
    }
    case 2:
    {
        string bDay;
        cout << "Enter new bDay: ";
        getline(cin, bDay);
        temp->data.SetBDay(bDay);
    }
    case 3:
    {
        string age;
        cout << "Enter new age: ";
        getline(cin, age);
        temp->data.SetAge(age);
    }
    case 4:
    {
        string parentData;
        cout << "Enter new parent data: ";
        getline(cin, parentData);
        temp->data.SetParentData(parentData);
    }
    case 5:
    {
        string spousData;
        cout << "Enter new spous data: ";
        getline(cin, spousData);
        temp->data.SetParentData(spousData);
    }
    case 6:
    {
        string childData;
        cout << "Enter new child data: ";
        getline(cin, childData);
        temp->data.SetParentData(childData);
    }
    case 7:
    {
        string day;
        cout << "Enter new death day: ";
        getline(cin, day);
        temp->data.SetName(day);
    }
    default:
    {
        break;
    }
    }

    for (int i = cnt + 1; i < count; i++) {
        reserve.AddElem(temp);
        temp = temp->pNext;
    }
    this->Head = reserve.Head;
    return *this;
}

void List::Del_head(){
    Element* temp = Head;
    Head = Head->pNext;
    delete temp;
}

void List::DelAll(){
    while (Head != 0)
        Del_head();
}

void List::Print(){
    Element* temp = Head;
    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }

    while (temp != 0){
        cout << "Name: " << temp->data.GetName() << endl << "Bday: " << temp->data.GetBDay() << "   " << "Age: " << temp->data.GetAge()
        << endl << "Spous data: " << temp->data.GetSpousData() << endl << "Death day:" << temp->data.GetDeathDay() << endl << "Child data: " << temp->data.GetChildData() << endl;
        // Переходим на следующий элемент
        temp = temp->pNext;
    }
}

void List::SaveToFile() {
    ofstream fout("file.txt");
    fout << this->count << endl;
    while(Head != 0) {
        fout << Head->data.GetName() << endl << Head->data.GetBDay() << endl << Head->data.GetAge() << endl << Head->data.GetParentData() << endl <<
            Head->data.GetSpousData() << endl << Head->data.GetDeathDay() << endl << Head->data.GetChildData() << endl;
        Head = Head->pNext;
    }
    fout.close();
    cout << "Complete!";
}

List& List::ReadFromFile() {
    Element* temp = new Element[1];
    string name, bDay, age, parentData, spousData, childData, deathDay;
    int cnt = 0;
    ifstream fin("file.txt");
    fin >> cnt;
    for (int i = 0; i < cnt; i++) {
        getline(fin, name);
        getline(fin, bDay);
        getline(fin, age);
        getline(fin, parentData);
        getline(fin, spousData);
        getline(fin, deathDay);
        getline(fin, childData);
        FamillyMember memb(name, bDay, age, parentData, spousData, deathDay, childData);
        temp->data = memb;
        temp->pNext = NULL;

        if (count == 0) {
            temp->pNext = nullptr;
            Head = Tail = temp;
        }
        else {
            Element* p = Head;
            while (p->pNext != NULL) p = p->pNext;
            p->pNext = temp;
        }
        count++;
    }
    cout << "Complete!" << endl;
    return *this;
}