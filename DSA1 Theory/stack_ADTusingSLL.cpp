//STACK ADT USING LINKED LIST
#include <iostream>

using namespace std;

class node
{
    int data;
    node *next;
    friend class stack;
    
    public:
        node(int d)
        {
            data = d;
            next = NULL;
        }
};

class stack
{
    node *top;
    
    public:
        stack()
        {
            top = NULL;
        }
        
        bool is_empty();
        void push();
        void pop();
        void display();
        void get_top();
};

bool stack :: is_empty()
{
    if(top == NULL)
        return 1; //stack is empty
    else
        return 0;
}

void stack :: push()
{
    int d;
    cout<<"\nEnter data: ";
    cin>>d;

    node *tmp = new node(d);
    if(!is_empty())
        tmp->next = top; 
    top = tmp;
}

void stack :: pop()
{
    if(is_empty())
    {
        cout<<"\nStack Underflow";
        return;
    }

    node *ptr = top;
    cout<<"\nPopped => "<<top->data;
    top = top->next;
    delete ptr;
}

void stack :: display()
{
    if(is_empty())
    {
        cout<<"\nStack is empty";
        return;
    }
    cout<<"\nSTACK: TOP --> ";
    node* ptr = top;
    while(ptr!=NULL)
    {
        cout<<"[ "<<ptr->data<<", "<<ptr->next<<" ] --> ";
        ptr = ptr->next;
    }
    cout<<"NULL";
}

void stack :: get_top()
{
    if(is_empty())
        cout<<"\nCan't get top element. Stack is empty";
    else
    {
        cout<<"Top element => ";
        cout<<top->data;
    }
}

int main()
{
    int ch;
    stack S;
    do{
        cout<<"\n******* STACK *******";
        cout<<"\n(0) Exit";
        cout<<"\n(1) PUSH";
        cout<<"\n(2) POP";
        cout<<"\n(3) DISPLAY";
        cout<<"\n(4) GET TOP ELEMENT";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 0: cout<<"\n****** PROGRAM ENDED ******";
                    break;

            case 1: S.push();
                    break;

            case 2: S.pop();
                    break;

            case 3: S.display();
                    break;

            case 4: S.get_top();
                    break;

            default: cout<<"\nInvalid choice.";
        }
    }while(ch != 0);

    return 0;
}
