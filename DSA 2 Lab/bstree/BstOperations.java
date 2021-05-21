/**
 * Roll number:	2372
 * Name: Sejal Kshirsagar
 * C number: C22019221374
 *  
 * DSA 2 Lab #2 21/05/2021
 * Problem Statement:
		Write a program to create a BST and perform following operations
				1. Find minimum or maximum node in a tree
				2. Display tree level wise
				3. Display tree in descending order
				4. Count no.of leaf nodes recursive
				(Extra functions- Find parent of a given node, Find height of a tree )
 */
package bstree;

import java.util.Scanner;
import java.util.Stack;
import java.util.ArrayList;
import java.util.LinkedList; 
import java.util.Queue;

class Node{
    int data; 
    Node left;
    Node right;

    Node(int data){
        this.data = data;
        left = null;
        right = null;
    }
}

class BST{
    Node root;
    Scanner sc = new Scanner(System.in);

    BST(){
        root = null;
    }


    void createBST(){
        int data;
        char ch;

        do
        {
            System.out.print("Enter data: ");
            data = sc.nextInt();
            Node tmp = new Node(data);

            if(root == null){
                root = tmp;
                System.out.println("Root Node added.");
            }
            else{
                Node ptr = root;
                
                while(ptr != null){

                    if(tmp.data < ptr.data){
                        if(ptr.left == null){
                            ptr.left = tmp;
                            System.out.println("New Node added.");
                            break;
                        }  
                        else
                            ptr = ptr.left;
                    }
                    else{
                        if(ptr.right == null){
                            ptr.right = tmp;
                            System.out.println("New Node added.");
                            break;
                        }  
                        else
                            ptr = ptr.right;
                    }
                }
            }

            System.out.print("\nAdd a new node? (Y/N): ");
            ch = sc.next().charAt(0);

        }while(ch != 'N');
    }


    void minNode(){
        Node ptr = root;
        while(ptr.left != null)
            ptr = ptr.left;
        System.out.println("Minimum Node: "+ptr.data);
    }

    void maxNode(){
        Node ptr = root;
        while(ptr.right != null)
            ptr = ptr.right;
        System.out.println("Maximum Node: "+ptr.data);
    }

    void levelWise(){
        Queue<Node> Q = new LinkedList<Node>();
        Q.add(root);
        
        while(true){
            int N = Q.size();

            if(Q.isEmpty())
                break;

            while(N > 0){
                Node ptr = Q.peek();
                System.out.print(ptr.data+"\t");

                if(ptr.left != null)
                    Q.add(ptr.left);
                if(ptr.right != null)
                    Q.add(ptr.right);
                    
                Q.remove();
                N--;
            }
            System.out.println(" ");
        }
    }

    int height(Node n){
        if(n == null)
            return 0;
        else{
            //Compute the depth of each subtree
            int LH = height(n.left);
            int RH = height(n.right);
            
            if(LH > RH)
                return LH + 1;
            else
                return RH + 1;
        }
    }

    void descendingOrder(){
        Stack<Node> S = new Stack<Node>();
        ArrayList<Integer> al = new ArrayList<Integer>();
        Node ptr = root;

        while(true){
            while(ptr != null){
                S.push(ptr);
                ptr = ptr.left;
            }
            
            if(!S.empty()){
                ptr = S.pop();
                al.add(ptr.data);
                ptr = ptr.right;
            }
            else //if Stack is empty
                break;
        }

        for(int i=al.size()-1; i>=0; i--){
            System.out.print(al.get(i)+"\t");
        }
    }

    void findParent(int key){
        boolean flag = false;
        Node ptr = root;
        Node parent = null;

        while(ptr != null){

            if(key == ptr.data){
                flag = true;
                break;
            }
            parent = ptr;
            if(key < ptr.data)
                ptr = ptr.left;
            else
                ptr = ptr.right;
        }

        if((parent != null) && (flag == true))
            System.out.println("Parent of "+key+" is "+parent.data);
        else
            System.out.println("Not Found");
    }

    int numLeafNodes(Node root){
        int count = 0;
        if(root == null)
            return 0;
        
        if((root.left == null) && (root.right == null))
            return 1;

        if(root.left != null)
            count += numLeafNodes(root.left);

        if(root.right != null)
            count += numLeafNodes(root.right);
        
        return count;
    }
 
}

