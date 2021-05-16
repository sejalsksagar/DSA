//Postfix Expression evaluation using STACK ADT USING LINKED LIST
#include <iostream>
#include <cmath>

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
        int pop();
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

int stack :: pop()
{
    if(is_empty())
    {
        cout<<"\nStack Underflow";
        return -1;
    }

    node *ptr = top;
    int d = top->data;
    top = top->next;
    delete ptr;
    return d;
}

void postfix_exp_eval()
{
	stack S;
	char ch;
	float s1, s2;
	string postfix;
	cout<<"\nEnter postfix expression: ";
	cin>>postfix;

	for(int i=0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];

		if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')//operator
		{
            s1 = S.pop();
        
            s2 = S.pop();

            switch (ch)
            {
                case '+': S.push(s2 + s1);
                            break;

                case '-': S.push(s2 - s1);
                            break;

                case '*': S.push(s2 * s1);
                            break;

                case '/': S.push(s2 / s1);
                            break;

                case '^': S.push(pow(s2, s1));
                            break;
            }

		}else
			S.push(ch - '0'); // -'0' to convert char to int
	}
	int ans = S.pop();
	cout << "\nPostfix Expression evaluation : "<< ans;
}


int main()
{
    postfix_exp_eval();

    return 0;
}

