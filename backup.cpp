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

void backup(book *begin)
{
	ofstream fout("base_reserv.txt", ios_base::trunc);
	while (begin != NULL)
	{
		fout << begin->number << endl;
		fout << begin->title << endl;
		fout << begin->author << endl;
		fout << begin->year << endl;
		fout << begin->inStock << endl;

		begin = begin->next;
	}
	fout.close();
}
