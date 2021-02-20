/* Calculate average salary of IT department employees */
#include<iostream>
#define MAX 2
using namespace std;

class employee
{
    public:
        int employeeID;
        string full_name;
        string department;
        string address;
        int salary;
};

class database 
{
   
    int tot_emp = MAX;
    employee employee[MAX];
    
     public:   
       void accept();
       void display();    
       void avg_IT_salary();
};


void database :: accept()
{
    for(int i=0; i<tot_emp; i++){
        cout<<"********** INPUT EMPLOYEE INFO **********";
        cout<<"\nEmployee id : ";
        cin>>employee[i].employeeID;
        getchar();
        
        cout<<"Full Name : ";
        getline(cin, employee[i].full_name);
        
        cout<<"Address : ";
        getline(cin, employee[i].address);  
        
        cout<<"Salary : ";
        cin>>employee[i].salary;
        getchar();
        
        cout<<"Department : ";
        getline(cin, employee[i].department);
    }
}

void database :: display()
{
    cout<<"\n********** EMPLOYEE DATABASE **********";
    for(int i=0; i<tot_emp; i++)
    {
        cout<<"\nEmployee ID : "<< employee[i].employeeID;
        
        cout<<"\nFull Name : "<< employee[i].full_name;
        
        cout<<"\nAddress : "<< employee[i].address;
      
        cout<<"\nSalary : "<< employee[i].salary;
    
        cout<<"\nDepartment : "<< employee[i].department;
        
        cout<<"\n-----------------------------------------";
    }
}


void database :: avg_IT_salary()
{
    int sum_IT_salary = 0;
    int num_IT_emp = 0;
    float avg_IT_sal;
    
    for(int i=0; i<tot_emp; i++)
    {
        if(employee[i].department == "it" || employee[i].department == "IT" || employee[i].department == "It")
        {
            sum_IT_salary += employee[i].salary;
            num_IT_emp++;
        }
    }
    
    avg_IT_sal = sum_IT_salary / num_IT_emp;
    cout<<"\nAverage IT Salary: "<<avg_IT_sal;
    
}


int main()
{
    database employeeDB;
    employeeDB.accept();
    employeeDB.display();
    employeeDB.avg_IT_salary();

    return 0;
}

