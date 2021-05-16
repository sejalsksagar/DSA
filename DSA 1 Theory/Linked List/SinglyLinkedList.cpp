//SINGLY LINKED LIST
#include <iostream>

using namespace std;

class node
{
    int data;
    node *next;
    friend class linked_list;
    
    public:
        node(int d)
        {
            data = d;
            next = NULL;
        }
};

class linked_list
{
    node *head;
    
    public:
        linked_list()
        {
            head = NULL;
        }
        
        void create();  //O(n)
        void insert();  //O(n)
        void remove();  //O(n)
        void display(); //O(n)
		void reverse(); //O(n)
};

void linked_list :: create()
{
    node *ptr, *tmp;
    int d;
    char ch;
    do{
        cout<<"\nEnter value : ";
        cin>>d;
        
        tmp = new node(d);
        
        if(head == NULL) 
            head = tmp;
        else
        {
            ptr = head;
            while(ptr->next!=NULL)
                ptr = ptr->next;
            
            ptr->next =  tmp;
        }

        cout<<"Add another node (y/n): ";
        cin>>ch;
    }while(ch!='n');
}

void linked_list :: insert()
{
    if(head == NULL)
    {
        cout<<"\nList is empty.";
        return;
    }

    node *ptr , *prev, *tmp;
    int pos, d;

    cout<<"\nEnter position for the node to be inserted: ";
    cin>>pos;
    cout<<"\nEnter value : ";
    cin>>d;
    tmp = new node(d);

    if(pos == 1)
    {
        tmp->next = head;
        head = tmp;
    }
    else
    {
        ptr = head;
        for(int i=1; i<pos; i++)
        {
            prev = ptr;
            ptr = ptr->next;

            if(ptr==NULL)
            {
                cout<<"\nInvalid position.";
                return;
            }
        }
        prev->next = tmp;
        tmp->next = ptr;
    }
    cout<<"\nInserted "<<d<<" at position "<<pos;
}

void linked_list :: remove()
{
    if(head == NULL)
    {
        cout<<"\nList is empty.";
        return;
    }

    int d;
    cout<<"\nEnter data to delete: ";
    cin>>d;
    
    node *ptr = head;
    node *prev = NULL;
    while(ptr->data!=d)
    {
        prev = ptr; 
        ptr = ptr->next;

        if(ptr == NULL)
        {
            cout<<"\nData not found.";
            return;
        }
    }

    if(ptr == head)
        head = ptr->next;
    else
        prev->next = ptr->next;
    
    cout<<"\nDeleted "<<ptr->data;
    delete ptr;
}

void linked_list :: display()
{
    if(head == NULL)
    {
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nLinked List: HEAD --> ";
    node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<"[ "<<ptr->data<<", "<<ptr->next<<" ] --> ";
        ptr = ptr->next;
    }
    cout<<"NULL";
}

void linked_list :: reverse()
{
	node *curr = head;
	node *cprev = NULL;
	node *cnext = NULL;

	while(curr != NULL)
	{
		cnext = curr->next;
		curr->next = cprev;
		cprev = curr;
		curr = cnext;
	}
	head = cprev;
	cout<<"\nSLL has been reversed.";
}

int main()
{
    int ch;
    linked_list ll;
    do{
        cout<<"\n******* SINGLY LINKED LIST *******";
        cout<<"\n(0) Exit";
        cout<<"\n(1) Create";
        cout<<"\n(2) Insert";
        cout<<"\n(3) Delete";
        cout<<"\n(4) Display";
		cout<<"\n(5) Reverse SLL";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 0: cout<<"\n****** PROGRAM ENDED ******";
                    break;

            case 1: ll.create();
                    break;

            case 2: ll.insert();
                    break;

            case 3: ll.remove();
                    break;

            case 4: ll.display();
                    break;

			case 5: ll.reverse();
					break;

            default: cout<<"\nInvalid choice.";
        }
    }while(ch!=0);

    return 0;
}
