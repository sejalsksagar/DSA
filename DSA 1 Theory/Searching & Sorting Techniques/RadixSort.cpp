//Radix Sort - non-comparative sorting algorithm
#include<iostream>
#define MAX 10
using namespace std;

void display(int *arr)
{
	cout<<"\n";
	for(int i=0; i<MAX; i++)
		cout<<arr[i]<<", ";
}

//Time Complexity: O(nk)  n is the number of elements in the unsorted array and k is the range of input data
//Space Complexity: O(n+k)
void radix_sort(int* A)
{
	int bucket[10][MAX];

	int maxval = A[0];
	for (int i = 1; i < MAX; i++) // Find max element
	{
		if (A[i] > maxval)
			maxval = A[i];
	}

	int passes = 0;
	while (maxval != 0)
	{
		maxval = maxval / 10;
		passes++;  //no. of digits in maxval
	}

	int x = 1;
	do
	{
		int count[10] = {0}; // initialize count array elements to 0s

		int digit;
		for (int i = 0; i < MAX; i++)  //fill bucket according to x place digit
		{
			digit = (A[i] / x) % 10;
			bucket[digit][count[digit]] = A[i];
			count[digit]++;
		}

		int k = 0;
		for (int i = 0; i < 10; i++)  //output array
		{
			if (count[i] != 0)
			{
				for (int j = 0; j < count[i]; j++)
					A[k++] = bucket[i][j];
			}
		}
		x = x * 10;
		display(A);
	} while (--passes);

	cout<<"\nAscending order: ";
	display(A);
}

int main(){
	int arr[MAX] = {101, 1, 20, 50, 9, 98, 27, 153, 35, 899};

	cout<<"\nradix_sort";
	radix_sort(arr);
}

