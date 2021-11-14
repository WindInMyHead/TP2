//Класс Фамильное дерево хранит данные о семье. Каждый член семьи имеет:
//ФИО, знания о родителях, знания о супруге, знания о своих детях, дату
//рождения, дату смерти(если есть), возраст.
#include"Menu.h"

int main() {
	try {
		List list;
		return Menu(list);
	}
	catch (MyException& exception){
		cout << "Exception occurred : " << exception.what() << "\n";
	}
	catch (exception& exception){
		cout << "Some other exception occurred : " << exception.what() << "\n";
	}
}
