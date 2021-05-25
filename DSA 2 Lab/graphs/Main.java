/*
 * Roll number:	2372
 * Name: Sejal Kshirsagar
 * C number: C22019221374
 *  
 * DSA 2 Lab #4 25/05/2021
 * Problem Statement:
	A news paper delivery boy every day drops news paper in a society having many lanes and
	houses. Represent this as a graph using adjacency matrix or adjacency list. Perform Depth
	First traversal and Breadth First traversal.
 */
package graphs;

import java.util.Scanner;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Stack;

class Node{
	int v; //vertex
	Node link;
}

class Graph
{
	int n; //number of vertices
	int e; //number of edges
	int[][] adjMat; //adjacency matrix of the graph
	final static int MAX = 20;

	Graph()
	{
		n = 0;
		e = 0;
		adjMat = null;
	}
	
	void createUsingAdjMat(Scanner sc)
	{
		adjMat = new int[MAX][MAX];
		System.out.print("Enter number of Houses: ");
		n = sc.nextInt();
		System.out.print("Enter number of Lanes: ");
		e = sc.nextInt();
		
		System.out.print("Are the lanes one-way? (Y/N): ");
		char ch = sc.next().charAt(0);
		
		int sv, ev;
		for(int i=0; i<e; i++) {
			System.out.print("Enter House no. of houses at endpoints of Lane "+i+" : ");
			sv = sc.nextInt();
			ev = sc.nextInt();
			adjMat[sv][ev] = 1;
			if(ch != 'Y')
				adjMat[ev][sv] = 1; //undirected graph.
		}
	}
	
	void displayAdjMat()
	{
		System.out.println("SOCIETY GRAPH ADJACENCY MATRIX:\n");
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) 
				System.out.print("   "+adjMat[i][j]);
			System.out.println("\n");
		}
	}
	
	void bfs(Scanner sc)
	{
		Queue<Integer> Q = new ArrayDeque<Integer>();
		boolean visited[] = new boolean[n];
		System.out.print("Enter start vertex: ");
		int sv = sc.nextInt();
		Q.add(sv);
		visited[sv] = true;
		
		System.out.println("BFS is: ");
		while(!Q.isEmpty()) {
			int v = Q.poll();
			System.out.print("\t"+v);
			
			for(int j=0; j<n; j++) {
				if(adjMat[v][j]==1 && !visited[j]) {
					Q.add(j);
					visited[j] = true;
				}	
			}
		}
	}
	
	//recursive
	void DFS(int v, boolean visited[]){
      
        System.out.print("\t"+v);
        
        for(int i=0; i<n; i++){
            if((adjMat[v][i]==1) && (!visited[i])) {
            	visited[i] = true;
            	DFS(i, visited);
            }  
        }
        
    }

    void depthFirstSearch(Scanner sc){
    	boolean visited[] = new boolean[n];
        System.out.print("Enter start vertex: ");
		int sv = sc.nextInt();
		
		System.out.println("Recursive DFS is: ");
		visited[sv] = true;
        DFS(sv, visited);
    }

	//non recursive
	void dfs(Scanner sc)
	{
		boolean visited[] = new boolean[n];
        Stack<Integer> S = new Stack<Integer>();
        
        System.out.print("Enter start vertex: ");
		int sv = sc.nextInt();
		
		System.out.println("Non Recursive DFS is: ");
        S.push(sv);
        visited[sv] = true;
        
        while(!S.empty()){
            int v = S.pop();
            System.out.print("\t"+v);
            
            for(int i=n-1; i>-1; i--){
                if((adjMat[v][i]==1) && (!visited[i])) {
                	S.push(i);
                	visited[i] = true;
                }
            }
        }
	}
}

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Graph g = new Graph();
		byte ch;
		do
		{
			System.out.println("\n______________________________________");
			System.out.println("*********** SOCIETY GRAPH ***********");
			System.out.println("0. Exit");
			System.out.println("1. Create Adjacency matrix");
			System.out.println("2. Display Adjacency matrix");
			System.out.println("3. Breadth-first Search (BFS)");
			System.out.println("4. Recursive Depth-first Search (DFS)");
			System.out.println("5. Non-Recursive Depth-first Search (DFS)");
			System.out.print("Enter your choice: ");
			ch = sc.nextByte();
			System.out.println("______________________________________");
			
			switch(ch)
			{
				case 0:System.out.println("************ PROGRAM END ************");
				break;
				
				case 1:g.createUsingAdjMat(sc);
				break;
				
				case 2:g.displayAdjMat();
				break;
				
				case 3:g.bfs(sc);
				break;
				
				case 4:g.depthFirstSearch(sc);
				break;
				
				case 5:g.dfs(sc);
				break;
				
				default: System.out.println("Invalid choice.");
			}
		}while(ch != 0);
		sc.close();
	}

}

