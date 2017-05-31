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

void show(book* begin)
{
	system("cls");
	while (begin != NULL)
	{
		cout << begin->number << endl << "Title: " << begin->title
			<< endl << "Author: " << begin->author << endl << "Year: " << begin->year << endl;
		if (begin->inStock)
		{
			cout << "In stock" << endl;
		}
		else
		{
			cout << "On hands" << endl;
		}
		cout << endl;
		begin = begin->next;
	}
}
