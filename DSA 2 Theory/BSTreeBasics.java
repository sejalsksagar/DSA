package BSTreeBasics;

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

    /*-------------------------------------------------------------- */

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

    /*-------------------------------------------------------------- */

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
            else{ //if Stack is empty
                break;
            }
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
    /*-------------------------------------------------------------- */

    void searchNode(){
        Node ptr = root;
        boolean flag = false;
        System.out.print("Enter key to search: ");
        int key = sc.nextInt();
        sc.nextLine(); //'\n'

        while(ptr != null){
            if(key == ptr.data){
                flag = true;
                break;
            }
            if(key < ptr.data)
                ptr = ptr.left;
            else 
                ptr = ptr.right;
        }

        if(flag)
            System.out.println("Data Found.");
        else
            System.out.println("Data not found.");
    }

    void updateNode(){
        Node ptr = root;
        boolean flag = false;
        System.out.print("Enter key to update: ");
        int key = sc.nextInt();
        sc.nextLine(); //'\n'

        while(ptr != null){
            if(key == ptr.data){
                flag = true;
                break;
            }
            if(key < ptr.data)
                ptr = ptr.left;
            else 
                ptr = ptr.right;
        }

        if(flag){
            System.out.print("Enter new value: ");
            int newKey = sc.nextInt();
            sc.nextLine(); //'\n'
            ptr.data = newKey;
            System.out.println("Node has been updated.");
        }
        else
            System.out.println("Data not found.");
    }

    void deleteNode(){
        Node ptr = root;
        Node parent = root;

        System.out.print("Enter key to delete: ");
        int key = sc.nextInt();
        sc.nextLine(); //'\n'

        while(ptr != null){
            if(key == ptr.data){
                //no child
                if((ptr.left == null) && (ptr.right == null)){
                    if(parent.left == ptr)
                        parent.left = null;
                    else
                        parent.right = null;
                }

                //only left child & no right child
                else if((ptr.left != null) && (ptr.right == null)){
                    if(parent.left == ptr)
                        parent.left = ptr.left;
                    else
                        parent.right = ptr.left;
                }

                //only right child & no left child
                else if((ptr.left == null) && (ptr.right != null)){
                    if(parent.left == ptr)
                        parent.left = ptr.right;
                    else
                        parent.right = ptr.right;
                }

                //both have child
                else if((ptr.left != null) && (ptr.right != null)){
                    Node p = ptr.left;
                    parent = null;

                    if(p.right != null){
                        while(p.right != null){
                            parent = p;
                            p = p.right;
                        }
                        ptr.data = p.data;
                        parent.right = null;
                    }
                    
                    if(parent != null)
                        parent.right = p.left;
                    else{
                        ptr.data = p.data;
                        ptr.left = null;
                    }
                }

                System.out.println("Node deleted.");
                break;
            }

            //ptr.data != key
            else{
                parent = ptr;
                if(key < ptr.data)
                    ptr = ptr.left;
                else 
                    ptr = ptr.right;
            }
   
        }
        if(ptr==null)
            System.out.println("Data not found.");

    }
}

public class BSTreeBasics{

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
            System.out.println("3) Height of tree");
            System.out.println("4) Display tree in descending order");
            System.out.println("5) Find parent of a given node");
            System.out.println("6) Count no. of leaf nodes");
            System.out.println("7) Search a node in the tree");
            System.out.println("8) Update a node in the tree");
            System.out.println("9) Delete a node in the tree");
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

                case 3: System.out.println("Height of BST is "+t.height(t.root));
                        break;

                case 4: System.out.println("BST in descending order: ");
                        t.descendingOrder();
                        break;

                case 5: System.out.println("Enter node key: ");
                        int key = sc.nextInt();
                        t.findParent(key);
                        break;

                case 6: System.out.println("Number of Leaf Nodes is "+t.numLeafNodes(t.root));
                        break;

                case 7: t.searchNode();
                        break;

                case 8: t.updateNode();
                        break;

                case 9: t.deleteNode();
                        break;
            }
        }while(ch != 0);

        sc.close();
    }
}