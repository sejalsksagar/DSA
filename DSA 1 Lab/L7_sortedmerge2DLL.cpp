/*
Department of computer engineering has two division. Student information along with their percentage are 
stored in linked list for every division in a sorted order. Generate a combined list of students which is sorted
in descending order based on their percentage. (Doubly Linked List)
*/

#include<iostream>
using namespace std;

class student
{
public:
	string name;
	int roll;
    float percent;
    student *prev;
    student *next;
    
        student()
        {
			name = "";
			roll = 0;
            percent = 0;
            prev = NULL;
            next = NULL;
        }
};

class division
{
public:
	int N;
    student *start;
    
        division()
        {
			N = 0;
            start = NULL;
        }
        bool is_empty();    //O(1)
        void create();      //O(n)
        void display();     //O(n)
		void sort_percent(); //O(n^2)
};

bool division :: is_empty()
{
    if(start == NULL) //list is empty
        return true;
    else 
        return false;
}

void division :: create()
{
    char ch;

    do{
        student *tmp = new student();
        cout<<"\nEnter student name: ";
        getline(cin, tmp->name);
		cout<<"Enter roll number: ";
		cin>>tmp->roll;
		cout<<"Enter percentage: ";
		cin>>tmp->percent;
		N++;

        if(is_empty())
            start = tmp;
        else{
            student *ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = tmp;
            tmp->prev = ptr;
        }
        cout<<"\nNode added to dll.";

        cout<<"\nAdd another node? (y/n): ";
        cin>>ch;
        getchar();
    }while(ch == 'y');  
}

void division :: display()
{
    if(is_empty())
    {
        cout<<"List is empty";
        return;
    }

    int i = 1;
    student *ptr = start;
    while(ptr!=NULL)
    {
		cout<<"\n"<<i++;
        cout<<"\nName: "<<ptr->name;
		cout<<"\nRoll no: "<<ptr->roll;
		cout<<"\nPercentage: "<<ptr->percent;
		cout<<"\n-----------------------------------";
        ptr = ptr->next;
    }
}
//<->ptr1<->ptr2<->
student* swap_adj_nodes(student* ptr1, student* ptr2)
{
    student* tmp_nxt = ptr2->next;
    student* tmp_prv = ptr1->prev;
    
    ptr2->next = ptr1;
	ptr2->prev = tmp_prv;

    ptr1->next = tmp_nxt;
    ptr1->prev = ptr2;

    if(tmp_nxt!=NULL)
        tmp_nxt->prev = ptr1;

    if(tmp_prv != NULL)
        tmp_prv->next = ptr2;
    
    return ptr2;
}

//Bubble Sort for DLL : Descending Order 
void division :: sort_percent()
{
    bool swaps;
    student **ptr;
    student *ptr1, *ptr2;
    
    for(int i=0; i<N; i++)
    {
        ptr = &start;
        swaps = false;

		for(int j=0; j<N-1-i; j++)
		{
			ptr1 = *ptr;
			ptr2 = ptr1->next;

			if(ptr1->percent < ptr2->percent)
			{
				*ptr = swap_adj_nodes(ptr1, ptr2);
				swaps = true;
			}

			ptr = &(*ptr)->next;
		}

        if(!swaps)
            break;
    }
	cout<<"\nDescending order: ";
}

//sorted merge of two sorted doubly linked lists
void combined_list(division A, division B)
{
    division C;

    student *ptr = C.start;
    student *ptrA = A.start;
    student *ptrB = B.start;

    while(ptrA!=NULL && ptrB!=NULL)
    {
        if(ptrA->percent > ptrB->percent)
        {
            if(C.start == NULL)
            {
                C.start = ptrA;
                ptr = ptrA;
            }
            else
            {
                ptr->next = ptrA;
                ptrA->prev = ptr;
                ptr = ptr->next;
            }
            ptrA = ptrA->next;
        }
        else //(ptrA->percent > ptrB->percent)
        {
            if(C.start == NULL)
            {
                C.start = ptrB;
                ptr = ptrB;
            }
            else
            {
                ptr->next = ptrB;
                ptrB->prev = ptr;
                ptr = ptr->next;
            }
            ptrB = ptrB->next;
        }
    }

    if(ptrA != NULL)
    {
        ptr->next = ptrA;
        ptrA->prev = ptr;
    }
    if(ptrB != NULL)
    {
        ptr->next = ptrB;
        ptrB->prev = ptr;
    }

    C.display();
}

int main()
{
	division A;
	cout<<"\n******** FOR DIV A *********";
	A.create();
	A.sort_percent();
	A.display();

	division B;
	cout<<"\n******** FOR DIV B *********";
	B.create();
	B.sort_percent();
	B.display();

	cout<<"\n******** COMBINED LIST *********";
    combined_list(A, B);
	return 0;
}
