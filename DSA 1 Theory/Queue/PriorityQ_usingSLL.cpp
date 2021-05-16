//PRIORITY QUEUE (FIFO) using Linked List
#include <iostream>

using namespace std;

class job
{
    int id;
    int priority;
    job *next;
    friend class queue;
    public:
        job()
        {
            id = 0;
            priority = 0;
            next = NULL;
        }

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
    job *front, *rear;

    public:
        queue()
        {
            front = NULL;
            rear = NULL;
        }
        bool is_empty();    //O(1)
        void enqueue();     //O(n)
        void dequeue();     //O(1)
        void display();     //O(n)
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
    job *tmp = new job();
    tmp->get_data();

    if(is_empty()) //1st element
    {
        front = tmp;
        rear = tmp;
    }
    else
    {
        job *ptr = front;
        job *prev = NULL;
        while(ptr!=NULL)
        {
            if(tmp->priority < ptr->priority)
            {
                tmp->next = ptr;
                if(prev==NULL) //ptr==front
                    front = tmp;
                else //prev!=NULL
                    prev->next = tmp;
                cout<<"\nEnequeued ..";
                return;
            }

            prev = ptr;
            ptr = ptr->next;
        }
        if(tmp->priority > rear->priority)
        {
            rear->next = tmp;
            rear = tmp;
        }
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

    job *ptr = front;
    ptr->put_data();
    front = ptr->next;
    delete ptr;
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
    for(job *ptr=front; ptr!=NULL; ptr=ptr->next)
        ptr->put_data();
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
