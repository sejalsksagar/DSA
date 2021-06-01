/**
 * 2372 Sejal Kshirsagar
 *  
 * DSA 2 Lab #7 31/05/2021
 * Problem Statement:
		Use a sequential file to maintain student information. Develop java code to add, and display
		student information from the file.( you can add search and delete operations).
 */
package sequentialFile;

import java.io.Serializable;
import java.io.*;
import java.util.Scanner;
import java.util.*;

class Student implements Serializable{
	
	int roll_no;
	double mark;
	String name;
	
	Student(int rl, String nm, double marks)
	{
		roll_no = rl;
		name = nm;
		mark = marks;
	}
	
	public String toString()
	{
		String s= "Student{ "+" id= "+roll_no+" name= "+name+" mark "+mark+" }"; 
		return s;
	}

}

class SeqFile
{
	Vector<Student> st = new Vector<>();
	Scanner sc = new Scanner(System.in);
	
	//Writing records in the file.
	void writeinFile()
	{
		char ch;
		int rl;
		double marks;
		String nm;
		do {
			System.out.print("\nEnter Roll number: ");
			rl = sc.nextInt();
			sc.nextLine();
			System.out.print("Enter Student Name: ");
			nm = sc.nextLine();
			System.out.print("Enter Marks: ");
			marks = sc.nextDouble();
			Student s = new Student(rl, nm, marks);
			st.add(s);
			
			System.out.print("Add another student? (y/n) :");
			ch = sc.next().charAt(0);
			sc.nextLine();
		}while(ch!='n');
		
		File f = new File("objectTest.txt");
		try {
			FileOutputStream fout = new FileOutputStream(f);
			ObjectOutputStream oo = new ObjectOutputStream(fout);
			oo.writeObject(st);
			fout.close();
		}
		catch (Exception e) {	//FileNotFound or IOException
	            e.printStackTrace();
	    }
	}
	void readFile(String filename)
	{
		try {
			FileInputStream fin = new FileInputStream(filename);
			try (ObjectInputStream oi = new ObjectInputStream(fin)) {
				Vector<Student> st1 = (Vector<Student>)oi.readObject();
				Iterator<Student> itr = st1.iterator();
				
				while(itr.hasNext()) {
					Student x = itr.next();
					System.out.println(x);
				}
			}
		}
		catch(Exception e) {	//FileNotFound IOException
			e.printStackTrace();
		}
	}
	
	void Search()
	{
		int rl;
		boolean flag = false;
		Student t = null;
		
		System.out.print("Enter Roll number: ");
		rl = sc.nextInt();
		
		try {
			FileInputStream fin = new FileInputStream("objectTest.txt");
			try (ObjectInputStream oi = new ObjectInputStream(fin)) {
				Vector<Student> st1 = (Vector<Student>)oi.readObject();
				Iterator<Student> itr = st1.iterator();
				
				while(itr.hasNext())
				{
					t = (Student)itr.next();
					if(t.roll_no==rl)
					{
						flag = true;
						break;
					}
				}
			}
			if(!flag)
			   System.out.println("Not Found!");
			else
			   System.out.println(t);
		}
		catch(Exception e) {	//FileNotFound IOException
			e.printStackTrace();
		}
	}

	void delete()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Roll number: ");
		int rl = sc.nextInt();
		boolean flag = false;
		
		try {
			FileInputStream fin = new FileInputStream("objectTest.txt");
			ObjectInputStream oi = new ObjectInputStream(fin);
			FileOutputStream fout = new FileOutputStream("objectTest2.txt");
			ObjectOutputStream oo = new ObjectOutputStream(fout);
			Vector<Student> st1 = (Vector<Student>)oi.readObject();
			 Iterator<Student> itr = st1.iterator();
			 Vector<Student> st2 = new Vector<Student>();

			 while(itr.hasNext())
			 {
				 Student s = (Student)itr.next();
				 if(s.roll_no==rl) flag = true;
				 if(s.roll_no!=rl) st2.add(s);
			 }
			 oo.writeObject(st2);
			 
			 if(!flag)
				   System.out.println("Not Found!");
			else 
				System.out.println("Deleted data.");
			 System.out.println("\n\nReading file again: ");
			 readFile("objectTest2.txt");
		}
		catch (Exception e) {	//FileNotFound or IOException
            e.printStackTrace();
	    }
	}
		
}

public class Main {

	public static void main(String[] args) {
		int ch;
		Scanner co = new Scanner (System.in);
		SeqFile f = new SeqFile();
		
		do {
			System.out.println("********** SEQUENTIAL FILE ************");
			System.out.println("0. Exit");
			System.out.println("1.Write File");
			System.out.println("2.Read file");
			System.out.println("3.Search record");
			System.out.println("4.Delete record");
			System.out.print("Enter your choice: ");
			ch = co.nextInt();
			System.out.println("-------------------------------------------");

			switch(ch) {
			case 0:System.out.println("*********** PROGRAM END ************");
			break;
			
			case 1:f.writeinFile();
			break;
			
			case 2:f.readFile("objectTest.txt");
			break;
			
			case 3:f.Search();
			break;
			
			case 4:f.delete();
			break;
			
			default:System.out.println("Invalid choice");
			break;
			}
		}while(ch!=0);
		co.close();
	}
}

