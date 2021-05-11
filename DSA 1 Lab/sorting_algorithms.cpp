/*
 * DSA 1 Lab #5:
 * 			Sorting Operations on first year student CGPA data using array.
 * 
 *  Created on: 10-May-2021
 *      Author: sejal 2372
 */
#include<iostream>
#define MAX 10
using namespace std;

class FY
{
public:
	int N;
	float arr[MAX];

	FY()
	{
		N = 0;
		arr[MAX] = {0};
	}

	void accept();
	void display();
};

void FY :: accept()
{
	cout<<"\nEnter number of FY students: ";
	cin>>N;
	for(int i=0; i<N; i++)
	{
		cout<<"Enter CGPA of student "<<i+1<<": ";
		cin>>arr[i];
	}
}

void FY :: display()
{
	for(int i=0; i<N; i++)
		cout<<arr[i]<<"\t";
}

void swap(float *a, float *b)
{
	float tmp = *a;
	*a = *b;
	*b = tmp;
}

//--------------------------------------------------------------------------------------------
/** BUBBLE SORT
 * Comparing each pair of adjacent items & swapping if they are in wrong order
 */
void bubble_sort_AO(float* arr, int N)
{
	for(int i=0; i<N-1; i++)
	{
		for(int j=0; j<N-1-i; j++)
		{
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
	cout<<"\nAscending order: ";
}

void bubble_sort_DO(float* arr, int N)
{
	for(int i=0; i<N-1; i++)
	{
		for(int j=0; j<N-1-i; j++)
		{
			if(arr[j] < arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
	cout<<"\nDescending order: ";
}

//--------------------------------------------------------------------------------------------
/** INSERTION SORT
 * Removes one element from unsorted data & insert it in correct position in already sorted data
 */
void insertion_sort_AO(float *arr, int N)
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

void insertion_sort_DO(float *arr, int N)
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

//--------------------------------------------------------------------------------------------
/** SELECTION SORT
 * Finds minimum value in unsorted list & swap it with element at first position
 */
void selection_sort_AO(float *arr, int N)
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

void selection_sort_DO(float *arr, int N)
{
	int i_min;
	for(int i=0; i<N-1; i++)
	{
		i_min = i;
		for(int j=i+1; j<N; j++)
		{
			if(arr[j] > arr[i_min])
				i_min = j;
		}
		swap(&arr[i], &arr[i_min]);
	}
	cout<<"\nDescending order: ";
}

//--------------------------------------------------------------------------------------------
/** QUICK SORT
 * Picks a pivot element & partition list with respect to pivot in to two parts.
 * Recursively solve left &right part.
 */
int partition_AO(float *arr, int si, int ei)
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

void quick_sort_AO(float *arr, int si, int ei)
{
	int mid;
	if(si < ei)
	{
		mid = partition_AO(arr, si, ei);
		quick_sort_AO(arr, si, mid);
		quick_sort_AO(arr, mid+1, ei);
	}
}


int partition_DO(float *arr, int si, int ei)
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

void quick_sort_DO(float *arr, int si, int ei)
{
	int mid;
	if(si < ei)
	{
		mid = partition_DO(arr, si, ei);
		quick_sort_DO(arr, si, mid);
		quick_sort_DO(arr, mid+1, ei);
	}
}


//--------------------------------------------------------------------------------------------
/** MERGE SORT
 * Divide list in to two parts.Then it sorts left & right part using merge sort.
 * Then merge two sublists in to one list.
 */
void merge_AO(float *arr, int low, int high, int mid)
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
		}else
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

void merge_sort_AO(float *arr, int low, int high)
{
	if(low<high)
	{
		int mid = (low + high)/2;
		merge_sort_AO(arr, low, mid);
		merge_sort_AO(arr, mid+1, high);
		merge_AO(arr, low, high, mid);
	}
}


void merge_DO(float *arr, int low, int high, int mid)
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
		}else
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

void merge_sort_DO(float *arr, int low, int high)
{
	if(low<high)
	{
		int mid = (low + high)/2;
		merge_sort_DO(arr, low, mid);
		merge_sort_DO(arr, mid+1, high);
		merge_DO(arr, low, high, mid);
	}
}


int main(){
	int ch;
	FY fy;
	do{
		cout<<"\n********** SORTING ALGORITHMS *************";
		cout<<"\n0. Exit";
		cout<<"\n1. Bubble Sort";
		cout<<"\n2. Insertion Sort";
		cout<<"\n3. Selection Sort";
		cout<<"\n4. Quick Sort";
		cout<<"\n5. Merge Sort";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		cout<<"\n--------------------------------------------";

		switch(ch)
		{
		case 0: cout<<"\n************ PROGRAM ENDED ***************";
				break;

		case 1: cout<<"\n******** BUBBLE SORT **********";
				fy.accept();
				bubble_sort_AO(fy.arr, fy.N);
				fy.display();
				bubble_sort_DO(fy.arr, fy.N);
				fy.display();
				break;

		case 2: cout<<"\n******** INSERTION SORT **********";
				fy.accept();
				insertion_sort_AO(fy.arr, fy.N);
				fy.display();
				insertion_sort_DO(fy.arr, fy.N);
				fy.display();
				break;

	   case 3: cout<<"\n******** SELECTION SORT **********";
				fy.accept();
				selection_sort_AO(fy.arr, fy.N);
				fy.display();
				selection_sort_DO(fy.arr, fy.N);
				fy.display();
				break;

	   case 4: cout<<"\n********** QUICK SORT ************";
				fy.accept();
				quick_sort_AO(fy.arr, 0, fy.N-1);
				cout<<"\nAscending order: ";
				fy.display();
				quick_sort_DO(fy.arr, 0, fy.N-1);
				cout<<"\nDescending order: ";
				fy.display();
				break;

	   case 5: cout<<"\n********** MERGE SORT ************";
				fy.accept();
				merge_sort_AO(fy.arr, 0, fy.N-1);
				cout<<"\nAscending order: ";
				fy.display();
				merge_sort_DO(fy.arr, 0, fy.N-1);
				cout<<"\nDescending order: ";
				fy.display();
				break;

		default: cout<<"\nInvalid choice.";
		}
	}while(ch!=0);
	return 0;
}

/*---------------------------------------------------------------------------------------------------
 * Method	   Best case	  Average case 	    Worst case	   Memory requirement	  Stable
 * --------------------------------------------------------------------------------------------------
 *
 * Bubble Sort.........O(n)............O(n^2)..........O(n^2)..............No................Yes
 *
 * Insertion Sort......O(n)............O(n^2)..........O(n^2)..............No................Yes
 *
 * Selection Sort......O(n^2)..........O(n^2)..........O(n^2)..............No................No
 *
 * Quick Sort..........O(nlogn)........O(nlogn)........O(n^2)..............No................No
 *
 * Merge Sort..........O(nlogn)........O(nlogn)........O(nlogn)............Yes...............Yes
 *
 * --------------------------------------------------------------------------------------------------
 */
