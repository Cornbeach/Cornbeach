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


void remove_book(book**begin, book**end, int &k)
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	book *start = (*begin);
	int i;
	cout << "Delete book number: ";
	cin >> i;
	if (i<1 || i>k)
	{
		cout << "There is no book with this number";
		system("pause");
		system("cls");
		return;
	}
	while ((*begin)->number != i)
	{
		*begin = (*begin)->next;
	}
	if ((*begin)->next == NULL && (*begin)->prev == NULL) //deleting first&last
	{
		book* temp = *begin;
		temp = *begin;
		delete temp;
		*begin = NULL;
		*end = NULL;
		return;
	}
	if ((*begin)->prev == NULL && (*begin)->next != NULL) // deleting first
	{
		book * temp = *begin;
		*begin = (*begin)->next;
		delete temp;
		(*begin)->prev = NULL;
		return;
	}
	if ((*begin)->next == NULL && (*begin)->prev != NULL)// deleting last
	{
		book *temp = *begin;
		*begin = (*begin)->prev;
		(*begin)->next = NULL;
		(*end) = (*begin);
		(*begin) = start;
		delete temp;
		return;
	}
	if ((*begin)->next != NULL && (*begin)->prev != NULL)// deleting inside of list
	{
		book * temp = (*begin)->next;
		book * temp1 = (*begin)->prev;
		temp->prev = temp1;
		temp1->next = temp;
		delete *begin;
		(*begin) = start;
		return;
	}
}

