/*
 * Roll number:	2372
 * Name: Sejal Kshirsagar
 * C number: C22019221374
 *  
 * DSA 2 Lab #5 26/05/2021
 * Problem Statement:
			Perform following operation on Min heap or Max Heap
						1. Insert an element
						2. Delete an element from heap
						3. Build Heap
						4. Delete Heap
						Extra- Heap sort
 */
package heaps;

import java.util.Scanner;

abstract class Heap{
	int[] heap;
	int n;
	final static int MAX = 30;
	
	Heap(int N){
		n = N; 
		heap = new int[MAX];
	}

    void swap(int i, int j) {
        int tmp;
        tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }
    
    void bottomUpApproach() {}
	
    void downAdjustment(int i) {}
	
	void insert(Scanner sc) {}
	
	void upAdjustment(int i) {}
	
	void deleteRoot() {}
	
	void display() {
		for(int i=0; i<n; i++)
			System.out.print("\t"+heap[i]);
	}
	
	void print()
    {
		System.out.println();
        for (int i = 0; i<n/2; i++) {
            System.out.print(
                " Parent : " + heap[i]
                + "\tLeft Child : " + heap[2*i+1]
                + "\tRight Child : " + heap[2*i+2]);
            System.out.println();
        }
    }
	
}

class MaxHeap extends Heap{
	
	MaxHeap(int N){
		super(N);
	}
	//Build heap using bottom up approach
    void bottomUpApproach() {
    	for(int i=n/2 - 1; i>=0; i--)
    		downAdjustment(n, i);
    }
	
    //Reheapify using downadjustment
    //N is size of heap
    void downAdjustment(int N, int i) {
    	int L = 2*i + 1;
    	int R = 2*i + 2;
    	int largest = i;
    	
    	if(L<N && heap[L]>heap[largest])
    		largest = L;
    	if(R<N && heap[R]>heap[largest])
    		largest = R;
    	
    	if(largest != i) {
    		swap(i, largest);
    		downAdjustment(N, largest);
    	}
    }
	
    //Insert element in heap (Upadjacement)
	void insert(Scanner sc) {

		System.out.print("Enter value to insert: ");
		int val = sc.nextInt();
		
		if (n+1 == MAX)
			System.out.println("Heap overflow");
      else {
    	  n++;
    	  heap[n-1] = val; //insert after last
           upAdjustment(n-1);
       }
	}
	
	void upAdjustment(int i) {
		if(i > 0) {
			int parent = (i-1)/2;
    		if(heap[i] > heap[parent])
    			swap(i, parent);
    		upAdjustment(parent);
	    }
	}
	
	//Delete element
	void deleteRoot() {
		int last = heap[n-1];
		heap[0] = last; //replace root with last element
		heap[n-1] = 0; 
		n--;
		downAdjustment(n, 0);
	}
	
	    void heapSort()
	    {
	        for (int i = n - 1; i > 0; i--) {
	            swap(i, 0);// Move current root to end
	            
	            // call max heapify on the reduced heap
	            downAdjustment(i, 0);
	        }
	    }
}

class MinHeap extends Heap{
	
	MinHeap(int N){
		super(N);
	}
	//Build heap using bottom up approach
    void bottomUpApproach() {
    	for(int i=n/2 - 1; i>=0; i--)
    		downAdjustment(n, i);
    }
	
    //Reheapify using downadjustment
    void downAdjustment(int N, int i) {
    	int L = 2*i + 1;
    	int R = 2*i + 2;
    	int smallest = i;
    	
    	if(L<N && heap[L]<heap[smallest])
    		smallest = L;
    	if(R<N && heap[R]<heap[smallest])
    		smallest = R;
    	
    	if(smallest != i) {
    		swap(i, smallest);
    		downAdjustment(N, smallest);
    	}
    }
	
    //Insert element in heap (Upadjacement)
	void insert(Scanner sc) {

		System.out.print("Enter value to insert: ");
		int val = sc.nextInt();
		
		if (n+1 == MAX)
			System.out.println("Heap overflow");
      else {
    	  n++;
    	  heap[n-1] = val; //insert after last
           upAdjustment(n-1);
       }
	}
	
