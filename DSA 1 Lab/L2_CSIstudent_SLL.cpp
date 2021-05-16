/*
 *  Created on: 04-May-2021
 *      @author sejal 2372
 *
 * DSA 1 Lab #2:
 	 	 CSI student branch student membership data maintenance using
		 singly linked list.
 *
 */
#include<iostream>

using namespace std;

class node
{
	string name;
	int roll, year;
	node *link;
	friend class list;

public:
	node()
	{
		name = "";
		roll = 0;
		year = 0;
		link = NULL;
	}
};

class list
{
	node *head;

public:
	list()
	{
		head = NULL;
	}

	node* accept();
	void create();
	void display();
	void insert();
	void remove();
	int count();
};

//accepts details, creates new node
node* list :: accept()
{
	node* tmp = new node();

	int rn;
	node *ptr;
	bool valid_roll = false;

	while(!valid_roll)
	{
		cout<<"\nEnter roll no.: ";
		cin>>rn;

		for(ptr = head; ptr != NULL; ptr=ptr->link)
		{
			if(ptr->roll == rn)
			{
				cout<<"Entered roll no. already exists.";
				break;
			}
		}

		if(ptr==NULL)
			valid_roll = true;
	}

	tmp->roll = rn;
	getchar(); //'\n'

	cout<<"Enter name: ";
	getline(cin, tmp->name);

	cout<<"Enter year: ";
	cin>>tmp->year;

	return tmp;
}

//adds the new node to singly linked list
void list :: create()
{
	char ch;
	node *ptr, *tmp;

	do{
		tmp = accept();
		if(head == NULL)
			head = tmp;
		else
		{
			for(ptr = head; ptr->link != NULL; ptr = ptr->link){}
			ptr->link = tmp;
		}
		cout<<"\nAdd another student? (y/n): ";
		cin>>ch;
	}while(ch!='n');
}

//displays all student members
void list :: display()
{
	if(head == NULL)
	{
		cout<<"\nList is empty. No members to display.";
		return;
	}

	cout<<"\n******* CSI STUDENT MEMBERS LIST *******";
	for(node *ptr = head; ptr != NULL; ptr = ptr->link)
	{
		cout<<"\nName: "<<ptr->name;
		cout<<"\nRoll number: "<<ptr->roll;
		cout<<"\nYear: "<<ptr->year;
		cout<<"\n............................................\n";
	}
}

//inserts new member at head, in middle or at end
void list :: insert(){
	int pos;
	bool valid_pos = false;
    node *ptr , *prev, *tmp;

    while(!valid_pos)
    {
    	cout<<"\nEnter position to insert the new member: ";
    	cin>>pos;
		if(pos<1 || pos>count()+1)
			cout<<"\nInvalid position. Try again.";
		else
			valid_pos = true;
    }

    tmp = accept();
    if(pos == 1)
    {
        tmp->link = head;
        head = tmp;
    }else
    {
        ptr = head;
        for(int i=1; i<pos; i++)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = tmp;
        tmp->link = ptr;
    }
}

//removes new member from head, middle or end
void list :: remove()
{
    int rn;
    node *ptr, *prev;

    if(head == NULL)
    {
        cout<<"\nList is empty.";
        return;
    }

    cout<<"\nEnter roll no. of member to delete: ";
    cin>>rn;

    for(ptr=head, prev=NULL ; ptr->roll!=rn && ptr!=NULL ; )
    {
        prev = ptr;
        ptr = ptr->link;
    }

    if(ptr == NULL)
    {
    	cout<<"\nRoll no. not found.";
    	return;
    }

    if(ptr == head)
        head = ptr->link;
    else
        prev->link = ptr->link;

    cout<<"\nDeleted member with roll no. "<<ptr->roll;
    delete ptr;
}

//counts total no. of members
int list :: count()
{
	int count = 0;
	for(node *ptr=head; ptr!=NULL; ptr=ptr->link)
		count++;
	return count;
}

int main(){
	int ch;
	list L;

	do{
		cout<<"\n******* CSI BRANCH MEMBERSHIP ********";
		cout<<"\n0. Exit";
		cout<<"\n1. Create members list";
		cout<<"\n2. Display members list";
		cout<<"\n3. Insert new member to list";
		cout<<"\n4. Delete a member from list";
		cout<<"\n5. Count no. total members";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 0: cout<<"\n********** PROGRAM ENDED ************";
				break;

		case 1: L.create();
				break;

		case 2: L.display();
				break;

		case 3: L.insert();
				break;

		case 4: L.remove();
				break;

		case 5: cout<<"\nTotal number of members: "<<L.count();
				break;

		default: cout<<"\nInvalid choice. Try again.";
		}
	}while(ch!=0);
	return 0;
}
