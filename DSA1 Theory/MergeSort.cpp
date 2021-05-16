/** MERGE SORT
 * Divide list in to two parts.Then it sorts left & right part using merge sort.
 * Then merge two sublists in to one list.
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

void merge_AO_Arr(float *arr, int low, int high, int mid)
{
	int i = low, j = mid+1, k = 0;
	float tmp[high-low+1];
	while(i<=mid && j<=high)
	{
		if(arr[i] < arr[j])
		{
			tmp[k] = arr[i];
			i++;
			k++;
		}
        else
		{
			tmp[k] = arr[j];
			j++;
			k++;
		}
	}
	while(i <= mid)
	{
		tmp[k] = arr[i];
		i++;
		k++;
	}

	while(j <= high)
	{
		tmp[k] = arr[j];
		j++;
		k++;
	}

	for(i = low; i <= high; i++)
	{
		arr[i] = tmp[i-low];
	}
}

void merge_sort_AO_Arr(float *arr, int low, int high)
{
	if(low<high)
	{
		int mid = (low + high)/2;
		merge_sort_AO_Arr(arr, low, mid);
		merge_sort_AO_Arr(arr, mid+1, high);
		merge_AO_Arr(arr, low, high, mid);
	}
}


void merge_DO_Arr(float *arr, int low, int high, int mid)
{
	int i = low, j = mid+1, k = 0;
	float tmp[high-low+1];
	while(i<=mid && j<=high)
	{
		if(arr[i] > arr[j])
		{
			tmp[k] = arr[i];
			i++;
			k++;
		}
        else
		{
			tmp[k] = arr[j];
			j++;
			k++;
		}
	}
	while(i <= mid)
	{
		tmp[k] = arr[i];
		i++;
		k++;
	}

	while(j <= high)
	{
		tmp[k] = arr[j];
		j++;
		k++;
	}

	for(i = low; i <= high; i++)
	{
		arr[i] = tmp[i-low];
	}
}

void merge_sort_DO_Arr(float *arr, int low, int high)
{
	if(low<high)
	{
		int mid = (low + high)/2;
		merge_sort_DO_Arr(arr, low, mid);
		merge_sort_DO_Arr(arr, mid+1, high);
		merge_DO_Arr(arr, low, high, mid);
	}
}



int main(){

    cout<<"\n******** MERGE SORT **********";

    cout<<"\n\n******** FOR ARRAY **********";
    array A;
    A.accept();
    cout<<"\nGiven: ";
    A.display();

    merge_sort_AO_Arr(A.arr, 0, A.N-1 );
    A.display();
    merge_sort_DO_Arr(A.arr, 0, A.N-1 );
    A.display();
	
	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------
 * Method	   Best case	  Average case 	    Worst case	    Memory requirement	     Stable            Pros                    Cons
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 *
 * Merge Sort   omega(nlogn)   theta(nlogn)       O(nlogn)               Yes               Yes         1. Good for            1. Bad for applications which 
                                                                                                    external sorting.           runs on machines with 
                                                                                                                                limited memory.                                                  
 *
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 */
