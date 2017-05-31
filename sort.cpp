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
void sort_title(book** begin, book** end)
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	book *temp, *temp1;
	while ((*begin)->next != NULL)
	{
		if (strcmp((*begin)->title, (*begin)->next->title) > 0)
		{
			temp = (*begin);
			temp1 = (*begin)->next->next;
			*begin = (*begin)->next;
			(*begin)->next = temp;
			(*begin)->prev = temp->prev;
			temp->next = temp1;
			temp->prev = (*begin);
			if (temp1 != NULL)
			{
				temp1->prev = temp;
			}
			if ((*begin)->prev != NULL)
			{
				(*begin) = (*begin)->prev;
				(*begin)->next = temp->prev;
			}
			while ((*begin)->prev != NULL)
			{
				*begin = (*begin)->prev;
			}
		}
		else
		{
			*begin = (*begin)->next;
		}
	}
	while ((*begin)->prev != NULL)
	{
		*begin = (*begin)->prev;
	}
	while ((*end)->next != NULL)
	{
		(*end) = (*end)->next;
	}
}

void sort_author(book** begin, book** end)
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	book *temp, *temp1;
	while ((*begin)->next != NULL)
	{
		if (strcmp((*begin)->author, (*begin)->next->author) > 0)
		{
			temp = (*begin);
			temp1 = (*begin)->next->next;
			*begin = (*begin)->next;
			(*begin)->next = temp;
			(*begin)->prev = temp->prev;
			temp->next = temp1;
			temp->prev = (*begin);
			if (temp1 != NULL)
			{
				temp1->prev = temp;
			}
			if ((*begin)->prev != NULL)
			{
				(*begin) = (*begin)->prev;
				(*begin)->next = temp->prev;
			}
			while ((*begin)->prev != NULL)
			{
				*begin = (*begin)->prev;
			}
		}
		else
		{
			*begin = (*begin)->next;
		}
	}
	while ((*begin)->prev != NULL)
	{
		*begin = (*begin)->prev;
	}
	while ((*end)->next != NULL)
	{
		(*end) = (*end)->next;
	}
}

void sort_year(book** begin, book** end)
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	book *temp, *temp1;
	while ((*begin)->next != NULL)
	{
		if ((*begin)->year > (*begin)->next->year)
		{
			temp = (*begin);
			temp1 = (*begin)->next->next;
			*begin = (*begin)->next;
			(*begin)->next = temp;
			(*begin)->prev = temp->prev;
			temp->next = temp1;
			temp->prev = (*begin);
			if (temp1 != NULL)
			{
				temp1->prev = temp;
			}
			if ((*begin)->prev != NULL)
			{
				(*begin) = (*begin)->prev;
				(*begin)->next = temp->prev;
			}
			while ((*begin)->prev != NULL)
			{
				*begin = (*begin)->prev;
			}
		}
		else
		{
			*begin = (*begin)->next;
		}
	}
	while ((*begin)->prev != NULL)
	{
		*begin = (*begin)->prev;
	}
	while ((*end)->next != NULL)
	{
		(*end) = (*end)->next;
	}
}

