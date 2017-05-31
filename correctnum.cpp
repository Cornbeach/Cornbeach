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

void correct_number(book *begin, int&k)
{
	k = 1;
	while (begin != NULL)
	{
		begin->number = k;
		k++;
		begin = begin->next;
	}
}
