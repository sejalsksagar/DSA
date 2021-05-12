/*
 * DSA 1 Lab #6:
 * 		Title: Library Book data maintenance
		Problem Statement:
				College Library maintains records of books. Write a program using C++
				for following operations :
									1. Add a new book details.
									2. Search a book in library.
									3. Sort books based on ISBN numbers.
									4. List all books of specific author.
									Use appropriate data structure.
 *
 *  Created on: 11-May-2021
 *      Author: sejal 2372
 */
#include<iostream>
#include<iomanip>

using namespace std;

class book
{
public:
	long long int ISBN_no; //13 digit
	string book_name;
	string author_name;
	string publication;
	book *link;
	friend class library;

	book()
	{
		ISBN_no = 0;
		book_name = "";
		author_name = "";
		publication = "";
		link = NULL;
	}

	void accept_details();
	void display_details();
};

void book :: accept_details()
{
	cout<<"\nEnter ISBN number: ";
	cin>>ISBN_no;
	getchar();
	cout<<"Enter book name: ";
	getline(cin, book_name);
	cout<<"Enter author name: ";
	getline(cin, author_name);
	cout<<"Enter publication: ";
	getline(cin, publication);
}

void book :: display_details()
{
	cout<<"\n" << setw(15)<<ISBN_no<<setw(20)<<book_name<<setw(20)<<author_name<<setw(20)<<publication;
}

class library
{
	int N;
	book* head;

public:
	library()
	{
		N = 0;
		head = NULL;
	}

	bool is_empty();
	void accept_all();
	void add_new();
	void display_header();
	void display_all();
	void search_by_author();
	void search_by_name();
	book* search_by_ISBN();
	void ISBN_search_result();
};

bool library :: is_empty()
{
	if(head == NULL)
	{
		cout<<"\nLibrary book list is empty.";
		return true;
	}
		return false;
}

void library :: accept_all()
{
	cout<<"\nEnter number of books: ";
	cin>>N;

	book *B;
	for(int i=0; i<N; i++)
	{
		B = new book();
		B->accept_details();

		if(head == NULL)
			head = B;
		else
		{
			B->link = head;
			head = B;
		}
	}
}

void library :: add_new()
{
	book *B = new book();
	B->accept_details();

	if(head == NULL)
		head = B;
	else
	{
		B->link = head;
		head = B;
	}
	N++;
}

void library :: display_header()
{
	cout<<"\n---------------------------------------------------------------------------------------------";
	cout<<"\n" << setw(15)<<"ISBN no."<<setw(20)<<"Book name"<<setw(20)<<"Author name"<<setw(20)<<"Publication";
	cout<<"\n----------------------------------------------------------------------------------------------";

}

void library :: display_all()
{
	if(is_empty()) return;

	cout<<"\n************ LIBRARY BOOK LIST **************";
	display_header();
	for(book *P=head; P!=NULL; P=P->link)
		P->display_details();
	cout<<"\n----------------------------------------------------------------------------------------------";
}

//linear/sequential search
void library :: search_by_author()
{
	if(is_empty()) return;

	bool found = false;
	string author;
	getchar();
	cout<<"\nEnter author name: ";
	getline(cin, author);

	for(book *P=head; P!=NULL; P=P->link)
	{
		if(P->author_name == author)
		{
			if(!found)
			{
				cout<<"\n************ SEARCH RESULTS **************";
				display_header();
			}
			found = true;
			P->display_details();
			cout<<"\n----------------------------------------------------------------------------------------------";
		}
	}
	if(!found)
		cout<<"\nAuthor not found.";
}

//linear/sequential search
void library :: search_by_name()
{
	if(is_empty()) return;

	bool found = false;
	string name;
	getchar();
	cout<<"\nEnter book name: ";
	getline(cin, name);

	for(book *P=head; P!=NULL; P=P->link)
	{
		if(P->book_name == name)
		{
			if(!found)
			{
				cout<<"\n************ SEARCH RESULTS **************";
				display_header();
			}
			found = true;
			P->display_details();
			cout<<"\n----------------------------------------------------------------------------------------------";
		}
	}
	if(!found)
		cout<<"\nBook not found.";
}

void swap(book *a, book *b)
{
	long long int ISBN_no = a->ISBN_no;
	string book_name = a->book_name;
	string author_name = a->author_name;
	string publication = a->publication;

	a->ISBN_no = b->ISBN_no;
	a->book_name = b->book_name;
	a->author_name = b->author_name;
	a->publication = b->publication;

	b->ISBN_no = ISBN_no;
	b->book_name = book_name;
	b->author_name = author_name;
	b->publication = publication;
}

//bubble sort
void bubble_sort_AO(book *head)
{
	book *I, *J;
	for(I=head; I->link!=NULL; I=I->link)
	{
		for(J=I->link; J!=NULL; J=J->link)
		{
			if(J->ISBN_no < I->ISBN_no)
				swap(I, J);
		}

	}
	cout<<"\nAfter Selection Sort: ";
}

//binary search
book* library :: search_by_ISBN()
{
	bubble_sort_AO(head);
	display_all();

	long long int key;
	cout<<"\nEnter ISBN number to search: ";
	cin>>key;

	int mid, low = 0, high = N - 1;
	while(low <= high)
	{
		mid = (low + high)/2;

		book *M=head;
		for(int i=0; i<mid; i++)
			M = M->link;

		if(M->ISBN_no == key)
			return M;
		else if(M->ISBN_no > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return NULL;
}

void library :: ISBN_search_result()
{
	if(is_empty()) return;

	book *F = search_by_ISBN();
	if(F == NULL)
		cout<<"\nBook not found.";
	else
	{
		cout<<"\nBook found.";
		display_header();
		F->display_details();
		cout<<"\n----------------------------------------------------------------------------------------------";
	}
}

int main()
{
	int ch;
	library L;
	L.accept_all();

	do{
		cout<<"\n************** LIBRARY DATABASE ***************";
		cout<<"\n0. Exit";
		cout<<"\n1. Add a new book details";
		cout<<"\n2. Search a book by book name";
		cout<<"\n3. Search a book by author name";
		cout<<"\n4. Search a book by ISBN number";
		cout<<"\n5. Display all books";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 0: cout<<"\n************* PROGRAM ENDED ******************";
				break;

		case 1: L.add_new();
			    break;

		case 2: L.search_by_name();
				break;

		case 3: L.search_by_author();
				break;

		case 4: L.ISBN_search_result();
				break;

		case 5: L.display_all();
				break;
		}
	}while(ch!=0);
	return 0;
}

/*********** TIME COMPLEXITY *************
 * Linear Search.....................O(n)
 * Binary Search.....................O(logn)
 */
