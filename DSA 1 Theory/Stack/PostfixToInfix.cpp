// POSTFIX TO INFIX CONVERSION
#include <iostream>
#define MAX 20

using namespace std;

class stack
{
    string data[MAX];
    int top;
    
    public:
        stack()
        {
            top = -1;
        }

        bool is_empty();
        bool is_full();
        void push(string s);
        string pop();
        string get_top();
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

void stack :: push(string s)
{
    if(is_full())
       return;
    else 
    {
        top++;
        data[top] = s;
    }
}

string stack :: pop()
{
    if(is_empty())
        return "";  
    else
    {
        top--;
        return data[top+1];
    }
}

string stack :: get_top()
{
    if(is_empty())
        return "";
    else
        return data[top];
}

void into_infix(string postfix)
{
    string s, s1, s2, infix;
    char ch;
    stack S;
    for(int i=0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')) //operand
        {
            s = ch;
            S.push(s);
        }else //operator
        {
            s = ch;
            s1 = S.pop();
            s2 = S.pop();
            S.push("("+s2+s+s1+")");
        }
    }
    infix = S.get_top();
    cout<<infix;
}

int main()
{
    string postfix;
    cout<<"Enter postfix expression: ";
    cin>>postfix;
    into_infix(postfix);
    return 0;
}
