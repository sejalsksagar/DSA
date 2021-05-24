/**
 * 2372 Sejal Kshirsagar
 *  
 * DSA 2 Lab #3 24/05/2021
 * Problem Statement:
		Create a reasonably balanced tree to maintain names and telephone numbers of all the
		customers of a shopkeeper and perform operations on it. Test your program for at least 10
		names.
 */
package avlTree;
import java.util.Scanner;
import java.util.Stack;

class Node{
    String customerName;
    String telephoneNo;
    Node left, right;
    int h; 

    Node(String cn, String tn){
        customerName = cn;
        telephoneNo = tn;
        left = null;
        right = null;
        h = 0;
    }
}

class AVLTree{
    Node root;

    Scanner sc = new Scanner(System.in);

    AVLTree(){
        root = null;
    }


    int height(Node root){
        int lh, rh;
        if(root == null)
            return 0;

        if(root.left == null)
            lh = 0;
        else
            lh = 1 + root.left.h;

        if(root.right == null)
            rh = 0;
        else
            rh = 1 + root.right.h;

        if(lh > rh)
            return lh;
        else
            return rh;
    }

    int balanceFactor(Node root){
        int bf, lh, rh;

        if(root == null)
            return 0;
        
        if(root.left == null)
            lh = 0;
        else 
            lh = 1 + height(root.left);

        if(root.right == null)
            rh = 0;
        else 
            rh = 1 + height(root.right);

        bf = lh - rh;
        return bf;
    }


    Node LL(Node root){ 
        //Right Rotation
        Node tmp = root.left;
        root.left = tmp.right;
        tmp.right = root;
        tmp.h = height(tmp);
        root.h = height(root);
        return tmp;
    }

    Node RR(Node root){ 
        //Left Rotation
        Node tmp = root.right;
        root.right = tmp.left;
        tmp.left = root;
        tmp.h = height(tmp);
        root.h = height(root);
        return tmp;
    }

    Node LR(Node root){ 
        //1) Left Rotation around child(alpha)
        //2) Right Rotation around alpha
        root.left = RR(root.left);
        root = LL(root);
        return root;
    }

    Node RL(Node root){ 
        //1) Right Rotation around child(alpha)
        //2) Left Rotation around alpha
        root.right = LL(root.right);
        root = RR(root);
        return root;
    }

    /*-------------------------------------------------------------- */

    void create(){
        String cn, tn;

        System.out.print("Enter Name: ");
        cn = sc.nextLine();

        System.out.print("Telephone Number: ");
        tn = sc.nextLine();

        root = insert(root, cn, tn);
    }

    Node insert(Node root, String cn, String tn){ 
        int bf;

        if(root == null){
            root = new Node(cn, tn);
            return root;
        }

        if(cn.compareToIgnoreCase(root.customerName) < 0){
            root.left = insert(root.left, cn, tn);
            bf = balanceFactor(root);

            if(bf == 2){
                if(cn.compareToIgnoreCase(root.left.customerName) < 0)
                    root = LL(root);
                else
                    root = LR(root);
            }
        }
        else{ //cn.compareToIgnoreCase(root.customerName) > 0
            root.right = insert(root.right, cn, tn);
            bf = balanceFactor(root);

            if(bf == -2){
                if(cn.compareToIgnoreCase(root.right.customerName) > 0)
                    root = RR(root);
                else
                    root = RL(root);
            }
        }

        root.h = height(root);
        return root;
    }
    
    //inOrder NonRecursive
    void display(){
        Stack<Node> S = new Stack<Node>();
        Node ptr = root;

        while(true){
            while(ptr != null){
                S.push(ptr);
                ptr = ptr.left;
            }
            
            if(!S.empty()){
                ptr = S.pop();
                System.out.println(ptr.customerName+" - "+ptr.telephoneNo);
                ptr = ptr.right;
            }
            else //if Stack is empty
                return;
        }
    }
}

public class AVLTreeTraversal {

	public static void main(String[] args) {
		byte ch;
		Scanner sc = new Scanner(System.in);
		AVLTree avl = new AVLTree();
		do
		{
			System.out.println("-----------------------------------");
			System.out.println("******* TELEPHONE DIRECTORY *******");
			System.out.println("0. Exit");
			System.out.println("1. Add new customer");
			System.out.println("2. Display directory");
			System.out.print("Enter your choice: ");
			ch = sc.nextByte();
			System.out.println("-----------------------------------");
			switch(ch)
			{
				case 0: System.out.println("********** PROGRAM END ***********");
				break;
				
				case 1:
				avl.create();
				break;
		
				case 2:
				avl.display();
				break;
			}
		}while(ch!=0);
		sc.close();
	}
}

/********** TIME COMPLEXITY ***********
 * insert......................O(logn)
 * display.....................O(n)
 * RR, LL, RL, LR..............O(1)
 * balanceFactor...............O(1)
 * height......................O(1)
 */

