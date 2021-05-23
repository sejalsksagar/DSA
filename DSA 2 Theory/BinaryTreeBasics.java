package BinaryTreeBasics;

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

    /*-------------------------------------------------------------- */

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
                        else{
                            ptr = ptr.leftChild;
                        }
                    }
                    else if(dir == 'R'){
                        if(ptr.rightChild == null){
                            ptr.rightChild = tmp;
                            System.out.println("New Node added.");
                            break;
                        }
                        else{
                            ptr = ptr.rightChild;
                        }
                    }
                    else{
                        System.out.println("Invalid direction.");
                    }
                }
            }

            System.out.print("\nAdd a new node? (Y/N): ");
            ch = sc.next().charAt(0);

        }while(ch != 'N');
    }

    /*-------------------------------------------------------------- */

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
            else{ //if Stack is empty
                return;
            }
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
            else{ //if Stack is empty
                return;
            }
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
            else{ //if Stack is empty
                return;
            }
        }
    }

    /*-------------------------------------------------------------- */

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

public class BinaryTreeBasics{

    public static void main(String[] args){

        BinaryTree bt = new BinaryTree();
        bt.createBinaryTree();

        System.out.println("\n-----------------------------------------------------------------------------");

        System.out.print("\nPreOrder Recursive Traversal  : ");
        bt.preOrderRecursive(bt.root);

        System.out.print("\nInOrder Recursive Traversal   : ");
        bt.inOrderRecursive(bt.root);

        System.out.print("\nPostOrder Recursive Traversal : ");
        bt.postOrderRecursive(bt.root);

        System.out.println("\n\n-----------------------------------------------------------------------------");

        System.out.print("\nPreOrder NonRecursive Traversal : ");
        bt.preOrderNonRecursive();

        System.out.print("\nInOrder NonRecursive Traversal  : ");
        bt.inOrderNonRecursive();

        System.out.print("\nPreOrder NonRecursive Traversal : ");
        bt.postOrderNonRecursive();

        System.out.println("\n\n-----------------------------------------------------------------------------");

        System.out.print("\nLevel Order Traversal  : ");
        bt.levelOrder();

        System.out.println("\n\n-----------------------------------------------------------------------------");
    }
}