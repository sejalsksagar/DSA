/** INSERTION SORT
 * Removes one element from unsorted data & insert it in correct position in already sorted data
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

void insertion_sort_AO_Arr(float *arr, int N)
{
	int j;
	float key;
	for(int i=1; i<N; i++)
	{
		key = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	cout<<"\nAscending order: ";
}

void insertion_sort_DO_Arr(float *arr, int N)
{
	int j;
	float key;
	for(int i=1; i<N; i++)
	{
		key = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	cout<<"\nDescending order: ";
}


int main(){

    cout<<"\n******** INSERTION SORT **********";

    cout<<"\n\n******** FOR ARRAY **********";
    array A;
    A.accept();
    cout<<"\nGiven: ";
    A.display();

    insertion_sort_AO_Arr(A.arr, A.N);
    A.display();
    insertion_sort_DO_Arr(A.arr, A.N);
    A.display();
	
	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------
 * Method	          Best case	  Average case 	    Worst case	    Memory requirement	     Stable            Pros                    Cons
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 *
 * Insertion Sort   omega(n)   theta(n^2)          O(n^2)               No               Yes          1.Good for            1. Inefficient
                                                                                                         almost                     for
                                                                                                         sorted data.         large data.
                                                                                                
 *
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 */
