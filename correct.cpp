#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include "remove.h"
using namespace std;

struct book
{
	int number;
	int year;
	char* author;
	char* title;
	bool inStock = true;
	book* next;
	book* prev;
};
void show1(book* begin);

void correct_book(book*begin, int k)
{
	int m = 1;
	int c;
	cout << "Input number of book, that you want to correct: ";
	cin >> c;
	if (c < 1 || c > k)
	{
		cout << "There is no book with this number";
		system("pause");
		system("cls");
		return;
	}
	while (begin->number != c)
	{
		begin = begin->next;
	}
	show1(begin);
	while (m != 0)
	{
		cout << "Change title - 1\n"
			<< "Change author - 2\n"
			<< "Change year -3\n"
			<< "exit - 0" << endl;
		cin >> m;
		cin.ignore();
		switch (m)
		{
		case(1) :
		{
					cout << "Input title ";
					cin.getline(begin->title, 255);
					show1(begin);
					break;
		}
		case(2) :
		{
					cout << "Input author ";
					cin.getline(begin->author, 255);
					show1(begin);
					break;
		}
		case(3) :
		{
					cout << "Input year ";
					string line;
					bool a = true;
					while (a)
					{
						getline(cin, line);
						stringstream ss(line);
						if ((ss >> begin->year) && ss.eof())
						{
							a = false;
						}
						else
						{
							cout << "Invalid input" << endl;
						}
					}
					show1(begin);
					break;
		}
		}
	}

}
