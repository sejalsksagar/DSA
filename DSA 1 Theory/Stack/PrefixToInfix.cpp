//PREFIX TO INFIX CONVERSION
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
        void push(string x);
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

void stack :: push(string x)
{
    if(is_full())
       return;
    else 
    {
        top++;
        data[top]=x;
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

string reverse(string prefix)
{
    char tmp;
    int l = 0, i = 0; //length
    while(prefix[i] != '\0')
        i++;
    
    l = i-1;
    for (int i = 0; i < l/2; i++)
    {
        tmp = prefix[i];
        prefix[i] = prefix[l-i];
        prefix[l-i] = tmp;
    }
    return prefix;
}

void into_inf(string prefix)
{
    string s, s1, s2, infix;
    char ch;

    prefix = reverse(prefix); //scan R to L
    stack S;
    for(int i=0; prefix[i] != '\0'; i++)
    {
        ch = prefix[i];

        if(ch>='a' && ch<='z') //operand
        {
            s = ch;
            S.push(s);
        }
        else //operator
        {
            s = ch;
            s1 = S.pop();
            s2 = S.pop();
            S.push("("+s1+s+s2+")");
        }
    }
    infix = S.get_top();
    cout<<infix;
}

int main()
{
    string prefix;
    cout<<"Enter prefix expression: ";
    cin>>prefix;
    into_inf(prefix);
    return 0;
}
