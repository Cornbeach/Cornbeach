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

void del(book**begin)
{
	while ((*begin) != NULL)
	{
		book*temp = (*begin);
		temp = (*begin);
		*begin = (*begin)->next;
		delete temp;
	}
	return;
}
