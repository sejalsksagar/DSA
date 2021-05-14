#include <iostream>
#define MAX 10

using namespace std;


class Arr{
    
    int len;
    int arr[MAX];

public:
    Arr(){
        arr[MAX] = {0};
    }
    void accept();
    void display();
    void insertion();
    void deletion();
    void arr_sum();
    void reverse_arr();
};

void Arr :: accept(){
    do{
        cout<<"\nEnter no. of elements: ";
        cin>>len;
    }while(MAX<len || len<=0);

    cout<<"Enter elements: ";
    for(int i=0; i<len; i++)
        cin>>arr[i]; 
}

void Arr :: display(){
    cout<<"\nDisplaying array elements: ";

    for(int i=0; i<len; i++)
        cout<<arr[i]<<" "; 
}

void Arr :: insertion(){
    int ele, pos;
    cout<<"Enter element to insert and position: ";
    cin>>ele>>pos;

    if(pos>MAX)
        cout<<"\nArray Overfow";
    else if(pos<1)
        cout<<"\nInvalid position";
    else{
        for(int i=len-1; i>=pos-1; i--) 
            arr[i+1]=arr[i];
        
        arr[pos-1]=ele; //inserting at pos-1 index
        len++;
    }
}

void Arr :: deletion(){
    if(len==0)
    {
        cout<<"\nArray is empty. No deletions possible.";
        return;
    }
    int pos;
    cout<<"\nEnter position of element to delete: ";
    cin>>pos;

    if(pos<0 || pos>len)
    {
       cout<<"\nInvalid position.";
       return; 
    }
        
    for(int i=pos-1; i<len; i++)
        arr[i]=arr[i+1];
    
    arr[len-1]=0;
    len--;
}

void Arr :: arr_sum(){
    int sum=0;

    for(int i=0; i<len; i++){
        sum+=arr[i];
    }
   cout<<"Sum of elements in the array: "<<sum; 
}

void Arr :: reverse_arr(){
    int tmp;

    for(int i=0; i<len/2; i++){
        tmp=arr[i];
        arr[i]=arr[len-1-i];
        arr[len-1-i]=tmp;
    }
}

int main()
{
    Arr a;
    int ch;
    a.accept();
    do{
        cout<<"\n\n******** ARRAY OPERATIONS *******";
        cout<<"\n0.Exit\n1.Display\n2.Insertion\n3.Deletion\n4.Sum of all elements\n5.Reverse array\nEnter your choice: ";
        cin>>ch;
        cout<<"\n----------------------------------\n";

        switch(ch)
        {
            case 0: cout<<"\n********** END **********"; break;
            case 1: a.display(); break;
            case 2: a.insertion(); break;
            case 3: a.deletion(); break;
            case 4: a.arr_sum(); break;
            case 5: a.reverse_arr(); break;
            default: cout<<"\nInvalid choice";
        }
    }while(ch!=0);

    return 0;
}
                                                                     
/********* TIME COMPLEXITY ************
 * accept()....................O(n)
 * display()...................O(n)
 * insertion().................O(n)
 * deletion()..................O(n)
 * arr_sum()...................O(n)
 * reverse_arr()...............O(n)
 * access......................O(1)
