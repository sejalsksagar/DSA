//Polynomial ADT using SINGLY LINKED LIST
#include <iostream>
#include <cmath>

using namespace std;

class term
{
    int coef, exp;
    term *link;
    friend class poly;
    
    public:
        term()
        {
            link = NULL;
        }
};

class poly
{
    term *head;
    
    public:
        poly()
        {
            head = NULL;
        }
        
        term* create();
        void accept();
        void display();
        poly add(poly *p2);
        poly multiply(poly *p2);
        float eval(float x);
};

term* poly :: create() 
{
    term *tmp, *ptr;
    tmp = new term();
    if(head==NULL)
        head = tmp;
    else
    {
        ptr = head;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=tmp;
    }
    return tmp;
}

void poly :: accept()
{
    char ch;
    
    do{
        term *tmp = create();
        cout<<"\nEnter coefficient: ";
        cin>>tmp->coef;
        cout<<"Enter exponent: ";
        cin>>tmp->exp;
        
        cout<<"Add another term?(y/n): ";
        cin>>ch;
    }while(ch!='n');
}

void poly :: display()
{
    if(head==NULL)
    {
        cout<<"NO terms";
        return;
    }
    for(term *ptr=head; ptr!=NULL; ptr=ptr->link)
    {
        if(ptr->coef>=0)
            cout<<ptr->coef<<"x^("<<ptr->exp<<")";
        else
            cout<<"("<<ptr->coef<<")"<<"x^("<<ptr->exp<<")";

        if(ptr->link!=NULL)
            cout<<" + "; 
    }
}

poly poly :: add(poly *p2)
{
    poly S;
    term *P1=head, *P2=p2->head, *tmp, *ptr;

    while(P1!=NULL && P2!=NULL)
    {
        tmp = S.create();
        if(P1->exp == P2->exp)
        {
            tmp->coef=P1->coef + P2->coef;
            tmp->exp=P1->exp;
            P1=P1->link;
            P2=P2->link;
        }
        else if(P1->exp > P2->exp)
        {
            tmp->coef=P1->coef;
            tmp->exp=P1->exp;
            P1=P1->link;
        }
        else  //P1->exp > P2->exp
        {
            tmp->coef=P2->coef;
            tmp->exp=P2->exp;
            P2=P2->link;
        }       
    }

    while(P1!=NULL)
    {
        tmp = S.create();
        tmp->coef=P1->coef;
        tmp->exp=P1->exp;
        P1=P1->link;
    }

    while(P2!=NULL)
    {
        tmp = S.create();
        tmp->coef=P2->coef;
        tmp->exp=P2->exp;
        P2=P2->link;
    }
    return S;
}

poly poly :: multiply(poly *p2)
{
    poly M;
    term *ptr, *tmp;
    int flag, tmp_coef, tmp_exp;

    for(term *P1=head; P1!=NULL; P1=P1->link)
    {
        for(term *P2=p2->head; P2!=NULL; P2=P2->link)
        {
            tmp_coef=P1->coef*P2->coef;
            tmp_exp=P1->exp+P2->exp;
            flag=0;

            ptr=M.head;
            while(ptr!=NULL && flag==0)
            {
                if(ptr->exp == tmp_exp) //same degree
                {
                    flag=1;
                    break;
                }
                ptr=ptr->link;
            }
            if(flag==1)
            {
                ptr->coef += tmp_coef;
            }
            else
            {
                tmp = M.create();
                tmp->coef= tmp_coef;
                tmp->exp= tmp_exp;
            }
        }
    }
    return M;
}

float poly :: eval(float x)
{
    float ans=0;
    for(term* ptr=head; ptr!=NULL; ptr=ptr->link)
    {
        ans+=ptr->coef*pow(x, ptr->exp);
    }
    return ans;
}

int main()
{
    int ch;
    poly P1, *P2, R;

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
        cin>>ch;
        cout<<"____________________________________________________\n";
        
        switch(ch){
            case 0: cout<<"\n*********** PROGRAM ENDED SUCCESSFULLY ************";
                    break;
                    
            case 1: cout<<"\nP1(x) = ";
                    P1.display();
                    break;
                    
            case 2: cout<<"Enter another polynomial P2(x) :";
                    P2 = new poly();
                    P2->accept();
                    R = P1.add(P2);
                    cout<<"\nP1(x) = ";
                    P1.display();
                    cout<<"\nP2(x) = ";
                    P2->display();
                    cout<<"\nR(x) = P1(x) + P2(x) = ";
                    R.display();
                    delete P2;
                    break;
                    
            case 3: float x;
                    cout<<"\nEnter value of x to evaluate P1(x): ";
                    cin>>x;
                    cout<<"\nP1("<<x<<") = "<<P1.eval(x);
                    break;
                    
            case 4: cout<<"\nEnter another polynomial P2(x) :";
                    P2 = new poly();
                    P2->accept();
                    R = P1.multiply(P2);
                    cout<<"\nP1(x) = ";
                    P1.display();
                    cout<<"\nP2(x) = ";
                    P2->display();
                    cout<<"\nR(x) = P1(x) * P2(x) = ";
                    R.display();
                    delete P2;
                    break;
                    
            default: cout<<"\nInvalid choice";
        }
    }while(ch!=0);

    return 0;
}

