/** BUBBLE SORT
 * Comparing each pair of adjacent items & swapping if they are in wrong order
 */
#include<iostream>
#define MAX 10
using namespace std;

/*........................ For Arrays .......................*/
class array
{
public:
	int N;
	float arr[MAX];

	array()
	{
		N = 0;
		arr[MAX] = {0};
	}

	void accept();
	void display();
};

void array :: accept()
{
	cout<<"\nEnter number of elements (for array): ";
	cin>>N;
	for(int i=0; i<N; i++)
	{
		cout<<"Enter data "<<i<<": ";
		cin>>arr[i];
	}
}

void array :: display()
{
    cout<<"\nArray: ";
	for(int i=0; i<N; i++)
		cout<<arr[i]<<"\t";
}

void swap(float *a, float *b)
{
	float tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort_AO_Arr(float* arr, int N)
{
    bool swaps;
	for(int i=0; i<N; i++)
	{
        swaps = false;
		for(int j=0; j<N-1-i; j++)
		{
			if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swaps = true;
            }
		}
        if(!swaps)
            break;
	}
	cout<<"\nAscending order: ";
}

void bubble_sort_DO_Arr(float* arr, int N)
{
    bool swaps;
	for(int i=0; i<N; i++)
	{
        swaps = false;
		for(int j=0; j<N-1-i; j++)
		{
			if(arr[j] < arr[j+1])
			{
                swap(&arr[j], &arr[j+1]);
                swaps = true;
            }
		}
        if(!swaps)
            break;
	}
	cout<<"\nDescending order: ";
}

/*........................ For Linked List .......................*/
class node
{
public:
    float data;
    node *next;

        node(int d)
        {
            data = d;
            next = NULL;
        }
};

class linked_list
{
public:
    int N;
    node *head;
    
        linked_list()
        {
            N = 0;
            head = NULL;
        }
        
        void create();  
        void display(); 
};

void linked_list :: create()
{
    node *ptr, *tmp;
    float d;
    char ch;
    do{
        cout<<"\nEnter value : ";
        cin>>d;
        
        tmp = new node(d);
        this->N++;
        
        if(head == NULL) 
            head = tmp;
        else
        {
            ptr = head;
            while(ptr->next!=NULL)
                ptr = ptr->next;
            
            ptr->next =  tmp;
        }

        cout<<"Add another node (y/n): ";
        cin>>ch;
    }while(ch!='n');
}

void linked_list :: display()
{
    if(head == NULL)
    {
        cout<<"\nList is empty";
        return;
    }

    cout<<"\nLinked List: HEAD --> ";
    node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<"[ "<<ptr->data<<", "<<ptr->next<<" ] --> ";
        ptr = ptr->next;
    }
    cout<<"NULL";
}

node* swap_adj_nodes(node* ptr1, node* ptr2)
{
    node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void bubble_sort_AO_SLL(node **head, int N)
{
    bool swaps;
    node **ptr;
    node *ptr1, *ptr2;
    
    for(int i=0; i<N; i++)
    {
	ptr = head;
	swaps = false;

	for(int j=0; j<N-1-i; j++)
	{
            ptr1 = *ptr;
            ptr2 = ptr1->next;

	   if(ptr1->data > ptr2->data)
            {
                *ptr = swap_adj_nodes(ptr1, ptr2);
                swaps = true;
            }

            ptr = &(*ptr)->next;
	}

        if(!swaps)
            break;
    }
	cout<<"\nAscending order: ";
}

void bubble_sort_DO_SLL(node **head, int N)
{
    bool swaps;
    node **ptr;
    node *ptr1, *ptr2;
    
    for(int i=0; i<N; i++)
    {
        ptr = head;
        swaps = false;

	for(int j=0; j<N-1-i; j++)
	{
            ptr1 = *ptr;
            ptr2 = ptr1->next;

	    if(ptr1->data < ptr2->data)
            {
                *ptr = swap_adj_nodes(ptr1, ptr2);
                swaps = true;
            }

            ptr = &(*ptr)->next;
	}

        if(!swaps)
            break;
    }
	cout<<"\nDescending order: ";
}

int main()
{

    cout<<"\n******** BUBBLE SORT **********";

    cout<<"\n\n******** FOR ARRAY **********";
    array A;
    A.accept();
    cout<<"\nGiven: ";
    A.display();

    bubble_sort_AO_Arr(A.arr, A.N);
    A.display();
    bubble_sort_DO_Arr(A.arr, A.N);
    A.display();

    cout<<"\n---------------------------------";

    cout<<"\n\n******** FOR LINKED LIST ********";
    linked_list L;
    L.create();
    cout<<"\nGiven: ";
    L.display();

    bubble_sort_AO_SLL(&L.head, L.N);
    L.display();
    bubble_sort_DO_SLL(&L.head, L.N);
    L.display();
	
	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------
 * Method	        Best case	   Average case 	   Worst case	    Memory requirement	     Stable            Pros                    Cons
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 *
 * Bubble Sort     omega(n)     theta(n^2)         O(n^2)               No                 Yes          1.Simple &              1. Highly
                                                                                                        easy method.            inefficient
                                                                                                        2.Efficient for         for large data.
                                                                                                        small list.
 *
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 */
