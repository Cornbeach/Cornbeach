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

void input_from_file(book**end, book** begin)
{
	ifstream fin("base_reserv.txt");
	if (fin.fail())
	{
		cout << "Opening file ERROR" << endl;
		return;
	}
	streampos current = fin.tellg();
	fin.seekg(0, fin.end);
	bool empty = !fin.tellg();
	fin.seekg(current, fin.beg);
	if (empty)
	{
		cout << "File is empty" << endl;
		return;
	}
	if (*end == NULL || (*begin) == NULL)
	{
		if ((*begin) == NULL)
		{
			(*begin) = new book;
			(*begin)->author = new char[30];
			(*begin)->title = new char[30];
		}
		(*end) = (*begin);
		(*end)->prev = NULL;
		book*temp = NULL;
		while (!fin.eof())
		{
			fin >> (*end)->number;
			fin.ignore();
			fin.getline((*end)->title, 255);
			//fin.ignore(1);
			fin.getline((*end)->author, 255);
			//fin.ignore(1);
			fin >> (*end)->year;
			fin.ignore();
			fin >> (*end)->inStock;
			fin.ignore();
			if (!fin.eof())
			{
				(*end)->next = new book;
				temp = *end;
				*end = (*end)->next;
				(*end)->prev = temp;
				(*end)->author = new char[30];
				(*end)->title = new char[30];
			}
		}
		if ((*end)->prev == NULL)
		{
			(*end)->next = NULL;
			return;
		}
		else
		{
			temp = (*end);
			(*end) = (*end)->prev;
			delete temp;
			(*end)->next = NULL;
			fin.close();
			return;
		}
	}
	else
	{
		(*end)->next = new book;
		book*temp = *end;
		*end = (*end)->next;
		(*end)->prev = temp;
		(*end)->author = new char[30];
		(*end)->title = new char[30];
		while (!fin.eof())
		{

			fin >> (*end)->number;
			fin.ignore();
			fin.getline((*end)->title, 255);
			//fin.ignore();
			fin.getline((*end)->author, 255);
			//fin.ignore();
			fin >> (*end)->year;
			fin.ignore();
			fin >> (*end)->inStock;
			fin.ignore();
			if (!fin.eof())
			{
				(*end)->next = new book;
				temp = *end;
				*end = (*end)->next;
				(*end)->prev = temp;
				(*end)->author = new char[30];
				(*end)->title = new char[30];
			}
		}
		temp = (*end);
		(*end) = (*end)->prev;
		delete temp;
		(*end)->next = NULL;
		fin.close();
		return;
	}
}
