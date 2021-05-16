/** SELECTION SORT
 * Finds minimum value in unsorted list & swap it with element at first position
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

void selection_sort_AO_Arr(float *arr, int N)
{
	int i_min;
	for(int i=0; i<N-1; i++)
	{
		i_min = i;
		for(int j=i+1; j<N; j++)
		{
			if(arr[j] < arr[i_min])
				i_min = j;
		}
		swap(&arr[i], &arr[i_min]);
	}
	cout<<"\nAscending order: ";
}

void selection_sort_DO_Arr(float *arr, int N)
{
	int i_max;
	for(int i=0; i<N-1; i++)
	{
		i_max = i;
		for(int j=i+1; j<N; j++)
		{
			if(arr[j] > arr[i_max])
				i_max = j;
		}
		swap(&arr[i], &arr[i_max]);
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

void selection_sort_AO_SLL(node *head, int N)
{
    node *min;
    
	for(node *tmp=head; tmp->next!=NULL; tmp=tmp->next)
	{
        min = tmp;

		for(node *ptr=tmp->next; ptr!=NULL; ptr=ptr->next)
		{
			if(ptr->data < min->data)
                min = ptr;
		}

        //swap data
        int d = tmp->data;
        tmp->data = min->data;
        min->data = d;
	}
	cout<<"\nAscending order: ";
}

void selection_sort_DO_SLL(node *head, int N)
{
    node *max;
    
	for(node *tmp=head; tmp->next!=NULL; tmp=tmp->next)
	{
        max = tmp;

		for(node *ptr=tmp->next; ptr!=NULL; ptr=ptr->next)
		{
			if(ptr->data > max->data)
                max = ptr;
		}

        //swap data
        int d = tmp->data;
        tmp->data = max->data;
        max->data = d;
	}
	cout<<"\nDescending order: ";
}

int main(){

    cout<<"\n******** SELECTION SORT **********";

    cout<<"\n\n******** FOR ARRAY **********";
    array A;
    A.accept();
    cout<<"\nGiven: ";
    A.display();

    selection_sort_AO_Arr(A.arr, A.N);
    A.display();
    selection_sort_DO_Arr(A.arr, A.N);
    A.display();

    cout<<"\n---------------------------------";

    cout<<"\n\n******** FOR LINKED LIST ********";
    linked_list L;
    L.create();
    cout<<"\nGiven: ";
    L.display();

    selection_sort_AO_SLL(L.head, L.N);
    L.display();
    selection_sort_DO_SLL(L.head, L.N);
    L.display();
	
	return 0;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------
 * Method	   Best case	  Average case 	    Worst case	    Memory requirement	     Stable            Pros                    Cons
 * --------------------------------------------------------------------------------------------------------------------------------------------------------
 *
 * Selection Sort   omega(n)       theta(n^2)        O(n^2)               No                   No          1.For small list.              1. Inefficient
                                                                                                                                              for
                                                                                                           2.Good for partially              large data.
                                                                                                             sorted data.
 *
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------
 */
