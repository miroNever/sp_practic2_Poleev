// practic2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;
void zadanie1()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int n = 10;
	int mass[10];
	cout << "Исходный массив: " << endl;
	for (int i = 0; i < n; i++)
	{
	mass[i] = rand() % 15;
	cout << mass[i] << " ";
	}
	cout << endl;
	cout << "Не повторяющийся массив: " << endl;
	for (int i = 0; i < n; ++i) {
		int currentElementValue = mass[i];
		bool hasEquals = false;

		for (int r = 0; r < n; ++r) {
			if (i == r) {
				continue;
			}
			if (currentElementValue == mass[r] && i != r) {
				hasEquals = true;
			}
		}
		if (!hasEquals) {
			
			cout << currentElementValue << " ";
		}
	}
}

void zadanie2()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	const int col = 3;
	const int row = 3;
	int mass[col][row];
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			mass[i][j] = rand() % 100;
			cout << mass[i][j] << "  ";
		}
		cout << endl;
	}

	for (int j = 0; j < col; j++)
	{
		int max = mass[0][j];
		int min = mass[0][j];
		int difference;
		for (int i = 1; i < row; i++)
		{
			if (mass[i][j] > max)
				max = mass[i][j];
			if (mass[i][j] < min)
				min = mass[i][j];
			difference = max - min;

		}
		cout << "Разница "<< j + 1 << " столбца: " << difference << endl;
	}
}
struct Employee {
		char name[100];
		char position[100];
		float salari;
	};
void zadanie3()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	const int countPerson = 5;
	Employee employees[countPerson] = {
		{"Бондырев", "Директор", 20000.0},
		{"Полеев", "Зам-Директора", 18000.0},
		{"Гребенюков", "Дизайнер", 14000.0},
		{"Швец", "Дизайнер", 14000.0},
	    {"Максимов", "Поломойка", 10.0},
	};
	float totalSalari = 0.0;
	int a = 1;
	cout << "Список сотрудников" << endl;
	for (int i = 0; i < countPerson; i++)
	{
		cout << employees[i].name << "(" << employees[i].position << ") - " << employees[i].salari << "руб." << endl;
		totalSalari += employees[i].salari;
	}
	float averageSalari = totalSalari / countPerson;
	cout << endl<< "Сотрудникики с зарплатой ниже средней: " << endl;
	for (int i = 0; i < countPerson; i++)
	{
		if (employees[i].salari < averageSalari)
			cout << employees[i].name <<"(" << employees[i].position << ")" << endl;
	}
}
class Queue {
	private: 
		static const int size = 5;
		int elements[size];
		int start;
		int	end;
	public:
		Queue()
		{
			start = -1;
			end = -1;
		}
		bool isFull() {
			if (start == 0 && end == size - 1) {
				return true;
			}
			return false;
		}
		bool isEmpty() {
			if (start == -1)
				return true;
			else
				return false;
		}
		void Add(int value) {
			if (isFull()) {
				cout << "Очередь заполнена"<< endl;
			}
			else {
				if (start == -1)
					start = 0;
				end++;
				elements[end] = value;
				cout << "Добавлен элемент " << value << endl;
			}
		}
		int Delete() {
			int value;
			if (isEmpty()) {
				cout << "Очередь пуста"<< endl;
				return (-1);
			}
			else {
				value = elements[start];
				if (start >= end) {
					start = -1;
					end = -1;
				}
				else {
					start++;
				}
				cout << "Удален элемент -> ";
				return (value);
			}
		}
		void Display() {
			int i;
			if (isEmpty()) {
				cout << "Пустая очередь"<< endl;
			}
			else {
				cout << "Индекс start-> " << start;
				cout << " Элементы -> ";
				for (i = start; i <= end; i++)
					cout << elements[i] << "  ";

				cout << "Индекс end-> " << end << endl;
			}
		}

};
void zadanie4()
{
	setlocale(LC_ALL, "ru");
	Queue queue;
	queue.Display();
	queue.Add(1);
	queue.Add(2);
	queue.Add(3);
	queue.Add(4);
	queue.Add(5);
	queue.Add(6);
	queue.Display();
	cout << queue.Delete() << endl;
	queue.Display();

}
int main()
{
	zadanie4();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
