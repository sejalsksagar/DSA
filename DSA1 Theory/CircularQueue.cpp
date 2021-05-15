//LINEAR CIRCULAR QUEUE (FIFO) using Array 
#include<iostream>
#define MAX 5
using namespace std;

class queue
{
    int front, rear;
    int data[MAX];
    public:
        queue()
        {
            front = -1;
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
    if(front==-1 && rear==-1)
        return 1;
    else 
        return 0;
}

bool queue :: is_full()
{
    if((rear==MAX-1 && front==0) || (front==(rear+1)))
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
    if(front==-1)
        front=0;
       
    cout<<"Enter data to enequeue: ";
    rear = (rear+1)%MAX;
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
    
    if(front==rear) //only one element left
    {
        cout<<"Dequeued "<<data[0];
        front = -1;
        rear = -1;
    }
    else
    {
        cout<<"Dequeued "<<data[front];
        front = (front+1)%MAX;
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
    int i;
    cout<<"front rear "<<front<<" "<<rear<<"\n";
    for(i=front; i!=rear; i=(i+1)%MAX)
        cout<<"\n"<<i+1<<") "<<data[i];
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

