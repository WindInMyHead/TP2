#include "List.h"

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
    system("cls");
    string name, bDay, age, parentData, spousData, childData, deathDay;
    cout << "===Add familly member====" << endl;
    cout << "!Press ENTER if there is no data !" << endl;
    //���
    cout << "Enter name(Full name): ";
    cin.ignore();
    getline(cin, name);
    //���� ��������
    cout << "Enter birth date: ";
    cin >> bDay;
    //�������
    cout << "Enter age: ";
    cin >> age;
    //���������� � ���������
    cout << "Enter parents data: ";
    cin.ignore();
    getline(cin, parentData);
    //���������� � �������
    cout << "Enter data about spous: ";
    getline(cin, spousData);
    //���������� � �����
    cout << "Enter data about child: ";
    getline(cin, childData);
    //���� ������
    cout << "Enter death date: ";
    cin >> deathDay;
    FamillyMember* memb = new FamillyMember(name, bDay, age, parentData, spousData, deathDay, childData);
    Element* temp = new Element;
    temp->data = memb;
    temp->pNext = NULL;


    if (this->IsEmpty()) {
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
    temp->data = elem->data;
    temp->pNext = elem->pNext;

    if (this->IsEmpty()) {
        Head = Tail = temp;
    }
    else {
        Element* p = Head;
        while (p->pNext != NULL) p = p->pNext;
        p->pNext = temp;
    }
    this->count++;
}

List& List::Del() {
    system("cls");
    if (this->IsEmpty()) {
        throw MyException("List is empty");
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
            cout << ++cnt << ". " << temp->data->GetName() << endl;
            temp = temp->pNext;
        }
        cout << ">>> ";
        cin >> cnt;
        if (cnt<1 || cnt>count) {
            throw MyException("Id do not exist");
        }
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
    system("cls");
    if (this->IsEmpty()) {
        throw MyException("List is empty");
    }
    List main = *this;
    List reserve;
    int cnt = 0;
    Element* temp = new Element;
    temp = Head;
    cout << "Which family member do you want to edit?" << endl;
    while (cnt != count) {
        cout << ++cnt << ". " << temp->data->GetName() << endl;
        temp = temp->pNext;
    }
    cout << ">>> ";
    cin >> cnt;
    if (cnt<1 || cnt>count) {
        throw MyException("Id do not exist");
    }
    cnt -= 1;
    temp = main.Head;
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
        temp->data->SetName(name);
        cout << "Complete!" << endl;
        break;
    }
    case 2:
    {
        string bDay;
        cout << "Enter new bDay: ";
        cin.ignore();
        getline(cin, bDay);
        temp->data->SetBDay(bDay);
        cout << "Complete!" << endl;
        break;
    }
    case 3:
    {
        string age;
        cout << "Enter new age: ";
        cin.ignore();
        getline(cin, age);
        temp->data->SetAge(age);
        cout << "Complete!" << endl;
        break;
    }
    case 4:
    {
        string parentData;
        cout << "Enter new parent data: ";
        cin.ignore();
        getline(cin, parentData);
        temp->data->SetParentData(parentData);
        cout << "Complete!" << endl;
        break;
    }
    case 5:
    {
        string spousData;
        cout << "Enter new spous data: ";
        cin.ignore();
        getline(cin, spousData);
        temp->data->SetSpousData(spousData);
        cout << "Complete!" << endl;
        break;
    }
    case 6:
    {
        string childData;
        cout << "Enter new child data: ";
        cin.ignore();
        getline(cin, childData);
        temp->data->SetChildData(childData);
        cout << "Complete!" << endl;
        break;
    }
    case 7:
    {
        string day;
        cout << "Enter new death day: ";
        cin.ignore();
        getline(cin, day);
        temp->data->SetDeathDay(day);
        cout << "Complete!" << endl;
        break;
    }
    default:
    {
        system("cls");
        cout << "Incorrected number" << endl;
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
    Element* temp = this->Head;
    Head = this->Head->pNext;
}

void List::DelAll(){
    while (Head != 0) this->Del_head();
}

void List::Print(){
    system("cls");
    Element* temp = this->Head;
    if (this->IsEmpty()) {
        throw MyException("List is empty");
    }

    int cnt = count;
    cout << "===Familly data===" << endl;
    while (cnt != 0) {
        cout << "Name: " << temp->data->GetName() << endl << "Bday: " << temp->data->GetBDay() << "   " << "Age: " << temp->data->GetAge() << endl << "Parent data: " << temp->data->GetParentData()
        << endl << "Spous data: " << temp->data->GetSpousData() << endl << "Death day:" << temp->data->GetDeathDay() << endl << "Child data: " << temp->data->GetChildData() << endl;
        // ��������� �� ��������� �������
        temp = temp->pNext;
        cnt--;
        cout << "===================" << endl;
    }
}

void List::SaveToFile() {
    system("cls");
    if (this->IsEmpty()) {
        throw MyException("List is empty");
    }
    ofstream fout("file.txt");
    if (!fout.is_open()) {
        throw MyException("File do not exist");
    }
    fout << this->count << endl;
    Element* Head_copy = Head;
    while(Head_copy != 0) {
        fout << Head_copy->data->GetName() << endl << Head_copy->data->GetBDay() << endl << Head_copy->data->GetAge() << endl << Head_copy->data->GetParentData() << endl <<
            Head_copy->data->GetSpousData() << endl << Head_copy->data->GetDeathDay() << endl << Head_copy->data->GetChildData() << endl;
        Head_copy = Head_copy->pNext;
    }
    fout.close();
    cout << "Complete!" << endl;
}

List& List::ReadFromFile() {
    string name, bDay, age, parentData, spousData, childData, deathDay;
    int cnt = 0;
    ifstream fin("file.txt");
    if (!fin.is_open()) {
        throw MyException("File do not exist");
    }
    fin >> cnt;
    for (int i = 0; i < cnt; i++) {
        getline(fin, name);
        if(i == 0) getline(fin, name);
        getline(fin, bDay);
        getline(fin, age);
        getline(fin, parentData);
        getline(fin, spousData);
        getline(fin, deathDay);
        getline(fin, childData);
        Element* temp = new Element;
        FamillyMember * memb = new FamillyMember(name, bDay, age, parentData, spousData, deathDay, childData);
        temp->data = memb;
        temp->pNext = NULL;

        if (count == 0) {
            temp->pNext = nullptr;
            Head = Tail = temp;
        }
        else {
            Element* p = Head;
            while (p->pNext != nullptr) p = p->pNext;
            p->pNext = temp;
            Tail = temp;
        }
        count++;
    }
    system("cls");
    cout << "Complete!" << endl;
    return *this;
}

bool List::IsEmpty() {
    return !count;
}