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
void show1(book* begin);

void search_title(book* begin, book* end)
{
	if (begin == NULL || end == NULL)
	{
		cout << "Error! Library is empty" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Input title to search: ";
	char search_title[30];
	cin.ignore();
	cin.getline(search_title, 255);
	while (begin != NULL)
	{
		if (strstr(begin->title, search_title) != NULL)
			show1(begin);
		begin = begin->next;
	}
}

void search_author(book* begin, book* end)
{
	if (begin == NULL || end == NULL)
	{
		cout << "Error! Library is empty" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Input author to search: ";
	char search_author[30];
	cin.ignore();
	cin.getline(search_author, 255);
	while (begin != NULL)
	{
		if (strstr(begin->author, search_author) != NULL)
			show1(begin);
		begin = begin->next;
	}
}

void search_year(book* begin, book* end)
{
	if (begin == NULL || end == NULL)
	{
		cout << "Error! Library is empty" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Input year to search: ";
	int year;
	cin >> year;
	while (begin != NULL)
	{
		if (begin->year == year)
			show1(begin);
		begin = begin->next;
	}
}




void search_number(book* begin, book* end)
{
	if (begin == NULL || end == NULL)
	{
		cout << "Error! Library is empty" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Input number to search: ";
	int number;
	cin >> number;
	while (begin->next != NULL)
	{
		if (begin->number == number)
		{
			show1(begin);
			return;
		}
		begin = begin->next;
	}
}
