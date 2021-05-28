/**
 * 2372 Sejal Kshirsagar
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