/******** TIME COMPLEXITY ********
 * create.....................O(E)
 * display....................O(V^2)
 * BFS........................O(V^2)
 * DFS........................O(V^2)
 */

/********* INPUT GRAPH ***********
 * Undirected:
 *    0---------3
 *    | \
 *    |  \
 *    |    2
 *    |   /  \
 *    |  /    \
 *     1       4
 *     
 * Directed:
 * 0 ---------->1
 * 0 ---------->2
 * 1 ---------->2
 * 2 ---------->0
 * 2 ---------->3
 * 3 ---------->3
 * 
 */

//************* OUTPUT ***************
/*

______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 1
______________________________________
Enter number of Houses: 5
Enter number of Lanes: 5
Are the lanes one-way? (Y/N): N
Enter House no. of houses at endpoints of Lane 0 : 0 3
Enter House no. of houses at endpoints of Lane 1 : 0 1
Enter House no. of houses at endpoints of Lane 2 : 0 2
Enter House no. of houses at endpoints of Lane 3 : 2 4
Enter House no. of houses at endpoints of Lane 4 : 1 2

______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 2
______________________________________
SOCIETY GRAPH ADJACENCY MATRIX:

   0   1   1   1   0

   1   0   1   0   0

   1   1   0   0   1

   1   0   0   0   0

   0   0   1   0   0


______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 3
______________________________________
Enter start vertex: 0
BFS is: 
	0	1	2	3	4
______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 4
______________________________________
Enter start vertex: 0
Recursive DFS is: 
	0	1	2	4	3
______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 5
______________________________________
Enter start vertex: 0
Non Recursive DFS is: 
	0	1	2	4	3
______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 1
______________________________________
Enter number of Houses: 4
Enter number of Lanes: 6
Are the lanes one-way? (Y/N): Y
Enter House no. of houses at endpoints of Lane 0 : 0 1
Enter House no. of houses at endpoints of Lane 1 : 0 2
Enter House no. of houses at endpoints of Lane 2 : 1 2
Enter House no. of houses at endpoints of Lane 3 : 2 0
Enter House no. of houses at endpoints of Lane 4 : 2 3
Enter House no. of houses at endpoints of Lane 5 : 3 3

______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 2
______________________________________
SOCIETY GRAPH ADJACENCY MATRIX:

   0   1   1   0

   0   0   1   0

   1   0   0   1

   0   0   0   1


______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 3
______________________________________
Enter start vertex: 2
BFS is: 
	2	0	3	1
______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 4
______________________________________
Enter start vertex: 2
Recursive DFS is: 
	2	0	1	3
______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 5
______________________________________
Enter start vertex: 2
Non Recursive DFS is: 
	2	0	1	3
______________________________________
*********** SOCIETY GRAPH ***********
0. Exit
1. Create Adjacency matrix
2. Display Adjacency matrix
3. Breadth-first Search (BFS)
4. Recursive Depth-first Search (DFS)
5. Non-Recursive Depth-first Search (DFS)
Enter your choice: 0
______________________________________
************ PROGRAM END ************

 */
