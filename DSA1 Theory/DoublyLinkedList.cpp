//DOUBLY LINKED LIST (DLL)
#include<iostream>
using namespace std;

class dnode
{
    int data;
    dnode *prev;
    dnode *next;
    friend class dll;
    public:
        dnode(int d)
        {
            data = d;
            prev = NULL;
            next = NULL;
        }
};

class dll
{
    dnode *start;
    public:
        dll()
        {
            start = NULL;
        }
        bool is_empty();    //O(1)
        void create();      //O(n)
        void display();     //O(n)
        void insert();      //O(n)
        void del_by_data(); //O(n)
        void reverse();     //O(n)
};

bool dll :: is_empty()
{
    if(start == NULL) //list is empty
        return true;
    else 
        return false;
}

void dll :: create()
{
    int d;
    char ch;

    do{
        cout<<"Enter data: ";
        cin>>d;
        dnode *tmp = new dnode(d);

        if(is_empty())
            start = tmp;
        else{
            dnode *ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = tmp;
            tmp->prev = ptr;
        }
        cout<<"\nNode added to dll.";

        cout<<"\nAdd another node? (y/n): ";
        cin>>ch;
    }while(ch == 'y');  
}

void dll :: display()
{
    if(is_empty())
    {
        cout<<"List is empty";
        return;
    }

    cout<<"START -> ";
    dnode *ptr = start;
    while(ptr!=NULL)
    {
        cout<<"[ (prev = "<<ptr->prev<<"), ";
        cout<<"(data = "<<ptr->data<<"), ";
        cout<<"(next = "<<ptr->next<<") ]";
        cout<<" <--> ";
        ptr = ptr->next;
    }
    cout<<"NULL";
}

void dll :: insert()
{
    if(is_empty())
    {
        cout<<"List is empty";
        return;
    }

    int pos, d;
    cout<<"Enter position to insert node: ";
    cin>>pos;
    cout<<"Enter data: ";
    cin>>d;
    dnode *tmp = new dnode(d);

    if(pos == 1) //At start
    {
        tmp->next = start;
        start->prev = tmp;
        start = tmp;
    }
    else
    {
        dnode *ptr = start;
        dnode *dprev = NULL;
        for(int i=1; i<pos; i++)
        {
            dprev = ptr;
            ptr = ptr->next;

            if(ptr == NULL)
            {
                cout<<"\nInvalid position.";
                return;
            }
        }
        
        dprev->next = tmp;
        tmp->next = ptr;
        tmp->prev = dprev;
        ptr->prev = tmp;
    } 
    
    cout<<"\nNode inserted at position "<<pos;
}

void dll :: del_by_data()
{
    if(is_empty())
    {
        cout<<"List is empty";
        return;
    }

    dnode *curr = start;
    int d;
    cout<<"Enter data to delete: ";
    cin>>d;

    while(curr!=NULL)
    {
        if(curr->data == d)
            break;
        curr = curr->next;
    }
    if(curr == NULL)
    {
        cout<<"Node not found.";
        return;
    }

    //if start node
    if (curr == start)
        start = curr->next;

    //if curr is not last node
    if (curr->next != NULL)
        (curr->next)->prev = curr->prev;

    //if curr is not 1st node
    if (curr->prev != NULL)
        (curr->prev)->next = curr->next;

    delete curr;
    cout<<"\nDeleted "<<d;
}

void dll :: reverse()
{
    if(is_empty() == 1)
    {
        cout<<"List is empty";
        return;
    }
    
    dnode *ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    while(ptr != start)
    {
        cout<<"[ (prev = "<<ptr->prev<<"), ";
        cout<<"(data = "<<ptr->data<<"), ";
        cout<<"(next = "<<ptr->next<<") ]";
        cout<<" <--> ";
        ptr = ptr->prev;
    }
    cout<<"[ (prev = "<<ptr->prev<<"), ";
    cout<<"(data = "<<ptr->data<<"), ";
    cout<<"(next = "<<ptr->next<<") ] <- START";
}

int main()
{
    int ch;
    dll D;
    do{
        cout<<"\n******* DOUBLY LINKED LIST *******";
        cout<<"\n(0) Exit";
        cout<<"\n(1) Create";
        cout<<"\n(2) Insert";
        cout<<"\n(3) Delete";
        cout<<"\n(4) Display";
        cout<<"\n(5) Display reversed dll";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 0: cout<<"\n****** PROGRAM ENDED ******";
                    break;

            case 1: D.create();
                    break;

            case 2: D.insert();
                    break;

            case 3: D.del_by_data();
                    break;

            case 4: D.display();
                    break;

            case 5: D.reverse();
                    break;

            default: cout<<"\nInvalid choice.";
        }
    }while(ch!=0);

    return 0;
}
