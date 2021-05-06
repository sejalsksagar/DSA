/*
 *  Created on: 05-May-2021
 *      @author sejal 2372
 *
 * DSA 1 Lab #3:
 * 			Implement Stack as ADT using linked list or array.
 * 			Use the same ADT to evaluate a given postfix  expression.
 *
 */

//STACK using an Array
#include <iostream>
#include<math.h>
#define MAX 10

using namespace std;

class stack
{
    float data[MAX];
    int top;

    public:
        stack()
        {
            top = -1;
        }

        bool is_empty();
        bool is_full();
        void push(float x);
        float pop();
        void display_stack();
        void get_top();
        void exp_evaluation();
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

void stack :: push(float x)
{
    if(is_full() == 1)
        cout<<"\nCan't push. Stack Overflow";
    else
    {
        top++;
        data[top]=x;
        cout<<"\nPushed => "<<data[top];
    }
}

float stack :: pop()
{
    if(is_empty() == 1)
    {
    	cout<<"\nCan't pop. Stack Underflow";
    	return -1;
    }
    else
    {
        top--;
        cout<<"\nPopped "<<data[top+1];
        return data[top+1];
    }
}

void stack :: display_stack()
{
    if(is_empty() == 1)
        cout<<"\nCan't display. Stack is empty";
    else
    {
        for(int i=top; i>=0; i--)
        {
            cout<<"\n["<<i<<"]\t"<<data[i];
        }
    }
}

void stack :: get_top()
{
    if(is_empty() == 1)
        cout<<"\nCan't get top element. Stack is empty";
    else
    {
        cout<<"Top element => ";
        cout<<data[top];
    }
}


void exp_evaluation()
{
	stack S;
	char ch;
	float a, b;
	string postfix;
	cout<<"\nEnter postfix expression: ";
	cin>>postfix;

	for(int i=0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];

		if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')//operator
		{
			if (!S.is_empty())
				a = S.pop();
			else
			{
				cout << "Invalid expression. Try again.";//Stack underflow
				return;
			}

			if (!S.is_empty())
				b = S.pop();
			else
			{
				cout << "Invalid expression. Try again.";//Stack underflow
				return;
			}

			if(!S.is_full())
			{
				switch (ch)
				{
					case '+': S.push(b + a);
							  break;

					case '-': S.push(b - a);
							  break;

					case '*': S.push(b * a);
							  break;

					case '/': S.push(b / a);
							  break;

					case '^': S.push(pow(b, a));
							  break;
				}
			}
			else
			{
				cout << "\nStack overflow.";
				return;
			}

		}else
			S.push(ch - '0'); // -'0' to convert char to int
	}
	int ans = S.pop();
	cout << "\nPostfix Expression evaluation : "<< ans;
}


int main()
{
    stack S;
    int ch;
    float x;
    do{
        cout<<"\n______________________________";
        cout<<"\n***** STACK OPERATIONS *****";
        cout<<"\n(0) Exit";
        cout<<"\n(1) Push";
        cout<<"\n(2) Pop";
        cout<<"\n(3) Display Stack";
        cout<<"\n(4) Get top element";
        cout<<"\n(5) Evaluate expression using stack";
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

            case 5: exp_evaluation();
            		break;

            default: cout<<"\nInvalid choice";
        }
    }while(ch!=0);

    return 0;
}

