//INFIX TO PREFIX CONVERSION
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
    if(is_full())
       return;  
    else 
    {
        top++;
        data[top]=x;
    }
}

char stack :: pop()
{
    if(is_empty())
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

int ICP(char ch)
{
    switch(ch)
    {
        case '^': return 4;
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        case '(': return 4;
        default: return -1;
    }
}

void reverse(char* infix)
{
    char tmp;
    int l = 0, i = 0; //l for length
    while(infix[i] != '\0')
        i++;
    
    l = i-1;
    for (int i = 0; i < l/2; i++)
    {
        tmp = infix[i];
        infix[i] = infix[l-i];
        infix[l-i] = tmp;
    }
}

void into_pre(char infix[20])
{
    string prefix="";
    char ch, x;
    reverse(infix); //Scan from R to L

    int i = 0; 
    stack S;
    while(infix[i] != '\0')
    {
        ch = infix[i];
        i++;
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')) //operand
        {
            prefix = ch + prefix;
        }
        else if(ch == ')')
        {
            S.push(ch);
        }
        else if(ch == '(')
        { 
            while(S.get_top() != ')')
            {
                x = S.pop();
                prefix = x + prefix;
            }
            x = S.pop(); //')'
        }
        else
        {               
            while(ISP(S.get_top()) > ICP(ch))
            {
                x = S.pop();
                prefix = x + prefix;
            }                    
            S.push(ch);           
        }   
        
    }
    while(!S.is_empty()){
        x = S.pop();
        prefix = x + prefix;
    }
    cout<<prefix;
}

int main()
{
    char infix[20];
    cout<<"Enter Infix expression: ";
    cin>>infix;
    into_pre(infix);
    return 0;
}
