//LINEAR QUEUE (FIFO) using Array 
#include <iostream>
#define MAX 5
using namespace std;

class queue
{
    int front, rear;
    int data[MAX];
    public:
        queue()
        {
            front = 0;
            rear = -1;
        }
        bool is_empty();
        bool is_full();
        void enqueue();
        void dequeue();
        void display();
};

bool queue :: is_empty()
{
    if(front == rear+1) 
        return 1;
    else 
        return 0;
}

bool queue :: is_full()
{
    if(rear == MAX-1)
        return 1;
    else 
        return 0;
}

void queue :: enqueue()
{
    if(is_full())
    {
        cout<<"Queue is full. Can't enqueue.";
        return;
    }
    cout<<"Enter data to enequeue: ";
    rear++;
    cin>>data[rear];
    cout<<"Enequeued "<<data[rear];
}

void queue :: dequeue()
{
    if(is_empty())
    {
        cout<<"Queue is empty. Can't dequeue.";
        return;
    }
    cout<<"Dequeued "<<data[front];
    front++;

    if(front == rear)
    {
        front = 0;
        rear = -1;
    }
}

void queue :: display()
{
    if(is_empty())
    {
        cout<<"Queue is empty.";
        return;
    }
    cout<<"QUEUE:";
    for(int i=front; i<=rear; i++)
        cout<<"\n"<<i+1<<") "<<data[i];
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
