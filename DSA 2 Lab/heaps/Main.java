/*
 * 2372 Sejal Kshirsagar
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

