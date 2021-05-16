//DOUBLY CIRCULAR LINKED LIST (DCLL)
#include<iostream>
using namespace std;

class dnode
{
    int data;
    dnode *prev;
    dnode *next;
    friend class dcll;

    public:
        dnode(int d)
        {
            data = d;
            prev = NULL;
            next = NULL;
        }
};

class dcll
{
    dnode *start;
    public:
        dcll()
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

bool dcll :: is_empty()
{
    if(start == NULL) //list is empty
        return true;
    else 
        return false;
}

void dcll :: create()
{
    int d;
    char ch;

    do{
        cout<<"Enter data: ";
        cin>>d;
        dnode *tmp = new dnode(d);

        if(is_empty())
        {
            start = tmp;
            tmp->next = start;
            tmp->prev = start;
        }
        else
        {
            dnode *ptr = start;
            while(ptr->next != start)
                ptr = ptr->next;

            ptr->next = tmp;
            tmp->next = start;
            tmp->prev = ptr;
            start->prev = tmp;

        }
        cout<<"Node added to dcll.";

        cout<<"\nAdd another node? (y/n): ";
        cin>>ch;
    }while(ch == 'y');  
}

void dcll :: display()
{
    if(is_empty())
    {
        cout<<"List is empty";
        return;
    }

    dnode *ptr = start;
    cout<<"START -> ";
    cout<<"[ (prev = "<<ptr->prev<<"), ";
    cout<<"(data = "<<ptr->data<<"), ";
    cout<<"(next = "<<ptr->next<<") ]";
    cout<<" <--> ";

    ptr = ptr->next;
    while(ptr!=start)
    {
        cout<<"[ (prev = "<<ptr->prev<<"), ";
        cout<<"(data = "<<ptr->data<<"), ";
        cout<<"(next = "<<ptr->next<<") ]";
        cout<<" <--> ";
        ptr = ptr->next;
    }
    cout<<"START";
}

void dcll :: insert()
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
    
    if(pos == 1)  //At start
    {
        (start->prev)->next = tmp;
        tmp->next = start;
        tmp->prev = start->prev;
        start->prev = tmp;
        start = tmp;
    }
    else  //At other positions
    {
        dnode *ptr = start;
        dnode *dprev = NULL;
        for(int i=1; i<pos; i++)
        {
            dprev = ptr;
            ptr = ptr->next;

            if(ptr == start)
            {
                cout<<"\nInvalid positon.";
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

void dcll :: del_by_data()
{
    if(is_empty())
    {
        cout<<"List is empty";
        return;
    }
    
    int d;
    cout<<"Enter data to delete: ";
    cin>>d;

    dnode *curr = start;
    while(curr->next!=start)
    {
        if(curr->data == d)
            break;
        curr = curr->next;
    }
    if(curr->data != d)
    {
        cout<<"Node not found.";
        return;
    }
    
    if(start->data == d) //if start node
    {  
        if(start->next == start) //if only 1 node in dcll
            start = NULL;
        else
        {
            (start->prev)->next = start->next;
            (start->next)->prev = start->prev;
            start = start->next;
        }
    }
    else //other node
    {
        (curr->prev)->next = curr->next;
        (curr->next)->prev = curr->prev;    
    }
    delete curr;
    cout<<"\nNode deleted.";
}

void dcll :: reverse()
{
    if(is_empty())
    {
        cout<<"List is empty";
        return;
    }

    dnode *ptr = start->prev; //last node
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
    dcll D;
    do{
        cout<<"\n******* DOUBLY CIRCULAR LINKED LIST *******";
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
