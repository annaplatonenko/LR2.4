// Лабораторная работа №2
// Вариант 4
// 1. Создать класс employee. 
// 2. Класс должен включать поле int для хранения номера сотрудника и поле float для хранения величины его оклада. 
// 3. Расширить содержание класса employee, включив в него класс date и перечисление etype.
// 4. Объект класса date использовать для хранения даты приема сотрудника на работу.
// 5. Перечисление использовать для хранения статуса сотрудника : лаборант, секретарь, менеджер и т.д.
// 6. Разработать методы getemploy() и putemploy(), предназначенные соответственно для ввода и отображения информации о сотруднике.
// 7. Написать программу, которая будет выдавать сведения о сотрудниках.

#include <iostream>
using namespace std; 

class Employee
{
public:
	class Date;
	Employee();
	Employee(int);
	~Employee();

class Date
{
public:
	Date(int day=1, int month=1, int year=1)
	{
		if (day > 31 || day < 1) this->day = 1;
		else this->day = day;
		if (month > 12 || month < 1) this->month = 1;
		else this->month = month;
		if (year > 2020 || year < 0001) this->year = 1;
		else this->year = year;
	}

	void PrintDate()
	{
		cout << day << '.' << month << '.' << year << endl;
	}


private:
	int day;
	int month;
	int year;
};

	void Getemploy() 
	{
		cout << "Введите зарплату сотрудника" << endl;
		cin >> salary;
		cout<<"Выберите должность из предложенных"<< endl;
		for (int i = (int)etype::lalaboratory_assistant; i <= (int)etype::programmer; i++)
		{
			cout << i << " - " << GetStringEnum(i) << endl;
		}
		int i;
		cin >> i;
		switch (i)
		{
		case (int)etype::lalaboratory_assistant:
			type = etype::lalaboratory_assistant;
			break;
		case (int)etype::secretary:
			type = etype::secretary;
			break;
		case (int)etype::manager:
			type = etype::manager;
			break;
		case (int)etype::programmer:
			type = etype::programmer;
			break;
		}
		cout << "Введите дату приема сотрудника на работу:" << endl;
		int day;
		cout << "Введите день ";
		cin >> day;
		int month;
		cout << "Введите месяц ";
		cin >> month;
		int year;
		cout << "Введите год ";
		cin >> year;
		date = Date(day, month, year); 
	}

	string GetStringEnum(int type)
	{
		switch (type)
		{
		case (int)etype::lalaboratory_assistant:
			return "Лаборант";
		case (int)etype::secretary:
			return "Секретарь";
		case (int)etype::manager:
			return "Менеджер";
		case (int)etype::programmer:
			return "Программист";
		default:
			return "Unknown";
		}
	}

	void Putemploy()
	{
		cout << "Сотрудник - " << number << endl;
		cout << "Должость: " << GetStringEnum((int)type) << endl;
		cout << "Зарплата: " << salary << " рублей" << endl;
		cout << "Дата приема сотрудника на работу:";
		date.PrintDate();
	}

private:
	int number;
	float salary = 0; 
	enum class etype
	{
		lalaboratory_assistant,
		secretary,
		manager,
		programmer
	};
	etype type = etype::lalaboratory_assistant;
	Date date;
};

Employee::Employee()
{
	number = 0;
	salary = 0;
	type = etype::lalaboratory_assistant;
	date = Date(1,1,1);
}

Employee::Employee(int a)
{
	number = a;
}

Employee::~Employee()
{
}

int main()
{
	setlocale(LC_ALL, "");
	int empl;
	cout << "Введите id сотрудника" << endl;
	cin >> empl;
	Employee sotrydnic(empl);
	sotrydnic.Getemploy();
	sotrydnic.Putemploy();
}
