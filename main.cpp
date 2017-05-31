

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include "remove.h"
#include "add.h"
//#include <cstdlib>
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

void show(book* begin);

void show1(book* begin);

void search_title(book* begin, book* end);

void search_author(book* begin, book* end);

void search_year(book* begin, book* end);

void search_number(book* begin, book* end);

void sort_title(book** begin, book** end);

void sort_author(book** begin, book** end);

void sort_year(book** begin, book** end);

void add_book(book** begin, book** end, int &k);

void remove_book(book**begin, book**end, int &k);

void input_from_file(book**end, book** begin);

void correct_number(book *begin, int&k);

void correct_book(book*begin, int k);

void backup(book *begin);

void del(book**begin);

int search_menu()
{
	int l;
	cout << "Search by title - 1\n"
		<< "Search by author - 2\n"
		<< "Search by year - 3\n"
		<< "Search by number - 4\n" << endl;
	cin >> l;
	return l;
}



int sort_menu()
{
	int l;
	cout << "Sort by title - 1\n"
		<< "Sort by author - 2\n"
		<< "Sort by year - 3\n" << endl;
	cin >> l;
	return l;
}

void take_book(book* begin, int k);

void return_book(book* begin, int k);

int main()
{
	system("color F5");
	int j = 1;
	book *begin = NULL;
	book *end = NULL;
	input_from_file(&end, &begin);
	correct_number(begin, j);
	bool inMenu = true;
	int l;
	cout << "Input 1 if you are client, 2 if you are worker" << endl;
	string line; 
	bool a = true;
	while (a)
	{
		getline(cin, line);
		stringstream ss(line);
		if ((ss >> l) && ss.eof())
		{
			a = false;
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	}
	if (l == 2)
	{
		while (inMenu)
		{

			system("cls");
			cout 
			
			    << "View all books - 1\n"
				<< "Add new book - 2\n"
				<< "Delete book - 3\n"
				<< "Search book - 4\n"
				<< "Sort books - 5\n"
				<< "Correct book - 6\n"
				<< "Create backup - 7\n"
				<< "Exit - 0\n " << endl;
			cout << "Your choice: ";
			string line;
			bool a = true;
			while (a)
			{
				getline(cin, line);
				stringstream ss(line);
				if ((ss >> l) && ss.eof())
				{
					a = false;
				}
				else
				{
					cout << "Invalid input" << endl;
				}
			}
			switch (l)
			{
			case 1:
				show(begin);
				break;
			case 2:
				add_book(&begin, &end, j);
				break;
			case 3:
				remove_book(&begin, &end, j);
				correct_number(begin, j);
				break;
			case 4:
				system("cls");
				switch (search_menu())
				{
				case 1:
					search_title(begin, end);
					break;
				case 2:
					search_author(begin, end);
					break;
				case 3:
					search_year(begin, end);
					break;
				case 4:
					search_number(begin, end);
					break;
				}
				break;
			case 5:
				system("cls");
				switch (sort_menu())
				{
				case 1:
					sort_title(&begin, &end);
					correct_number(begin, j);
					break;
				case 2:
					sort_author(&begin, &end);
					correct_number(begin, j);
					break;
				case 3:
					sort_year(&begin, &end);
					correct_number(begin, j);
					break;
				}
				break;
			case 6:
				correct_book(begin, j);
				break;
			case 7:
				backup(begin);
				break;
			case 0:
				inMenu = false;
				break;
			}
			system("pause");
		}
	}
	else if (l == 1)
	{
		while (inMenu)
		{

			system("cls");	
			cout << "View all books - 1\n"
				<< "Search book - 2\n"
				<< "Sort books - 3\n"
				<< "Take book - 4\n"
				<< "Return book - 5\n"
				<< "Create backup - 6\n"
				<< "Exit - 0\n " << endl;
			cout << "Your choice: ";
			string line;
			bool a = true;
			while (a)
			{
				getline(cin, line);
				stringstream ss(line);
				if ((ss >> l) && ss.eof())
				{
					a = false;
				}
				else
				{
					cout << "Invalid input" << endl;
				}
			}
			switch (l)
			{
			case 1:
				show(begin);
				break;
			case 2:
				system("cls");
				switch (search_menu())
				{
				case 1:
					search_title(begin, end);
					break;
				case 2:
					search_author(begin, end);
					break;
				case 3:
					search_year(begin, end);
					break;
				case 4:
					search_number(begin, end);
					break;
				case 5:
					backup(begin);
					break;
				}
				break;
			case 3:
				    system("cls");
				    switch (sort_menu())
				{
				case 1:
					sort_title(&begin, &end);
					correct_number(begin, j);
					break;
				case 2:
					sort_author(&begin, &end);
					correct_number(begin, j);
					break;
				case 3:
					sort_year(&begin, &end);
					correct_number(begin, j);
					break;
				}
				break;
			case 4:
				take_book(begin, j);
				break;
			case 5:
				return_book(begin, j);
				break;
			case 6:
				backup(begin);
				break;
			    	
			case 0:
				inMenu = false;
				break;
			}
			system("pause");
		}
	}

	return 0;
}
