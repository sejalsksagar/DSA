//Searching Algorithms
#include<iostream>
#define MAX 5
using namespace std;

//For unsorted data
//1. Sequential Search: O(n)
void sequential_search(int arr[], int key)
{
	bool flag = 0;
	int pos;
	for(int i=0; i<MAX; i++)
	{
		if(arr[i] == key)
		{
			flag = 1;
			pos = i;
			break;
		}
	}

	if(flag == 1)
		cout<<"\nKey found at position: "<<pos;
	else
		cout<<"\nKey not found";
}

//For sorted data
//2.a. Binary Search: 
// Time complexity O(logn)
// Space Complexity O(1)
void binary_search(int arr[], int key)
{
	int low = 0;
	int high = MAX-1;
	int mid;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(arr[mid] == key)
		{
			cout<<"\nKey found at position: "<<mid;
			return;
		}
		else if(key < arr[mid])
			high = mid - 1;
		else //key > arr[mid]
			low = mid + 1;
	}

	cout<<"\nKey not found";
}

//2.b. Recursive Binary Search:
// Time complexity O(logn) 
// Space Complexity O(logn)
// Binary Search is more efficient
void recur_binary_search(int arr[], int key, int low, int high)
{
	int mid;
	if(low <= high)
	{
		mid = (low + high)/2;
		if(arr[mid] == key)
		{
			cout<<"\nKey found at position: "<<mid;
			return;
		}
		else if(key < arr[mid])
			recur_binary_search(arr, key, low, mid-1);
		else //key > arr[mid]
			recur_binary_search(arr, key, mid+1, high);
	}
}

int main(){
	int arr[MAX] = {10, 20, 30 , 40, 50 };
	int key = 40;
	cout<<"\nSequential Search";
	sequential_search( arr, key);
	cout<<"\nBinary Search";
	binary_search( arr, key);
	cout<<"\nRecursive Binary Search";
	recur_binary_search( arr, key, 0, MAX-1);
}
