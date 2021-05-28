/**
 * Roll number:	2372
 * Name: Sejal Kshirsagar
 * C number: C22019221374
 *  
 * DSA 2 Lab #6 28/05/2021
 * Problem Statement:
		Implement a hash table for storing bank account information. Handle the collision using
		linear probing without replacement. Perform operations on it.
 */

package hashTable;

import java.util.Scanner;

class Customer {
	long id;
	String name;
	double balance;

	Customer(Scanner sc) {
		System.out.print("Enter customer id: ");
		id = sc.nextLong();
		sc.nextLine();
		System.out.print("Enter customer name: ");
		name = sc.nextLine();
		System.out.print("Enter bank balance: ");
		balance = sc.nextDouble();
	}
	
	void display() {
		
		System.out.println("Customer id: "+id);
		System.out.println("Name: "+name);
		System.out.println("Bank Balance: "+balance);
		System.out.println("--------------------------------");
	}

}

class Table {
	int size;
	int hashadress;
	final static int MAX_SIZE = 10;
	Customer hashtable[] = new Customer[MAX_SIZE];
	
	Table(){
		size = 0;
	}
	
	void clearTable() {
		for (int i = 0; i < MAX_SIZE; i++) 
			hashtable[i] = null;
	}
	
	boolean isFull() {
		if(size==MAX_SIZE)
			return true;
		else
			return false;
	}
	
	int hash(long id)
	{
		return (int)id % MAX_SIZE;
	}
	
	
	void create(Scanner sc)
	{
		if(isFull()) {
			System.out.println("Hash Table is full.");
			return;
		}
		Customer c = new Customer(sc);
		int i = hash(c.id);
		
		boolean placed = false;
		while(!placed) {
			if(hashtable[i]==null) {
				hashtable[i] = c;
				size++;
				placed = true;
			}
			else 
				i = (i + 1) % MAX_SIZE;			
		}
	}
	
	void display()
	{
		System.out.println("\t****** CUSTOMER HASH TABLE *********");
		System.out.format("\n %10s %10s %15s %15s", "Index", "ID", "Customer Name", "Balance");
		for (int i = 0; i < MAX_SIZE; i++) {

			if(hashtable[i]!=null) 
				System.out.format("\n %10d %10s %15s %15f", i, hashtable[i].id, hashtable[i].name, hashtable[i].balance);
			else
				System.out.format("\n %10d ", i);
		}
	}
	
	Customer search(Scanner sc)
	{
		System.out.print("Enter customer id to search: ");
		long key = sc.nextLong();
		int i = hash(key);
		boolean stop = false;
		int counter = 0;
		while(!stop) {
			if(hashtable[i]!=null && hashtable[i].id==key) {
				System.out.println("Customer found.");
				hashtable[i].display();
				return hashtable[i];
			}
			else 
				i = (i + 1) % MAX_SIZE;	
			counter++;
			if(counter==MAX_SIZE) {
				System.out.println("Customer with entered id NOT found");
				stop = true;
			}
		}
		return null;
	}
	
	void delete(Scanner sc)
	{
		System.out.print("Enter customer id to delete: ");
		long key = sc.nextLong();
		
		int counter = 0;
		int i = hash(key);
		boolean stop = false;
		
		while(!stop) {
			if(hashtable[i]!=null && hashtable[i].id==key) {
				hashtable[i] = null;
				size--;
				System.out.println("Customer account has been deleted.");
				return;
			}
			else i = (i + 1) % MAX_SIZE;	
			
			counter++;
			if(counter==MAX_SIZE) {
				System.out.println("Customer with entered id NOT found");
				stop = true;
			}
		}
	}

}

public class LinearProbing {

	public static void main(String[] args) {
		
		byte ch;
		Table T = new Table();
		Scanner sc = new Scanner(System.in);
		do {
			System.out.println("\n_____________________________________");
			System.out.println("******** BANK ACCOUNT INFO ********");
			System.out.println("0. Exit");
			System.out.println("1. Add new customer");
			System.out.println("2. Display all customers");
			System.out.println("3. Search a customer");
			System.out.println("4. Delete a customer");
			System.out.print("Enter your choice: ");
			ch = sc.nextByte();
			System.out.println("_____________________________________");
			
			switch(ch) {
				case 0: System.out.println("********** PROGRAM END ***********");
				break;
				case 1: T.create(sc); //insert
				break;
				case 2: T.display();
				break;
				case 3: T.search(sc);
				break;
				case 4: T.delete(sc);
				break;
				default: System.out.println("Invalid choice.");
			}
		}while(ch!=0);

	}
}

