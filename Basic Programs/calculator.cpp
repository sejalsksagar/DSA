/* Simple Calculator - Addition, Subtraction, Multiplication, Division */
#include<iostream>
using namespace std;

class calci{
  float num1, num2, ans;

  public:
   void accept();
   void addition();
   void subtraction();
   void multiplication();
   void division();

   void display(){
       cout<<"Result = "<<ans;
   }
};

void calci :: accept()
{
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;
}

void calci :: addition()
{
    ans = num1 + num2;
}

void calci :: subtraction()
{
    ans = num1 - num2;
}

void calci :: multiplication()
{
    ans = num1 * num2;
}

void calci :: division()
{
    ans = num1 / num2;
}

int main(){
    int ch;

    calci c;
    c.accept();

    do{
        cout<<"\n\n********* SIMPLE CALCULATOR *********";
        cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\nEnter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1: c.addition(); 
                    c.display(); 
                    break;

            case 2: c.subtraction(); 
                    c.display(); 
                    break;

            case 3: c.multiplication(); 
                    c.display(); 
                    break;

            case 4: c.division(); 
                    c.display(); 
                    break;

            case 5: cout<<"\n************ Program ended ************"; 
                    break;

            default: cout<<"\nInvalid choice";
        }
    }while(ch!=5);

    return 0;
}