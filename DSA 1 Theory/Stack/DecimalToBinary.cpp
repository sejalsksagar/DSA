//Decimal to binary using STACK ADT USING LINKED LIST
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
        void push(int d);
        void pop();
};

bool stack :: is_empty()
{
    if(top == NULL)
        return 1; //stack is empty
    else
        return 0;
}

void stack :: push(int d)
{
    node *tmp = new node(d);
    if(!is_empty())
        tmp->next = top; 
    top = tmp;
}

void stack :: pop()
{
    node *ptr;
    if(is_empty())
    {
        cout<<"\nStack Underflow";
        return;
    }

    ptr = top;
    cout<<top->data;
    top = top->next;
    delete ptr;
}

int main()
{
    int num;
    stack S;
    cout<<"Enter decimal no.: ";
    cin>>num;
    while(num!=0)
    {
        S.push(num%2);
        num=num/2;
    }
    while(S.is_empty() != 1)
        S.pop();

    return 0;
}
