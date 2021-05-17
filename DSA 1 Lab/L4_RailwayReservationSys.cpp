/*
 *  Created on: 07-May-2021
 *      @author sejal 2372
 *
 * DSA 1 Lab #4:
 *		 Implement Queue as ADT using linked list or array. Use Queue ADT to simulate �waiting list�
 *		 operations of railway reservation system.
 *
 */

//LINEAR QUEUE (FIFO) using Array
#include<iostream>
#include<cstdlib>

#define MAX 5
using namespace std;

class passenger
{
	string name;
	int age;
	char gender;
	string contact_no;
	long int PNR;
	string booking_status;
	friend class queue;
public:
	passenger()
	{
		name = "";
		age = 0;
		gender = '\0';
		contact_no = "";
		PNR = 0;
		booking_status = "CONFIRMED";
	}
	void accept(); //accepts passenger details
	void display(); //displays passenger details
	static int search_PNR(passenger C[], int size, long int PNR);
};

void passenger :: accept()
{
	PNR = rand()%100000 + 1110000000; //10 digits
	cout<<"\nEnter name: ";
	getline(cin,name);
	cout<<"Enter age: ";
	cin>>age;
	cout<<"Enter gender (M/F): ";
	cin>>gender;
	cout<<"Contact number: ";
	cin>>contact_no;
}

void passenger :: display()
{
	cout<<"\nPNR number: "<<PNR;
	cout<<"\nName: "<<name;
	cout<<"\nGender: "<<gender;
	cout<<"\nAge: "<<age;
	cout<<"\nContact number: "<<contact_no;
	cout<<"\nBooking status: "<<booking_status;
	cout<<"\n.................................";
}

int passenger :: search_PNR(passenger C[], int size, long int PNR)
{
	passenger P;
	int pos = -1;
	for(int i=0; i<size; i++)
	{
		if(PNR == C[i].PNR)
		{
			pos = i;
			break;
		}
	}
	return pos; //position of ticket to cancel
}

class queue
{
    int front, rear;
    passenger P[MAX];
    public:
        queue()
        {
            front = 0;
            rear = -1;
        }
        int is_empty();
        int is_full();
        void enqueue();
        passenger dequeue();
        void show_front();
        void show_rear();
        void display();
};

int queue :: is_empty()
{
    if(front == rear+1) //
        return 1;
    else
        return 0;
}

int queue :: is_full()
{
    if(rear == MAX-1)
        return 1;
    else
        return 0;
}

//adds passenger to the queue
void queue :: enqueue()
{
    rear++;
    P[rear].accept();
    P[rear].booking_status = "WAITING";
    P[rear].display();
}

//removes first passenger from queue
passenger queue :: dequeue()
{
    passenger p = P[front];
    p.booking_status = "CONFIRMED";
    front++;
    if(front == rear)//single passenger in the queue
    {
    	front = 0;
    	rear = -1;
    }
    cout<<"\nTicket was successfully cancelled.";
    return p;
}

void queue :: show_front()
{
	P[front].display();
}

void queue :: show_rear()
{
	P[rear].display();
}

void queue :: display()
{
    if(is_empty() == 1)
    {
        cout<<"Queue is empty.";
        return;
    }
    cout<<"QUEUE:";
    for(int i=front; i<=rear; i++)
    {
    	cout<<"\n"<<i+1<<") ";
    	P[i].display();
    }

}

int main()
{
    passenger *C; //array of object of passengers with confirmed tickets
    queue WL; //queue of passengers in waiting list
    int ch, tot;
    static int i = 0;

    cout<<"\nEnter total no. of confirmed tickets available: ";
    cin>>tot;

    C = new passenger[tot];
    passenger p;

    do{
        cout<<"\n**** RAILWAY RESERVATION SYSTEM ****";
        cout<<"\n0. Exit";
        cout<<"\n1. Book tickets";
        cout<<"\n2. Cancel tickets";
        cout<<"\n3. Display all confirmed tickets";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        getchar(); //'\n'
        cout<<"\n.................................";

        switch(ch)
        {
            case 0: cout<<"\n******* PROGRAM ENDED ********";
                    break;
            case 1: 	if(i < tot)
			{
				C[i].accept();
				cout<<"\nYour ticket is booked.";
				C[i].display();
				i++;
			}
            		else if(WL.is_full() == 1)
            			cout<<"\n Waiting List is full.";
			else{
				cout<<"\nAll confirmed tickets are booked. Your ticket will be added to the waiting list.";
				WL.enqueue();
			}
                    break;
            case 2: 	int PNR, pos;
			cout<<"\nEnter the PNR no. of the ticket to be cancelled: ";
			cin>>PNR;
			pos = passenger::search_PNR(C , tot , PNR);
			if(pos != -1)
			{
				if(!WL.is_empty())
				{
					p = WL.dequeue();
					C[pos] = p;
					cout<<"\n\nConfirmed next ticket on waiting list: ";
					C[pos].display();
				}
			}
			else //pos = -1
				cout<<"\nInvalid PNR !";
                    break;
            case 3: 	for(int i = 0 ; i<tot ; i++)
			{
				C[i].display();
				cout<<"\n-------------------------------------------";
			}
			break;

            default:cout<<"Invalid choice.";
        }

    }while(ch!=0);

    return 0;
}
