#include <iostream>
#define MAX 20

using namespace std;

class SparseMatrix
{
    int SM[MAX][3];   // <row,column,value>
    
    public:
    
        SparseMatrix()
        {
            SM[MAX][3] = {0};
        }
    
        void accept();
        void display();
        void isSquareMatrix();
        void isUpperTriangular();
        void isLowerTriangular();
        void addition(SparseMatrix B);
        void simpleTranspose();
        SparseMatrix fastTranspose();
};

void SparseMatrix :: accept()
{
    cout<<"\nEnter number of ROWS and COLUMNS: ";
    cin>>SM[0][0]>>SM[0][1]; 
    
    cout<<"\nEnter number of non-zero values: ";
    cin>>SM[0][2]; 
    
    cout<<"\nEnter row, column, value:";
    for(int i=1 ; i<=SM[0][2] ; i++)
    {
            cout<<"\n("<<i<<") : ";
            cin>>SM[i][0]>>SM[i][1]>>SM[i][2];
    }
}

void SparseMatrix :: display()
{
    cout<<"\nNo. of rows = "<<SM[0][0];
    cout<<"\nNo. of columns = "<<SM[0][1];
    cout<<"\nNo. of non-zero values = "<<SM[0][2];
    cout<<"\n----------------------------";
    cout<<"\nrow, column, value";
    for(int i=1; i<=SM[0][2] ; i++)
    {
        cout<<"\n"<<SM[i][0]<<"\t"<<SM[i][1]<<" \t"<<SM[i][2];
    } 
}

void SparseMatrix :: isSquareMatrix()
{
    if(SM[0][0] == SM[0][1])
        cout<<"is a Square Matrix";
    else
        cout<<"is NOT a Square Matrix";
}

void SparseMatrix :: isUpperTriangular()
{
    for(int i=1 ; i<=SM[0][2] ; i++)
    {
        if((SM[i][1] < SM[i][0]) && (SM[i][2] != 0))
        { 
            cout<<"is NOT Upper Triangular";
            return;
        }
    }
    cout<<"is Upper Triangular";
}

void SparseMatrix :: isLowerTriangular()
{
    for(int i=0; i<SM[0][2]; i++)
    {
        if((SM[i][1] > SM[i][0]) && (SM[i][2] != 0))
        {
            cout<<"is NOT Lower Triangular";
            return;
        }
    }
    cout<<"is Lower Triangular";
}

void SparseMatrix :: addition(SparseMatrix B)
{
    if((SM[0][0] != B.SM[0][0]) || (SM[0][1] != B.SM[0][1]))
    {
        cout<<"\nSparseMatrix A and B have different dimensions. Addition not possible.";
    }
    else
    {
        SparseMatrix C;
        C.SM[0][0] = SM[0][0];
        C.SM[0][1] = SM[0][1];
        C.SM[0][2] = 0;
        
        int Avals = SM[0][2];
        int Bvals = B.SM[0][2];
        
        int i = 1;
        int j = 1;
        int k = 1;
        
        while((i <= Avals) && (j <= Bvals))
        {
            if(SM[i][0] == B.SM[j][0]) //row positions equal
            {
                if(SM[i][1] == B.SM[j][1])  //col positions equal
                {
                    C.SM[k][0] = SM[i][0];
                    C.SM[k][1] = SM[i][1];
                    C.SM[k][2] = SM[i][2] + B.SM[j][2];
                    i++; j++; k++;
                }
                else if(SM[i][1] < B.SM[j][1])  //col A position < col B position
                {
                    C.SM[k][0] = SM[i][0];
                    C.SM[k][1] = SM[i][1];
                    C.SM[k][2] = SM[i][2];
                    i++; k++;
                }
                else  //col A position > col B position
                {
                    C.SM[k][0] = B.SM[j][0];
                    C.SM[k][1] = B.SM[j][1];
                    C.SM[k][2] = B.SM[j][2];
                    j++; k++;
                }
            }
            else if(SM[i][0] < B.SM[j][0])  //row A position < row B position
            {
                C.SM[k][0] = SM[i][0];
                C.SM[k][1] = SM[i][1];
                C.SM[k][2] = SM[i][2];
                i++; k++;
            }
            else  //row A position > row B position
            {
                C.SM[k][0] = B.SM[j][0];
                C.SM[k][1] = B.SM[j][1];
                C.SM[k][2] = B.SM[j][2];
                j++; k++;
            }
        }
        
        while(i <= Avals)
        {
            C.SM[k][0] = SM[i][0];
            C.SM[k][1] = SM[i][1];
            C.SM[k][2] = SM[i][2];
            i++; k++;
        }
        
        while(j <= Bvals)
        {
            C.SM[k][0] = B.SM[j][0];
            C.SM[k][1] = B.SM[j][1];
            C.SM[k][2] = B.SM[j][2];
            j++; k++;
        }
        C.SM[0][2] = k-1;  //update no. of non-zero values in C
        
        cout<<"\nSparseMatrix A + SparseMatrix B = SparseMatrix C: \n";
        C.display();
    }
}

