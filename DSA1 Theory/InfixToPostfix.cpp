//INFIX TO POSTFIX CONVERSION
#include <iostream>
#define MAX 20

using namespace std;

class stack
{
    char data[MAX];
    int top;
    
    public:
        stack()
        {
            top = -1;
        }

        bool is_empty();
        bool is_full();
        void push(char x);
        char pop();
        char get_top();
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

void stack :: push(char x)
{
    if(is_full()) //Stack Overflow
       return;
    else 
    {
        top++;
        data[top] = x;
    }
}

char stack :: pop()
{
    if(is_empty()) //Stack Underflow
        return -1; 
    else
    {
        top--;
        return data[top+1];
    }
}


char stack :: get_top()
{
    if(is_empty())
        return -1;
    else
        return data[top];
}

//InStack Priority 
int ISP(char ch)
{
    switch(ch)
    {
        case '(': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

//InComming Priority
int ICP(char ch)
{
    switch(ch)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 4;
        case '(': return 4;
        default: return -1;
    }
}

void into_post(char infix[20])
{
    char ch, x;
    int i = 0;
    stack S;
    while(infix[i] != '\0')
    {
        ch = infix[i];
        i++;
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')) //operand
        {
            cout<<ch;
        }
        else if(ch == ')')
        { 
            while(S.get_top() != '(')
            {
                x = S.pop();
                cout<<x;
            }
            x = S.pop(); //'('
        }
        else//operator
        {
            while(ISP(S.get_top()) >= ICP(ch))
            {
                x = S.pop();
                cout<<x;
            }
            S.push(ch);
        }   
        
    }
    while(S.is_empty() != 1){
        x = S.pop();
        cout<<x;
    }
}

int main()
{
    char infix[20];
    cout<<"Enter Infix expression: ";
    cin>>infix;
    into_post(infix);
    return 0;
}
