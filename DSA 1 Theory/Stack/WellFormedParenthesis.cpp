//Well formed parenthesis STACK ADT USING LINKED LIST
#include <iostream>

using namespace std;

class node
{
    char data;
    node *next;
    friend class stack;
    
    public:
        node(char d)
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
        void push(char d);
        char pop();
        void display();
};

bool stack :: is_empty()
{
    if(top == NULL)
        return 1; //stack is empty
    else
        return 0;
}

void stack :: push(char d)
{
    node *tmp = new node(d);
    if(!is_empty())
        tmp->next = top; 
    top = tmp;
}

char stack :: pop()
{
    if(is_empty())
        return '\0';

    node *ptr = top;
    int d = top->data;
    top = top->next;
    delete ptr;
    return d;
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

int main()
{
    char x;
    bool flag=0;
    string E;
    stack S;
    cout<<"Enter infix expression: ";
    cin>>E;
    
    for(int i=0; E[i]!='\0'; i++)
    {
        if(E[i]=='('||E[i]=='['||E[i]=='{')
        {
            S.push(E[i]);
        }
        if(E[i]==')'||E[i]==']'||E[i]=='}')
        {
            x = S.pop();
            
            if((E[i]==')' && x!='(')||(E[i]==']' && x!='[')||(E[i]=='}' && x!='{'))
            {
                flag = 1;
                break;
            }
        }
    }
    
    if(S.is_empty() && flag==0)
        cout<<"Balanced";
    else
        cout<<"Unbalanced";

    return 0;
}
