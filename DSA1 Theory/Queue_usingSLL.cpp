//LINEAR QUEUE (FIFO) using Linked List
#include <iostream>

using namespace std;

class node
{
    int data;
    node *next;
    friend class queue;
    public:
        node(int d)
        {
            data = d;
            next = NULL;
        }
};

class queue
{
    node *front, *rear;

    public:
        queue()
        {
            front = NULL;
            rear = NULL;
        }
        bool is_empty();
        void enqueue();
        void dequeue();
        void display();
};

bool queue :: is_empty()
{
    if(front == NULL) 
        return 1;
    else 
        return 0;
}

void queue :: enqueue()
{
    int d;
    cout<<"Enter data to enequeue: ";
    cin>>d;

    node *tmp = new node(d);
    if(is_empty())
    {
        rear = tmp;
        front = tmp;
    }
    else
    {
        rear->next = tmp;
        rear = tmp;
    }   
    cout<<"Enequeued "<<d;
}

void queue :: dequeue()
{
    if(is_empty())
    {
        cout<<"Queue is empty. Can't dequeue.";
        return;
    }
    node *ptr = front;
    cout<<"Dequeued "<<ptr->data;
    front = ptr->next;
    delete ptr;
}

void queue :: display()
{
    if(is_empty())
    {
        cout<<"Queue is empty.";
        return;
    }
    cout<<"QUEUE:";
    node *ptr = front;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"NULL";
}

int main()
{
    queue Q;
    int ch;
    do{
        cout<<"\n**** QUEUE OPERATIONS ****";
        cout<<"\n0. Exit";
        cout<<"\n1. Enqueue";
        cout<<"\n2. Dequeue";
        cout<<"\n3. Display";
        cout<<"\nEnter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 0: cout<<"**** PROGRAM ENDED ****";
                    break;
            case 1: Q.enqueue();
                    break;
            case 2: Q.dequeue();
                    break;
            case 3: Q.display();
                    break;
            default: cout<<"Invalid choice.";
        }

    }while(ch!=0);

    return 0;
}
