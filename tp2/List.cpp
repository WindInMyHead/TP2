#include "List.h"

List::List(){
    Head = Tail = NULL;
    count = 0;
}

List::~List(){
    DelAll();
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

List& List::Del(int cnt) {
    system("cls");
    if (this->IsEmpty()) {
        throw MyException("List is empty");
    }
    if (cnt<0 || cnt>count) {
        throw MyException("Id do not exist");
    }
    List reserve;
    Element* temp = Head;
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
    count--;
    return *this;
}

void List::Del_head() {
    Element* temp = this->Head;
    Head = this->Head->pNext;
}

void List::DelAll() {
    while (Head != 0) this->Del_head();
}

List& List::operator++() {
    system("cls");
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

Element* List::operator[](const int index) {
    if (index < 0 || index >= this->count) throw("Incorrect index");

    if (index == 0) return this->Head;
    else if (index == this->count - 1) return this->Tail;
    else {
        Element* p = Head;
        for (int i = 0; i < index; i++) {
            p = p->pNext;
        }
        return p;
    }
}

void List::AddElem(Element* elem) {
    if (this->IsEmpty()) {
        Head = Tail = elem;
    }
    else {
        Element* p = Head;
        while (p->pNext != NULL) p = p->pNext;
        Tail = elem;
    }

    this->count++;
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

void List::Print() {
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
        // Переходим на следующий элемент
        temp = temp->pNext;
        cnt--;
        cout << "===================" << endl;
    }
}

List& List::RemoveSimilar() {
    system("cls");
    if (this->IsEmpty()) {
    throw MyException("List is empty");
    }
    int flag = 0;
    int cntDel = 0;
    string* names = new string[this->count];
    string* delNames = new string[this->count];
    for (int i = 0; i < this->count; i++) {
        names[i] = this->Head->data->GetName();
        for (int j = 0; j < i - 1; j++) {
            if (names[i] == names[j]) {
                flag = 1;
                this->Del(j);
                delNames[cntDel] = names[i];
                cntDel++;
            }
        }
    }
    if (flag == 1) {
        cout << "Complete, ";
        for (int i = 0; i < cntDel; i++) {
            cout << delNames[i] << " ";
        }
        cout << "has been deleted" << endl;
    }
    else {
        cout << "No similar records!" << endl;
    }
    delete[] names, delNames;
    return *this;
}

int List::GetCount(){
    return count;
}
void List::SetCount(int cnt) {
    this->count = cnt;
}

Element* List::GetHead() {
    return Head;
}
void List::SetHead(Element* elem) {
    this->Head = elem;
}

Element* List::GetTail() {
    return Tail;
}
void List::SetTail(Element* elem) {
    this->Tail = elem;
}


bool List::IsEmpty() {
    return !count;
}