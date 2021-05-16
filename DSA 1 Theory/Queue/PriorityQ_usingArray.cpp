//PRIORITY QUEUE (FIFO) using Array 
#include <iostream>
#define MAX 5
using namespace std;

class job
{
    friend class queue;
    public:
        int id;
        int priority;

        void get_data();
        void put_data();
};

void job :: get_data()
{
    cout<<"\nEnter job id: ";
    cin>>id;
    cout<<"\nEnter job priority: ";
    cin>>priority;
}

void job :: put_data()
{
    cout<<"\n\njob id:\t"<<id;
    cout<<"\t,priority:\t"<<priority;
}

class queue
{
    int front, rear;
    job data[MAX];
    public:
        queue()
        {
            front = 0;
            rear = -1;
        }
        bool is_empty();    //O(1)
        bool is_full();     //O(1)
        void enqueue();     //O(n)
        void dequeue();     //O(1)
        void display();     //O(n)
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
    job j;
    j.get_data();

    if(is_empty()) //1st element
    {
        rear++;
        data[rear] = j;
    }
    else
    {
        int i = rear;
        while(i>=front && data[i].priority>j.priority)
        {
            data[i+1] = data[i];
            i = i - 1;
        }

        data[i+1] = j;
        rear++;
    }
    cout<<"\nEnequeued ...";
}

void queue :: dequeue()
{
    if(is_empty())
    {
        cout<<"Queue is empty. Can't dequeue.";
        return;
    }

    job tmp = data[front];
    tmp.put_data();

    if(front == rear)   //only one element left
    {
        front = 0;
        rear = -1;
    }
    else
        front++;
    cout<<"\nDequeued ...";
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
        data[i].put_data();
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
