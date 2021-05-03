/*
 * matrix.cpp
 *
 * DSA 1 Lab #1:
		Write C++ program to perform following operations on matrices:
		1. Check matrix is square matrix .
		2. Check matrix is upper triangular.
		3. Compute transpose of matrix .
		4. Add two matrices .
		5. Multiply two matrices.
 *
 *  Created on: 03-May-2021
 *      Author: sejal 2372
 */
#include <iostream>
#define MAX 20

using namespace std;

class Matrix
{
    int matrix[MAX][MAX];
    int row, col;

    public:

        Matrix()
        {
            matrix[MAX][MAX] = {0};
            row = 0;
            col = 0;
        }

        void accept();
        void display();
        void isSquareMatrix();
        void isUpperTriangular();
        void isLowerTriangular();
        void transpose(Matrix A);
        int addition(Matrix A, Matrix B);
        int multiplication(Matrix A, Matrix B);
};

void Matrix :: accept()
{
    cout<<"\nEnter number of ROWS and COLUMNS: ";
    cin>>row>>col;

    cout<<"\nEnter values:\n";
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<"("<<i<<", "<<j<<") : ";
            cin>>matrix[i][j];
        }
    }
}

void Matrix :: display()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            cout<<matrix[i][j]<<"  ";

        cout<<"\n";
    }
    cout<<"Dimension: "<<row<<"x"<<col<<"\n";
}

void Matrix :: isSquareMatrix()
{
    if(row == col)
        cout<<"is a Square Matrix";
    else
        cout<<"is NOT a Square Matrix";
}

void Matrix :: isUpperTriangular()
{
	if(row != col){
			cout<<" is not a Square Matrix. Cannot check if it is Upper Triangular.";
			return;
	}

    for(int i=1; i<row; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(matrix[i][j]!=0)
            {
                cout<<"is NOT Upper Triangular";
                return;
            }
        }
    }
    cout<<"is Upper Triangular";
}

void Matrix :: isLowerTriangular()
{
	if(row != col){
		cout<<" is not a Square Matrix. Cannot check if it is Lower Triangular.";
		return;
	}

    for(int i=0; i<row; i++)
    {
        for(int j=i+1; j<row; j++)
        {
            if(j>i && matrix[i][j]!=0)
            {
                cout<<"is NOT Lower Triangular";
                return;
            }
        }
    }
    cout<<"is Lower Triangular";
}

void Matrix :: transpose(Matrix A)
{
	row = A.col;
	col = A.row;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
        	matrix[i][j] = A.matrix[j][i];
        }
    }
}

int Matrix :: addition(Matrix A, Matrix B)
{
    if(A.row!=B.row || A.col!=B.col)
    {
        cout<<"\nMatrix A and B have different dimensions. Matrix addition not possible.";
        return -1;
    }

    row = A.row;
    col = A.col;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
    return 0;
}

int Matrix :: multiplication(Matrix A, Matrix B)
{
    if(A.col != B.row)
    {
        cout<<"\nNumber of Columns in Matrix A and Rows in Matrix B are not equal. Matrix multiplication not possible.";
        return -1;
    }

    row = A.row;
    col = B.col;

    for(int i=0; i<A.row; i++)
    {
        for(int j=0; j<B.col; j++)
        {
            matrix[i][j] = 0;

            for(int k=0; k<A.col; k++) //B.row
                matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
        }
    }
    return 0;
}

int main()
{
    int ch;
    Matrix A, B, C;

    cout<<"For Matrix A: ";
    A.accept();

    do{
            cout<<"\n*************** MATRIX OPERATIONS ***************";
            cout<<"\n0. Exit";
            cout<<"\n1. Display Matrix A";
            cout<<"\n2. Check if Matrix A is a Square Matrix";
            cout<<"\n3. Check if Matrix A is Upper Triangular";
            cout<<"\n4. Check if Matrix A is Lower Triangular";
            cout<<"\n5. Transpose Matrix A";
            cout<<"\n6. Add Matrix A & another Matrix B";
            cout<<"\n7. Multiply Matrix A & another Matrix B";
            cout<<"\n8. Accept new matrix A";
            cout<<"\nEnter your choice: ";
            cin>>ch;
            cout<<"____________________________________________________\n";

        switch(ch)
        {
            case 0: cout<<"\n*********** PROGRAM ENDED SUCCESSFULLY ************";
                    break;

            case 1: cout<<"\nMatrix A: \n";
                    A.display();
                    break;

            case 2: cout<<"\nMatrix A: \n";
                    A.display();
                    cout<<"\nMatrix A ";
                    A.isSquareMatrix();
                    break;

            case 3: cout<<"\nMatrix A: \n";
                    A.display();
                    cout<<"\nMatrix A ";
                    A.isUpperTriangular();
                    break;

            case 4: cout<<"\nMatrix A: \n";
                    A.display();
                    cout<<"\nMatrix A ";
                    A.isLowerTriangular();
                    break;

            case 5: cout<<"\nMatrix A: \n";
                    A.display();
                    C.transpose(A);
                    cout<<"\nTranspose of Matrix A: \n";
                    C.display();
                    break;

            case 6: cout<<"\nFor another Matrix B:";
                    B.accept();
                    cout<<"\nMatrix A: \n";
                    A.display();
                    cout<<"\nMatrix B: \n";
                    B.display();
                    if(C.addition(A, B) != -1)
                    {
                        cout<<"\nMatrix A + Matrix B = Matrix C: \n";
                        C.display();
                    }
                    break;

            case 7: cout<<"\nFor another Matrix B:";
                    B.accept();
                    cout<<"\nMatrix A: \n";
                    A.display();
                    cout<<"\nMatrix B: \n";
                    B.display();
                    if(C.multiplication(A, B) != -1)
                    {
                        cout<<"\nMatrix A x Matrix B = Matrix C: \n";
                        C.display();
                    }
                    break;

            case 8: cout<<"\nFor new matrix A:";
            		A.accept();
            		break;

            default: cout<<"\nInvalid choice";
        }

    }while(ch!=0);

    return 0;
}
