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
#include "add.h"
using namespace std;


void show(book* begin);

void add_book(book** begin, book** end, int &k)
{
///fignia
	ofstream fout("base_reserv.txt");
	int c;
	cout << "Input number of books, you want to add to library: ";
	cin >> c;
	if (c == 0)
	{
		return;
	}
	if ((*end) == NULL || (*begin) == NULL)
	{
		(*begin) = new book;
		(*end) = (*begin);
		(*end)->author = new char[30];
		(*end)->title = new char[30];
		(*end)->prev = NULL;
		book* temp = NULL;
		for (int i = 0; i < c; i++)
		{
			cout << "Book " << k << endl;
			(*end)->number = k;
			fout << k << endl;
			k++;
			cout << "Title: ";
			cin.ignore(1);
			cin.getline((*end)->title, 255);
			fout << (*end)->title << endl;
			cout << "Author: ";
			cin.getline((*end)->author, 255);
			fout << (*end)->author << endl;
			cout << "Year: ";
			string line;
			bool a = true;
			while (a)
			{
				getline(cin, line);
				stringstream ss(line);
				if ((ss >> (*end)->year) && ss.eof())
				{
					a = false;
				}
				else
				{
					cout << "Invalid input" << endl;
				}
			}
			fout << (*end)->year << endl;
			fout << (*end)->inStock << endl;

			if (i == c - 1)
			{
				(*end)->next = NULL;
				(*end)->prev = temp;
			}
			else
			{
				(*end)->next = new book;
				temp = *end;
				*end = (*end)->next;
				(*end)->prev = temp;
				(*end)->author = new char[30];
				(*end)->title = new char[30];
			}
		}
		show(*begin);
		fout.close();
		return;
	}
	(*end)->next = new book;
	book* temp = *end;
	*end = (*end)->next;
	(*end)->prev = temp;
	(*end)->author = new char[30];
	(*end)->title = new char[30];
	for (int i = 0; i < c; i++)
	{
		cout << "Book " << k << endl;
		(*end)->number = k;
		fout << k << endl;
		k++;
		cout << "Title: ";
		cin.ignore(1);
		cin.getline((*end)->title, 255);
		fout << (*end)->title << endl;
		cout << "Author: ";
		cin.getline((*end)->author, 255);
		fout << (*end)->author << endl;
		cout << "Year: " << endl;
		string line;
		bool a = true;
		while (a)
		{
			getline(cin, line);
			stringstream ss(line);
			if ((ss >> (*end)->year) && ss.eof())
			{
				a = false;
			}
			else
			{
				cout << "Invalid input" << endl;
			}
		}
		fout << (*end)->year << endl;
		fout << (*end)->inStock << endl;

		if (i == c - 1)
		{
			(*end)->next = NULL;
		}
		else
		{
			(*end)->next = new book;
			temp = *end;
			*end = (*end)->next;
			(*end)->author = new char[30];
			(*end)->title = new char[30];
		}
		(*end)->prev = temp;
	}
	fout.close();
	return;
}
