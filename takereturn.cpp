#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <sstream>
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
void take_book(book* begin, int k)
{
	int c;
	cout << "Input number of book, that you want to take: ";
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
	if (begin->inStock == false)
	{
		cout << "Book is already on hands." << endl;
	}
	begin->inStock = false;
}

void return_book(book* begin, int k)
{
	int c;
	cout << "Input number of book, that you want to return: ";
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
	if (begin->inStock == true)
	{
		cout << "Book is already in library." << endl;
	}
	begin->inStock = true;
}