	void upAdjustment(int i) {
		if(i > 0) {
			int parent = (i-1)/2;
    		if(heap[i] < heap[parent])
    			swap(i, parent);
    		upAdjustment(parent);
	    }
	}
	
	//Delete element
	void deleteRoot() {
		int last = heap[n-1];
		heap[0] = last; //replace root with last element
		heap[n-1] = 0; 
		n--;
		downAdjustment(n, 0);
	}
	
	void heapSort()
    {
        for (int i = n-1; i>0; i--) {
            swap(i, 0);// Move current root to end
 
            // call min heapify on the reduced heap
            downAdjustment(i, 0);
        }
    }
}


public class Main {

	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		byte ch;
		
		do {
			System.out.println("\n************** HEAP **************");
			System.out.println("0. Exit");
			System.out.println("1. Buid Max Heap");
			System.out.println("2. Buid Min Heap");
			System.out.print("Enter your choice: ");
			ch = sc.nextByte();
			System.out.println("-------------------------------------");
			
			switch(ch) 
			{
			case 0: System.out.println("******** PROGRAM END *********");
					break;
					
			case 1: Main.maxHeapOp();
					break;
					
			case 2: Main.minHeapOp();
					break;
					
			default: System.out.println("Invalid choice.");
			}
			

		}while(ch!=0);

			sc.close();
	}
	
	static void maxHeapOp() {
		
		int ch;
		System.out.print("Enter number of elements: ");
		int M = sc.nextInt();
		MaxHeap hp = new MaxHeap(M);
		System.out.print("Enter elements: ");
		for(int i=0; i<M; i++) 
			hp.heap[i] = sc.nextInt();
		
		//create max heap
		hp.bottomUpApproach();
		System.out.println("Max Heap created: ");
		hp.display();
		
		do
		{
			System.out.println("\n********** MAX HEAP *************");
			System.out.println("0. Exit");
			System.out.println("1. Insert element in heap");
			System.out.println("2. Delete root");
			System.out.println("3. Display");
			System.out.println("4. Heap sort");
			System.out.print("Enter your choice: ");
			ch = sc.nextByte();
			System.out.println("-------------------------------------");
			
				switch(ch)
				{
				case 1: hp.insert(sc);
						System.out.println("Element has been inserted.");
						break;
				case 2: hp.deleteRoot();
						System.out.println("Root has been deleted.");
						break;
				case 3: System.out.println("MAX HEAP: ");
						hp.display(); 
						hp.print();
						break;
				case 4: hp.heapSort();
						System.out.println("Ascending Order:");
						hp.display();
						ch=0; break;
				default: System.out.println("Invalid choice.");
				}
		   }while(ch!=0);
	}
	
	static void minHeapOp() {
		
		int ch;
		System.out.print("Enter number of elements: ");
		int M = sc.nextInt();
		MinHeap hp = new MinHeap(M);
		System.out.print("Enter elements: ");
		for(int i=0; i<M; i++) 
			hp.heap[i] = sc.nextInt();
		
		//create min heap
		hp.bottomUpApproach();
		System.out.println("Min Heap created: ");
		hp.display();
		
		do
		{
			System.out.println("\n********** MIN HEAP *************");
			System.out.println("0. Exit");
			System.out.println("1. Insert element in heap");
			System.out.println("2. Delete root");
			System.out.println("3. Display");
			System.out.println("4. Heap sort");
			System.out.print("Enter your choice: ");
			ch = sc.nextByte();
			System.out.println("-------------------------------------");
			
				switch(ch)
				{
				case 1: hp.insert(sc);
						System.out.println("Element has been inserted.");
						break;
				case 2: hp.deleteRoot();
						System.out.println("Root has been deleted.");
						break;
				case 3: System.out.println("MIN HEAP: ");
						hp.display(); 
						hp.print();
						break;
				case 4: hp.heapSort();
						System.out.println("Descending Order:");
						hp.display();
						ch=0; break;
				default: System.out.println("Invalid choice.");
				}
				
		   }while(ch!=0);
	}

}

