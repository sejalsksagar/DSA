//SINGLY CIRCULAR LINKED LIST
#include <iostream>

using namespace std;

class node
{
    int data;
    node *next;
    friend class SCLL;
    
    public:
        node(int d)
        {
            data = d;
            next = NULL;
        }
};

class SCLL
{
    node *head;
    
    public:
        SCLL()
        {
            head = NULL;
        }
        
        void create(); //O(n)
        void insert(); //O(n)
        void remove(); //O(n)
        void display(); //O(n)
};

void SCLL :: create()
{
    node *ptr, *tmp;
    int d;
    char ch;
    do{
        cout<<"\nEnter value : ";
        cin>>d;
        
        tmp = new node(d);
        
        ptr = head;
        if(head == NULL) 
        {
            head = tmp;
            tmp->next = head;
        }
        else
        {
            while(ptr->next!=head)
                ptr = ptr->next;
            
            ptr->next =  tmp;
            tmp->next = head;
        }

        cout<<"\nAdd another node (y/n): ";
        cin>>ch;
    }while(ch!='n');
}

void SCLL :: insert()
{
    if(head == NULL)
    {
        cout<<"\nList is empty.";
        return;
    }

    int pos, d;
    node *ptr, *prev;
    
    cout<<"\nEnter position for the node to be inserted: "; 
    cin>>pos;
    cout<<"\nEnter value : ";
    cin>>d;
    node *tmp = new node(d);

    if(pos == 1)
    {
        prev = head;
        while(prev->next != head)
            prev = prev->next;

        tmp->next = head;
        head = tmp;
        prev->next = head;
    }
    else
    {
        ptr = head;
        for(int i=1; i<pos; i++)
        {
            prev = ptr;
            ptr = ptr->next;

            if(ptr == head)
            {
                cout<<"\nInvalid position.";
                return;
            }
        }
        prev->next = tmp;
        tmp->next = ptr;
    }
    cout<<"\nInserted "<<d<<" at "<<pos;
}

void SCLL :: remove()
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
    node *prev = head;

    //If SCLL contains only a single node
    if((head->data == d) && (head->next == head))
        head = NULL;

    else if(head->data == d) //if head node to be deleted
    {
        while(prev->next != head)
             prev = prev->next; 

        head = ptr->next;
        prev->next = head;
    }   
    else
    {
        while(ptr->data!=d)
        {
            prev = ptr; 
            ptr = ptr->next;

            if(ptr == head)
            {
                cout<<"\nData not found.";
                return;
            }
        }
        prev->next = ptr->next;
    }
        
    cout<<"\nDeleted "<<ptr->data;
    delete ptr;
}

void SCLL :: display()
{
    if(head == NULL)
    {
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nSINGLY CIRCULAR LINKED LIST:\n HEAD --> ";
    node* ptr = head;
    while(ptr->next!=head)
    {
        cout<<"[ "<<ptr->data<<", "<<ptr->next<<" ] --> ";
        ptr = ptr->next;
    }
    cout<<"[ "<<ptr->data<<", "<<ptr->next<<" ] --> ";
    cout<<"HEAD";
}

int main()
{
    int ch;
    SCLL ll;
    do{
        cout<<"\n******* SINGLY CIRCULAR LINKED LIST *******";
        cout<<"\n(0) Exit";
        cout<<"\n(1) Create";
        cout<<"\n(2) Insert";
        cout<<"\n(3) Delete";
        cout<<"\n(4) Display";
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

            default: cout<<"\nInvalid choice.";
        }
    }while(ch!=0);

    return 0;
}
