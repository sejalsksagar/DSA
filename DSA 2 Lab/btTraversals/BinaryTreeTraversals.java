/**
 * Name: Sejal Kshirsagar
 *  
 * DSA 2 Lab #1 20/05/2021
 * Problem Statement:
		Create a binary tree and perform inorder, preorder and postorder traversals.
 */
package btTraversals;

import java.util.Scanner;
import java.util.Stack;
import java.util.LinkedList; 
import java.util.Queue;

class Node{
    int data; 
    Node leftChild;
    Node rightChild;

    Node(int data){
        this.data = data;
        leftChild = null;
        rightChild = null;
    }
}

class BinaryTree{
    Node root;
    Scanner sc = new Scanner(System.in);

    BinaryTree(){
        root = null;
    }

    

    void createBinaryTree(){
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
                char dir;

                while(ptr != null){
                    System.out.println("Current node data: "+ptr.data);
                    System.out.print("Direction to move (L/R): "); //Left or Right of current node
                    dir = sc.next().charAt(0);

                    if(dir == 'L'){
                        if(ptr.leftChild == null){
                            ptr.leftChild = tmp;
                            System.out.println("New Node added.");
                            break;
                        }
                        else
                            ptr = ptr.leftChild;
                    }
                    else if(dir == 'R'){
                        if(ptr.rightChild == null){
                            ptr.rightChild = tmp;
                            System.out.println("New Node added.");
                            break;
                        }
                        else
                            ptr = ptr.rightChild;
                    }
                    else
                        System.out.println("Invalid direction.");
                }
            }

            System.out.print("\nAdd a new node? (Y/N): ");
            ch = sc.next().charAt(0);

        }while(ch != 'N');
    }

    

    void inOrderRecursive(Node localRoot){
        if(localRoot != null){
            inOrderRecursive(localRoot.leftChild);
            System.out.print(localRoot.data+"\t");
            inOrderRecursive(localRoot.rightChild);
        }
    }

    void preOrderRecursive(Node localRoot){
        if(localRoot != null){
            System.out.print(localRoot.data+"\t");
            preOrderRecursive(localRoot.leftChild);
            preOrderRecursive(localRoot.rightChild);
        }
    }

    void postOrderRecursive(Node localRoot){
        if(localRoot != null){
            postOrderRecursive(localRoot.leftChild);
            postOrderRecursive(localRoot.rightChild);
            System.out.print(localRoot.data+"\t");
        }
    }

    /*-------------------------------------------------------------- */

    void inOrderNonRecursive(){
        Stack<Node> S = new Stack<Node>();
        Node ptr = root;

        while(true){
            while(ptr != null){
                S.push(ptr);
                ptr = ptr.leftChild;
            }
            
            if(!S.empty()){
                ptr = S.pop();
                System.out.print(ptr.data+"\t");
                ptr = ptr.rightChild;
            }
            else //if Stack is empty
                return;
        }
    }

    void preOrderNonRecursive(){
        Stack<Node> S = new Stack<Node>();
        Node ptr = root;

        while(true){
            while(ptr != null){
                System.out.print(ptr.data+"\t");
                S.push(ptr);
                ptr = ptr.leftChild;
            }
            
            if(!S.empty()){
                ptr = S.pop();
                ptr = ptr.rightChild;
            }
            else //if Stack is empty
                return;
        }
    }

    void postOrderNonRecursive(){
        Stack<Node> S1 = new Stack<Node>();
        Stack<Character> S2 = new Stack<Character>();
        Node ptr = root;
        char flag;

        while(true){
            while(ptr != null){
                S1.push(ptr);
                S2.push('L');
                ptr = ptr.leftChild;
            }
            
            if(!S1.empty()){
                ptr = S1.pop();
                flag = S2.pop();

                if(flag == 'L'){
                    S1.push(ptr);
                    S2.push('R');
                    ptr = ptr.rightChild;
                }
                else{
                    System.out.print(ptr.data+"\t");
                    ptr = null;
                }
            }
            else //if Stack is empty
                return;
        }
    }

    

    void levelOrder(){
        Queue<Node> Q = new LinkedList<Node>();

        Node ptr = root;
        while(ptr != null){
            System.out.print(ptr.data+"\t");
            if(ptr.leftChild != null)
                Q.add(ptr.leftChild);
            if(ptr.rightChild != null)
                Q.add(ptr.rightChild);
            if(Q.isEmpty())
                ptr = null;
            else
                ptr = Q.remove();
        }
    }

}


public class BinaryTreeTraversals {
	
	public static void main(String[] args) {
		
		int ch;
		BinaryTree b = new BinaryTree();
		Scanner sc = new Scanner(System.in);
		do
		{
			System.out.println("\n*********** BINARY TREE TRAVERSALS *************");
			System.out.println("0. Exit");
			System.out.println("1. Create a Binary Tree");
			System.out.println("2. Display the recursive Inorder");
			System.out.println("3. Display the non recursive Inorder");
			System.out.println("4. Display the recursive Preorder");
			System.out.println("5. Display the non recursive Preorder");
			System.out.println("6. Display the recursive PostOrder");
			System.out.println("7. Display the non recursive PostOrder");
			System.out.println("8. Display the Level Order Traversal");
			System.out.print("Enter your choice: ");
			ch = sc.nextInt();
			System.out.println("---------------------------------------------\n");
			
			switch(ch)
			{
				case 0: System.out.println("******** PROGRAM END **********");
						break;
			
				case 1: b.createBinaryTree(); 
						break;
						
				case 2: System.out.println("2. Recursive Inorder Traversal: ");
						b.inOrderRecursive(b.root);
						break;
						
				case 3: System.out.println("3. Non-Recursive Inorder Traversal: ");
						b.inOrderNonRecursive();
						break;
						
				case 4: System.out.println("4. Recursive Preorder Traversal: ");
						b.preOrderRecursive(b.root);
						break;
				
				case 5: System.out.println("5. Non-Recursive Preorder Traversal: ");
						b.preOrderNonRecursive();
						break;
						
				case 6: System.out.println("6. Recursive Postorder Traversal: ");
						b.postOrderRecursive(b.root);
						break;
				
				case 7: System.out.println("7. Non-Recursive Postorder Traversal: ");
						b.postOrderNonRecursive();
						break;
						
						
				case 8: System.out.println("8. Levelorder Traversal: ");
						b.levelOrder();
						break;
						
				default: System.out.println("Invalid choice.");
			}
			
		}while (ch != 0);
		
		sc.close();
	}
}



/*
 * ************ TIME COMPLEXITY *************
 * createBinaryTree()....................O(n) 
 * inOrderRecursive(Node localRoot)......O(n)
 * preOrderRecursive(Node localRoot).....O(n)
 * postOrderRecursive(Node localRoot)....O(n)
 * inOrderNonRecursive().................O(n)
 * preOrderNonRecursive()................O(n)
 * postOrderNonRecursive()...............O(n)
 * levelOrder()..........................O(n)
 */