/******** TIME COMPLEXITY ***********
 * insert....................O(n)
 * display...................O(n)
 * search....................O(n)
 * delete....................O(n)
 */


//************** OUTPUT **************
/*

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 21
Enter customer name: Shravani J.
Enter bank balance: 786768

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 31
Enter customer name: Aditi S.
Enter bank balance: 767987

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 41
Enter customer name: Gayatri K.
Enter bank balance: 676567

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 42
Enter customer name: Harsh P.
Enter bank balance: 767867

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 67
Enter customer name: Maya R.
Enter bank balance: 676858

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 77
Enter customer name: Mihir R.
Enter bank balance: 675697

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 78
Enter customer name: Kavya H.
Enter bank balance: 78678

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 89
_____________________________________
Invalid choice.

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 89
Enter customer name: Yerin J.
Enter bank balance: 757867

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 43
Enter customer name: Yuna L.
Enter bank balance: 678967

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 65
Enter customer name: Sara C.
Enter bank balance: 768756

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Hash Table is full.

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 2
_____________________________________
	****** CUSTOMER HASH TABLE *********

      Index         ID   Customer Name         Balance
          0         89        Yerin J.   757867.000000
          1         21     Shravani J.   786768.000000
          2         31        Aditi S.   767987.000000
          3         41      Gayatri K.   676567.000000
          4         42        Harsh P.   767867.000000
          5         43         Yuna L.   678967.000000
          6         65         Sara C.   768756.000000
          7         67         Maya R.   676858.000000
          8         77        Mihir R.   675697.000000
          9         78        Kavya H.    78678.000000
_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 3
_____________________________________
Enter customer id to search: 41
Customer found.
Customer id: 41
Name: Gayatri K.
Bank Balance: 676567.0
--------------------------------

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 4
_____________________________________
Enter customer id to delete: 78
Customer account has been deleted.

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 4
_____________________________________
Enter customer id to delete: 42
Customer account has been deleted.

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 4
_____________________________________
Enter customer id to delete: 77
Customer account has been deleted.

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 4
_____________________________________
Enter customer id to delete: 5
Customer with entered id NOT found

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 2
_____________________________________
	****** CUSTOMER HASH TABLE *********

      Index         ID   Customer Name         Balance
          0         89        Yerin J.   757867.000000
          1         21     Shravani J.   786768.000000
          2         31        Aditi S.   767987.000000
          3         41      Gayatri K.   676567.000000
          4 
          5         43         Yuna L.   678967.000000
          6         65         Sara C.   768756.000000
          7         67         Maya R.   676858.000000
          8 
          9 
_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 54
Enter customer name: Ketaki P.
Enter bank balance: 657856

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 1
_____________________________________
Enter customer id: 77
Enter customer name: Sana S.
Enter bank balance: 65486

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 2
_____________________________________
	****** CUSTOMER HASH TABLE *********

      Index         ID   Customer Name         Balance
          0         89        Yerin J.   757867.000000
          1         21     Shravani J.   786768.000000
          2         31        Aditi S.   767987.000000
          3         41      Gayatri K.   676567.000000
          4         54       Ketaki P.   657856.000000
          5         43         Yuna L.   678967.000000
          6         65         Sara C.   768756.000000
          7         67         Maya R.   676858.000000
          8         77         Sana S.    65486.000000
          9 
_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 4
_____________________________________
Enter customer id to delete: 89
Customer account has been deleted.

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 4
_____________________________________
Enter customer id to delete: 31
Customer account has been deleted.

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 4
_____________________________________
Enter customer id to delete: 53
Customer with entered id NOT found

_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 2
_____________________________________
	****** CUSTOMER HASH TABLE *********

      Index         ID   Customer Name         Balance
          0 
          1         21     Shravani J.   786768.000000
          2 
          3         41      Gayatri K.   676567.000000
          4         54       Ketaki P.   657856.000000
          5         43         Yuna L.   678967.000000
          6         65         Sara C.   768756.000000
          7         67         Maya R.   676858.000000
          8         77         Sana S.    65486.000000
          9 
_____________________________________
******** BANK ACCOUNT INFO ********
0. Exit
1. Add new customer
2. Display all customers
3. Search a customer
4. Delete a customer
Enter your choice: 0
_____________________________________
********** PROGRAM END ***********

 */
