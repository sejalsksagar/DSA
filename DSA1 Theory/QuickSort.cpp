/** QUICK SORT
 * Picks a pivot element & partition list with respect to pivot in to two parts.
 * Recursively solve left & right part.
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

int partition_AO_Arr(float *arr, int si, int ei)
{
	float pivot = arr[si];
	int i = si, j = ei;
	while(i < j)
	{
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if(i < j)
			swap(&arr[i], &arr[j]);
	}
	if(j < i)
		swap(&pivot, &arr[j]);
	return j;
}

void quick_sort_AO_Arr(float *arr, int si, int ei)
{
	int mid;
	if(si < ei)
	{
		mid = partition_AO_Arr(arr, si, ei);
		quick_sort_AO_Arr(arr, si, mid);
		quick_sort_AO_Arr(arr, mid+1, ei);
	}
}


int partition_DO_Arr(float *arr, int si, int ei)
{
	float pivot = arr[si];
	int i = si, j = ei;
	while(i < j)
	{
		while(arr[i] > pivot)
			i++;
		while(arr[j] < pivot)
			j--;
		if(i < j)
			swap(&arr[i], &arr[j]);
	}
	if(j < i)
		swap(&pivot, &arr[j]);
	return j;
}

void quick_sort_DO_Arr(float *arr, int si, int ei)
{
	int mid;
	if(si < ei)
	{
		mid = partition_DO_Arr(arr, si, ei);
		quick_sort_DO_Arr(arr, si, mid);
		quick_sort_DO_Arr(arr, mid+1, ei);
	}
}


int main(){

    cout<<"\n******** QUICK SORT **********";

    cout<<"\n\n******** FOR ARRAY **********";
    array A;
    A.accept();
    cout<<"\nGiven: ";
    A.display();

    quick_sort_AO_Arr(A.arr, 0, A.N-1 );
    A.display();
    quick_sort_DO_Arr(A.arr, 0, A.N-1 );
    A.display();
	
	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------
 * Method	   Best case	  Average case 	    Worst case	    Memory requirement	     Stable            Pros                    Cons
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 *
 * Quick Sort   omega(nlogn)   theta(nlogn)       O(n^2)               No               No          1. Extremely fast.            1. Complex
                                                                                                    2. Inherently                    algorithm.
                                                                                                       recursive.                        
                                                                                                
 *
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 */