/******** TIME COMPLEXITY ***********
 * up/down Adjustment  O(log N) 
 * bottomUpApproach  O(N*log N) 
 * insert             O(log N)
 * delete             O(log N)
 * overall time complexity of Heap Sort is O(N*Log N)
 */

/************** INPUT ***************
  Max Heap:
  input: 1 3 5 4 6 13 10 9 8 15 17
 
                 17
              /      \
            15         13
          /    \      /  \
         9      6    5   10
        / \    /  \
       4   8  3    1 
 delete root
                 15
              /      \
            9         13
          /    \      /  \
         8      6    5   10
        / \    /  
       4   1  3 
 insert   14 
                 15
              /      \
            14         13
          /    \      /  \
         8      9    5   10
        / \    /  \
       4   1  3    6
  
  Min Heap: 
  input: 15 10 5 30
  
           5         
         /    \           
       10       15         
      /                    
    30    
   delete root
           10         
         /    \           
       30       15         
                          
       
   insert 1  
           1         
         /    \           
       10       15         
       /           
     30                          
 */
 
//*********** OUTPUT **************

/*
************** HEAP **************
0. Exit
1. Buid Max Heap
2. Buid Min Heap
Enter your choice: 2
-------------------------------------
Enter number of elements: 4
Enter elements: 15 10 5 30
Min Heap created: 
	5	10	15	30
********** MIN HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 2
-------------------------------------
Root has been deleted.

********** MIN HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 3
-------------------------------------
MIN HEAP: 
	10	30	15
 Parent : 10	Left Child : 30	Right Child : 15

********** MIN HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 1
-------------------------------------
Enter value to insert: 1
Element has been inserted.

********** MIN HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 3
-------------------------------------
MIN HEAP: 
	1	10	15	30
 Parent : 1	Left Child : 10	Right Child : 15
 Parent : 10	Left Child : 30	Right Child : 0

********** MIN HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 4
-------------------------------------
Descending Order:
	30	15	10	1
************** HEAP **************
0. Exit
1. Buid Max Heap
2. Buid Min Heap
Enter your choice: 1
-------------------------------------
Enter number of elements: 11
Enter elements: 1 3 5 4 6 13 10 9 8 15 17
Max Heap created: 
	17	15	13	9	6	5	10	4	8	3	1
********** MAX HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 3
-------------------------------------
MAX HEAP: 
	17	15	13	9	6	5	10	4	8	3	1
 Parent : 17	Left Child : 15	Right Child : 13
 Parent : 15	Left Child : 9	Right Child : 6
 Parent : 13	Left Child : 5	Right Child : 10
 Parent : 9	Left Child : 4	Right Child : 8
 Parent : 6	Left Child : 3	Right Child : 1

********** MAX HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 2
-------------------------------------
Root has been deleted.

********** MAX HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 3
-------------------------------------
MAX HEAP: 
	15	9	13	8	6	5	10	4	1	3
 Parent : 15	Left Child : 9	Right Child : 13
 Parent : 9	Left Child : 8	Right Child : 6
 Parent : 13	Left Child : 5	Right Child : 10
 Parent : 8	Left Child : 4	Right Child : 1
 Parent : 6	Left Child : 3	Right Child : 0

********** MAX HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 1
-------------------------------------
Enter value to insert: 14
Element has been inserted.

********** MAX HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 3
-------------------------------------
MAX HEAP: 
	15	14	13	8	9	5	10	4	1	3	6
 Parent : 15	Left Child : 14	Right Child : 13
 Parent : 14	Left Child : 8	Right Child : 9
 Parent : 13	Left Child : 5	Right Child : 10
 Parent : 8	Left Child : 4	Right Child : 1
 Parent : 9	Left Child : 3	Right Child : 6

********** MAX HEAP *************
0. Exit
1. Insert element in heap
2. Delete root
3. Display
4. Heap sort
Enter your choice: 4
-------------------------------------
Ascending Order:
	1	3	4	5	6	8	9	10	13	14	15
************** HEAP **************
0. Exit
1. Buid Max Heap
2. Buid Min Heap
Enter your choice: 0
-------------------------------------
******** PROGRAM END *********

*/