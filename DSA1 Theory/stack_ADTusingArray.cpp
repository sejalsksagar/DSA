//STACK ADT using an Array
#include <iostream>
#define MAX 5

using namespace std;

class stack
{
    int data[MAX];
    int top;
    
    public:
        stack()
        {
            top = -1;
        }

        bool is_empty();        //O(1)
        bool is_full();         //O(1)
        void push(int x);       //O(1)
        void pop();             //O(1)
        void display_stack();   //O(n)
        void get_top();         //O(1)
};

bool stack :: is_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

bool stack :: is_full()
{
    if(top >= MAX-1)
        return 1;
    else 
        return 0;
}

void stack :: push(int x)
{
    if(is_full())
        cout<<"\nCan't push. Stack Overflow";
    else 
    {
        top++;
        data[top]=x;
        cout<<"\nPushed => "<<data[top];
    }
}

void stack :: pop()
{
    if(is_empty())
        cout<<"\nCan't pop. Stack Underflow";
    else
    {
        cout<<"\nPopped => "<<data[top];
        top--;
    }
}

void stack :: display_stack()
{
    if(is_empty())
        cout<<"\nCan't display. Stack is empty";
    else 
    {
        for(int i=top; i>=0; i--)
            cout<<"\n["<<i<<"]\t"<<data[i];
    }
}

void stack :: get_top()
{
    if(is_empty())
        cout<<"\nCan't get top element. Stack is empty";
    else
    {
        cout<<"Top element => ";
        cout<<data[top];
    }
}

int main()
{
    stack S;
    int x, ch;
    do{
        cout<<"\n______________________________";
        cout<<"\n***** STACK OPERATIONS *****";
        cout<<"\n(0) Exit";
        cout<<"\n(1) Push";
        cout<<"\n(2) Pop";
        cout<<"\n(3) Display Stack";
        cout<<"\n(4) Get top element";
        cout<<"\nEnter you choice: ";
        cin>>ch;
        cout<<"______________________________\n";
        switch(ch)
        {
            case 0: cout<<"\n***** PROGRAM ENDED *****";
                    break;

            case 1: cout<<"\nEnter element to push: ";
                    cin>>x;
                    S.push(x);
                    break;

            case 2: S.pop();
                    break;

            case 3: S.display_stack();
                    break;

            case 4: S.get_top();
                    break;

            default: cout<<"\nInvalid choice";
        }
    }while(ch!=0);

    return 0;
}
