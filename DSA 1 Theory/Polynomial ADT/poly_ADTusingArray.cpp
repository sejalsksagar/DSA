//Polynomial ADT using Arrays
#include <iostream>
#include <cmath>

using namespace std;

class Term
{
    public:
    int deg, coef;
    
    Term()
    {
        deg = 0;
        coef = 0;
    }
    
};

class Polynomial
{
    int maxTerms = 20;
    Term T[20];
    int numTerms;
    
    public:
        void accept();
        void display();
        void polySum(Polynomial P1, Polynomial P2);
        void evaluate(int x);
        void polyMultiply(Polynomial P1, Polynomial P2);
};

void Polynomial :: accept()
{
    cout<< "\nEnter number of terms in the Polynomial (Max Terms: "<<maxTerms<<") : ";
    cin>>numTerms;
    if((numTerms>maxTerms) || (numTerms<0))
    {
        cout<<"\nInvalid number of terms";
        return;
    }
    
    for(int i=0; i<numTerms; i++)
    {
        cout<<"Enter coefficient: ";
        cin>> T[i].coef;
        cout<<"Enter degree: ";
        cin>> T[i].deg;
    }
}

void Polynomial :: display()
{
    for(int i=0; i<numTerms; i++)
    {
        if(T[i].coef>=0)
        {
            cout<<T[i].coef<<"x^("<<T[i].deg<<")";
        }
        else  // T[i].coef<0
        {
            cout<<"("<<T[i].coef<<")"<<"x^("<<T[i].deg<<")";
        }
        
        if(i!=numTerms-1)
                cout<<" + ";
    }
}

void Polynomial :: polySum(Polynomial P1, Polynomial P2)
{
    numTerms = 0;
    int i=0, j=0;
    
    while(i<P1.numTerms && j<P2.numTerms)
    {
        if(P1.T[i].deg == P2.T[j].deg)
        {
            T[numTerms].coef = P1.T[i].coef + P2.T[j].coef;
            T[numTerms].deg = P1.T[i].deg;
            i++; j++;
            numTerms++;
        }
        else if(P1.T[i].deg > P2.T[j].deg)
        {
            T[numTerms].coef = P1.T[i].coef;
            T[numTerms].deg = P1.T[i].deg;
            i++; 
            numTerms++;
        }
        else  //P1.T[i].deg < P2.T[j].deg
        {
            T[numTerms].coef = P2.T[i].coef;
            T[numTerms].deg = P2.T[i].deg;
            j++;
            numTerms++;
        }
    }
    
    while(i<P1.numTerms)
    {
        T[numTerms].coef = P1.T[i].coef;
        T[numTerms].deg = P1.T[i].deg;
        i++;
        numTerms++;
    }
        
    while(j<P2.numTerms)
    {
        T[numTerms].coef = P2.T[i].coef;
        T[numTerms].deg = P2.T[i].deg;
        j++;
        numTerms++;
    }
}

void Polynomial :: evaluate(int x)
{
    int answer = 0;
    for(int i=0; i<numTerms; i++)
        answer += T[i].coef*pow(x, T[i].deg);
    
    cout<<"\nP1("<<x<<") = "<<answer;
}

void Polynomial :: polyMultiply(Polynomial P1, Polynomial P2)
{
    numTerms = 0;
    int k, flag, tempCoef, tempDeg;
    
    for(int i=0; i<P1.numTerms; i++)
    {
        for(int j=0; j<P2.numTerms; j++)
        {
            tempCoef = P1.T[i].coef * P2.T[j].coef;
            tempDeg = P1.T[i].deg + P2.T[j].deg;
            flag = 0;
            
            k = 0;
            while(k<numTerms && flag==0)
            {
                if(T[k].deg == tempDeg) // same degree
                {
                    flag = 1;
                    break;
                }
                k++;
            }
            
            if(flag == 1)  // result contains 2 terms with same degree
            {
                T[k].coef += tempCoef;  // update term coefficient
            }
            else 
            {
                T[numTerms].coef = tempCoef;
                T[numTerms].deg = tempDeg;
                numTerms++;
            }
        }
    }
}

int main()
{
    int choice, x;
    Polynomial P1, P2, R;
    
    cout<<"For a polynomial P1(x) :";
    P1.accept();
    do{
        cout<<"\n*************** POLYNOMIAL OPERATIONS ***************";
        cout<<"\n0. Exit";
        cout<<"\n1. Display P1(x)";
        cout<<"\n2. Find sum of P1(x) and another polynomial P2(x)";
        cout<<"\n3. Evaluate P1(x)";
        cout<<"\n4. Multiply P1(x) and another polynomial P2(x)";
        cout<<"\nEnter your choice:  ";
        cin>>choice;
        cout<<"____________________________________________________\n";
        
        switch(choice){
            case 0: cout<<"\n*********** PROGRAM ENDED SUCCESSFULLY ************";
                    break;
                    
            case 1: cout<<"\nP1(x) = ";
                    P1.display();
                    break;
                    
            case 2: cout<<"Enter another polynomial P2(x) :";
                    P2.accept();
                    R.polySum(P1, P2);
                    cout<<"\nP1(x) = ";
                    P1.display();
                    cout<<"\nP2(x) = ";
                    P2.display();
                    cout<<"\nR(x) = P1(x) + P2(x) = ";
                    R.display();
                    break;
                    
            case 3: cout<<"\nEnter value of x to evaluate P1(x): ";
                    cin>>x;
                    P1.evaluate(x);
                    break;
                    
            case 4: cout<<"\nEnter another polynomial P2(x) :";
                    P2.accept();
                    R.polyMultiply(P1, P2);
                    cout<<"\nP1(x) = ";
                    P1.display();
                    cout<<"\nP2(x) = ";
                    P2.display();
                    cout<<"\nR(x) = P1(x) * P2(x) = ";
                    R.display();
                    break;
                    
            default: cout<<"\nInvalid choice";
        }
    }while(choice!=0);
    
    return 0;
}
