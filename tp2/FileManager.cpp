#include "FileManager.h"

FileManager::FileManager() {
    this->file.open("file.txt");
    if (!file.is_open()) {
        throw MyException("File do not exist");
    }
}

FileManager::~FileManager() {
    file.close();
}

void FileManager::SaveToFile(List& list) {
    system("cls");
    if (list.IsEmpty()) {
        throw MyException("List is empty");
    }
    this->file << list.GetCount() << endl;
    Element* Head_copy = list.GetHead();
    while (Head_copy != 0) {
        this->file << Head_copy->data->GetName() << endl << Head_copy->data->GetBDay() << endl <<
            Head_copy->data->GetAge() << endl << Head_copy->data->GetParentData() << endl <<
            Head_copy->data->GetSpousData() << endl << Head_copy->data->GetDeathDay() << endl
            << Head_copy->data->GetChildData() << endl;
        Head_copy = Head_copy->pNext;
    }
    this->file.close();
    cout << "Complete!" << endl;
}

List& FileManager::ReadFromFile(List& list) {
    string name, bDay, age, parentData, spousData, childData, deathDay;
    int cnt = 0;
    this->file >> cnt;
    for (int i = 0; i < cnt; i++) {
        getline(this->file, name);
        if (i == 0) getline(this->file, name);
        getline(this->file, bDay);
        getline(this->file, age);
        getline(this->file, parentData);
        getline(this->file, spousData);
        getline(this->file, deathDay);
        getline(this->file, childData);
        Element* temp = new Element;
        FamillyMember* memb = new FamillyMember(name, bDay, age, parentData, spousData, deathDay, childData);
        temp->data = memb;
        temp->pNext = NULL;

        if (list.IsEmpty()) {
            temp->pNext = nullptr;
            list.SetHead(temp);
            list.SetTail(temp);
        }
        else {
            Element* p = list.GetHead();
            while (p->pNext != nullptr) p = p->pNext;
            p->pNext = temp;
            list.SetTail(temp);
        }
        int inc = list.GetCount() + 1;
        list.SetCount(inc);
    }
    system("cls");
    cout << "Complete!" << endl;
    return *this;
}