public class BstOperations {
	public static void main(String[] args){

        BST t = new BST();
        t.createBST();

        Scanner sc = new Scanner(System.in);
        byte ch;

        do{
            System.out.println("\n-------------------------------------");
            System.out.println("******* BST OPERATIONS ********");
            System.out.println("0) Exit");
            System.out.println("1) Minimum and Maximum node in the tree");
            System.out.println("2) Display tree level wise");
            System.out.println("3) Display tree in descending order");
            System.out.println("4) Count no. of leaf nodes recursive");
            System.out.println("5) Height of tree");
            System.out.println("6) Find parent of a given node");
            System.out.print("Enter your choice: ");
            ch = sc.nextByte();
            sc.nextLine(); //'\n'
            System.out.println("-------------------------------------");

            switch(ch){
                case 0: System.out.println("******** PROGRAM ENDED ********");
                        break;

                case 1: t.minNode();
                        t.maxNode();
                        break;

                case 2: System.out.println("BST Level wise: ");
                        t.levelWise();
                        break;
                        
                case 3: System.out.println("BST in descending order: ");
                		t.descendingOrder();
                		break;
                		
                case 4: System.out.println("Number of Leaf Nodes is "+t.numLeafNodes(t.root));
                		break;

                case 5: System.out.println("Height of BST is "+t.height(t.root));
                        break;
             
                case 6: System.out.println("Enter node key: ");
                        int key = sc.nextInt();
                        t.findParent(key);
                        break;
              
                default: System.out.println("Invalid choice.");
                		 break;
            }
        }while(ch != 0);

        sc.close();
    }
}


/********** TIME COMPLEXITY ************
 * minNode()........................O(n)
 * maxNode()........................O(n)
 * levelWise()......................O(n)
 * descendingOrder()................O(n)
 * numLeafNodes(t.root).............O(n)
 * height(t.root)...................O(n)
 * findParent(key)..................O(n)
 */

/********** INPUT BST ************
 * 				 10
 * 		   	   /    \
 *            6     13
 *           / \    / \
 *          4   8  11  15
 *         / 
 *        1
 */

// *********** OUTPUT ************
/*
Enter data: 10
Root Node added.

Add a new node? (Y/N): Y
Enter data: 6
New Node added.

Add a new node? (Y/N): Y
Enter data: 4
New Node added.

Add a new node? (Y/N): Y
Enter data: 1
New Node added.

Add a new node? (Y/N): Y
Enter data: 8
New Node added.

Add a new node? (Y/N): Y
Enter data: 13
New Node added.

Add a new node? (Y/N): Y
Enter data: 11
New Node added.

Add a new node? (Y/N): Y
Enter data: 15
New Node added.

Add a new node? (Y/N): N

-------------------------------------
******* BST OPERATIONS ********
0) Exit
1) Minimum and Maximum node in the tree
2) Display tree level wise
3) Display tree in descending order
4) Count no. of leaf nodes recursive
5) Height of tree
6) Find parent of a given node
Enter your choice: 1
-------------------------------------
Minimum Node: 1
Maximum Node: 15

-------------------------------------
******* BST OPERATIONS ********
0) Exit
1) Minimum and Maximum node in the tree
2) Display tree level wise
3) Display tree in descending order
4) Count no. of leaf nodes recursive
5) Height of tree
6) Find parent of a given node
Enter your choice: 2
-------------------------------------
BST Level wise: 
10	 
6	13	 
4	8	11	15	 
1	 

-------------------------------------
******* BST OPERATIONS ********
0) Exit
1) Minimum and Maximum node in the tree
2) Display tree level wise
3) Display tree in descending order
4) Count no. of leaf nodes recursive
5) Height of tree
6) Find parent of a given node
Enter your choice: 3
-------------------------------------
BST in descending order: 
15	13	11	10	8	6	4	1	
-------------------------------------
******* BST OPERATIONS ********
0) Exit
1) Minimum and Maximum node in the tree
2) Display tree level wise
3) Display tree in descending order
4) Count no. of leaf nodes recursive
5) Height of tree
6) Find parent of a given node
Enter your choice: 4
-------------------------------------
Number of Leaf Nodes is 4

-------------------------------------
******* BST OPERATIONS ********
0) Exit
1) Minimum and Maximum node in the tree
2) Display tree level wise
3) Display tree in descending order
4) Count no. of leaf nodes recursive
5) Height of tree
6) Find parent of a given node
Enter your choice: 5
-------------------------------------
Height of BST is 4

-------------------------------------
******* BST OPERATIONS ********
0) Exit
1) Minimum and Maximum node in the tree
2) Display tree level wise
3) Display tree in descending order
4) Count no. of leaf nodes recursive
5) Height of tree
6) Find parent of a given node
Enter your choice: 6
-------------------------------------
Enter node key: 
8
Parent of 8 is 6

-------------------------------------
******* BST OPERATIONS ********
0) Exit
1) Minimum and Maximum node in the tree
2) Display tree level wise
3) Display tree in descending order
4) Count no. of leaf nodes recursive
5) Height of tree
6) Find parent of a given node
Enter your choice: 0
-------------------------------------
******** PROGRAM ENDED ********
*/