void SparseMatrix :: simpleTranspose()
{
    SparseMatrix T;

    int Arows = SM[0][0];
    int Acols = SM[0][1];
    int Avals = SM[0][2];
    
    T.SM[0][0] = Acols;  //no. T's rows = no. A's cols
    T.SM[0][1] = Arows;   //no. T's cols = no. A's rows
    T.SM[0][2] = Avals;
    
    int i = 1; //row index 
    for(int j=0; j < Acols ; j++) //column values in A
    {
        for(int k=1; k <= Avals ; k++) //non-zero values in A
        {
            if(SM[k][1] == j) // find lowest column value
            {
                T.SM[i][0] = SM[k][1]; //T's row = A's col
                T.SM[i][1] = SM[k][0]; //T's col = A's row
                T.SM[i][2] = SM[k][2]; //T's val = A's val
                i++;
            }
        }
    }
    cout<<"\n===============================";
    cout<<"\nSimple Transpose of SparseMatrix A: \n";
    T.display();
}

SparseMatrix SparseMatrix :: fastTranspose()
{
    SparseMatrix T;
    int count[MAX] = {0},  index[MAX];
    int i, j;  

    int Arows = SM[0][0];
    int Acols = SM[0][1];
    int Avals = SM[0][2];

    T.SM[0][0] = Acols;     //no. T's rows = no. A's cols
    T.SM[0][1] = Arows;     //no. T's cols = no. A's rows
    T.SM[0][2] = Avals;

    for(i=1; i<=Avals; i++)
        count[SM[i][1]]++;  //A's column values count

    index[0]=1;
    for(i=1; i<Acols; i++)
        index[i] = index[i-1] + count[i-1];
    
    for(i=1; i<=Avals; i++)
    {
        j = index[SM[i][1]]++;
        T.SM[j][0] = SM[i][1];
        T.SM[j][1] = SM[i][0];
        T.SM[j][2] = SM[i][2];
    }
    return T;
}

int main()
{
    int ch;
    SparseMatrix A, B;
    
    cout<<"For Matrix A: ";
    A.accept();
    
    do{
            cout<<"\n************** SPARSE MATRIX OPERATIONS **************";
            cout<<"\n0. Exit";
            cout<<"\n1. Display SparseMatrix A";
            cout<<"\n2. Check if SparseMatrix A is a Square Matrix";
            cout<<"\n3. Check if SparseMatrix A is Upper Triangular";
            cout<<"\n4. Check if SparseMatrix A is Lower Triangular";
            cout<<"\n5. Add SparseMatrix A and another SparseMatrix B";
            cout<<"\n6. Simple Transpose of SparseMatrix A";
            cout<<"\n7. Fast Transpose of SparseMatrix A";
            cout<<"\nEnter your choice: ";
            cin>>ch;
            cout<<"____________________________________________________\n";
            
        switch(ch)
        {
            case 0: cout<<"\n*********** PROGRAM ENDED SUCCESSFULLY ************";
                    break;
            
            case 1: cout<<"\nSparseMatrix A: \n";
                    A.display();
                    break;
                    
            case 2: cout<<"\nSparseMatrix A: \n";
                    A.display();
                    cout<<"\nSparseMatrix A ";
                    A.isSquareMatrix();
                    break;
                    
            case 3: cout<<"\nSparseMatrix A: \n";
                    A.display();
                    cout<<"\nSparseMatrix A ";
                    A.isUpperTriangular();
                    break;
                    
            case 4: cout<<"\nSparseMatrix A: \n";
                    A.display();
                    cout<<"\nSparseMatrix A ";
                    A.isLowerTriangular();
                    break;
                    
            case 5: cout<<"\nFor another SparseMatrix B:";
                    B.accept();
                    cout<<"\nSparseMatrix A: \n";
                    A.display();
                    cout<<"\nSparseMatrix B: \n";
                    B.display();
                    A.addition(B);                    
                    break;

            case 6: cout<<"\nSparseMatrix A: \n";
                    A.display();
                    A.simpleTranspose();
                    break;

            case 7: cout<<"\nSparseMatrix A: \n";
                    A.display();
                    A = A.fastTranspose();
                    cout<<"\n===============================";
                    cout<<"\nFast Transpose of SparseMatrix A: \n";
                    A.display();
                    break;
                    
            default: cout<<"\nInvalid choice";
        }
        
    }while(ch!=0);

    return 0;
}

/*
accept()........................O(n)
display().......................O(n)
isSquareMatrix()................O(1)
isUpperTriangular().............O(n)
isLowerTriangular().............O(n)
addition(SparseMatrix B)........O(n)
simpleTranspose()...............O(n*m) where n = Acols & m = Avals
fastTranspose().................O(n+m) where n = Acols & m = Avals
  */
