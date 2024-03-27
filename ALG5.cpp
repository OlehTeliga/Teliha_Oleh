#include <iostream>
#include "windows.h"
#include <set>

using namespace std;

class myClass
{
private:
	set<set<int>> Movie;

	int x;
	int y;
	int z;
	
public:
	myClass()
	{
		Movie.insert({1,2,3});
		Movie.insert({3,2,5});
	}

	void pritnSet()
	{
		for (auto it = Movie.begin(); it != Movie.end(); it++)
		{
			for (auto i : *it)
			{
				cout << i << " ";
			}
			cout << endl;
		};
	}

	void addSet()
	{
		system("cls");
		int x, y, z;
		cout << "Ведіть дані для множини (х,у,z): ";
		cin >> x;
		cin >> y;
		cin >> z;

		Movie.insert({ x,y,z });
	}

	void deletSet()
	{
		system("cls");
		cout << "Яки елемент бажаєте видалити: \n";

		cin >> x;
		cin >> y;
		cin >> z;

		if (Movie.find({ x,y,z }) != Movie.end())
		{
			cout << "Елемент був видалений !!!\n";
			Movie.erase(Movie.find({ x,y,z }));
		}
		else {
			cout << "Такого елементу не існує\n";
		}
		
		cin >> y;
	}

	void redSet()
	{
		cout << "Напишіть елементи рядка яких хочете змінити: \n";
		cin >> x;
		cin >> y;
		cin >> z;
		
		if (Movie.find({ x,y,z, }) != Movie.end())
		{
			cout << "Такий рядок існує , введіть значення на які потрібно замінити:\n";
			Movie.erase(Movie.find({ x,y,z }));
			cin >> x;
			cin >> y;
			cin >> z;
			Movie.insert({ x,y,z });
		}
		else
		{
			cout << "Такого рядка не існує\n";
		}
	};
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	myClass ALG;
	char userInput;
	while (true)
	{
		system("cls");
		ALG.pritnSet();
		cout << "Варіант дій: \n1.Дадати рядок в множину (Рядок не повинен повторюватись!)\n2.Видалити рядок\n3.Редагувати рядок";
		cin >> userInput;

		switch (userInput)
		{
		case '1':
			ALG.addSet();
			break;
		case '2':
			ALG.deletSet();
			break;
		case'3':
			ALG.redSet();
			break;
		default:
			break;
		}
	}
}
