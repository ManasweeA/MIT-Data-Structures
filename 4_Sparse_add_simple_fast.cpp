#include<iostream>
using namespace std;

class Sparse_Matrix
{
  private:
  int S_Mat[20][3];
  public:
  void Read_SparseMatrix();
  void Display_SparseMatrix();
  Sparse_Matrix Add_SparseMatrix(Sparse_Matrix B);
  Sparse_Matrix Simple_Transporse();
  Sparse_Matrix Fast_Transpose();
};

void Sparse_Matrix :: Read_SparseMatrix()
{
  int m,n,terms;
  int i,row,col,val;
  cout<<"Enter number of rows and columns of matrix: \n";
  cin>>m>>n;
  cout<<"Enter number of non-zero terms in the matrix: \n";
  cin>>terms;
  S_Mat[0][0]=m;
  S_Mat[0][1]=n;
  S_Mat[0][2]=terms;
  for(i=1;i<=terms;i++)
  {
    cout<<"Enter row, column and value of non-zero terms: \n";
    cin>>row>>col>>val;
    S_Mat[i][0]=row;
    S_Mat[i][1]=col;
    S_Mat[i][2]=val;
  }  
}

void Sparse_Matrix :: Display_SparseMatrix()
{
  int i,terms;
  terms=S_Mat[0][2];
  //cout<<"Row No.\t Col No.\t Value\n";
  for(i=0;i<=terms;i++)
  {
    cout<<S_Mat[i][0]<<"\t\t"<<S_Mat[i][1]<<"\t\t"<<S_Mat[i][2]<<"\n";
  }
}

Sparse_Matrix Sparse_Matrix :: Add_SparseMatrix (Sparse_Matrix B)
{
	Sparse_Matrix C;
	int i, j, k, Row1, Row2, Col1, Col2, M1, M2; 
	Row1 = S_Mat[0][0];
	Col1 = S_Mat[0][1]; 
	M1 = S_Mat[0][2];
	Row2 = B.S_Mat[0][0];
	Col2 = B.S_Mat[0][1];
	M2 = B.S_Mat[0][2];
	if(Row1 == Row2 && Col1 == Col2)
	// checking dimensions if1
	{
		i = 1;j = 1;k = 1;
		C.S_Mat[0][0] = S_Mat[0][0];
		C.S_Mat[0][1] = S_Mat[0][1];
		while(i<=M1 && j<=M2)  //while1
		{
			if(S_Mat[i][0] == B.S_Mat[j][0])	//if2
			{
				if(S_Mat[i][1] == B.S_Mat[j][1])	//if3
				{
					C.S_Mat[k][0] = S_Mat[i][0];
					C.S_Mat[k][1] = S_Mat[i][1];
					C.S_Mat[k][2] = S_Mat[i][2] + B.S_Mat[j][2];
					i++;j++;k++;
				} //end if3
				else  //else of if3
				{
					if(S_Mat[i][1] < B.S_Mat[j][1]) 	//if4
					{
						C.S_Mat[k][0] = S_Mat[i][0];
						C.S_Mat[k][1] = S_Mat[i][1];
						C.S_Mat[k][2] = S_Mat[i][2];
						i++;k++;						
					} //end of if4
					else  //else of if4
					{
						C.S_Mat[k][0] = B.S_Mat[j][0];
						C.S_Mat[k][1] = B.S_Mat[j][1];
						C.S_Mat[k][2] = B.S_Mat[j][2];
						j++;k++;						
					} //end of else of if4					
				}  //end of else of if3
			} //end of if2
			else  //else of if2
			{
				if(S_Mat[i][0] < B.S_Mat[j][0]) 	//if5
				{
					C.S_Mat[k][0] = S_Mat[i][0];
					C.S_Mat[k][1] = S_Mat[i][1];
					C.S_Mat[k][2] = S_Mat[i][2];
					i++;k++;						
				} //end of if5
				else  //else of if5
				{
					C.S_Mat[k][0] = B.S_Mat[j][0];
					C.S_Mat[k][1] = B.S_Mat[j][1];
					C.S_Mat[k][2] = B.S_Mat[j][2];
					j++;k++;						
				} //end of else of if5	
			} //end of else of if2	
		} //end of while1
		while(i<=M1)  //while2
		{
			C.S_Mat[k][0] = S_Mat[i][0];
			C.S_Mat[k][1] = S_Mat[i][1];
			C.S_Mat[k][2] = S_Mat[i][2];
			i++;k++;
		} //end of while2
		while(j<=M2)  //while3
		{
			C.S_Mat[k][0] = B.S_Mat[j][0];
			C.S_Mat[k][1] = B.S_Mat[j][1];
			C.S_Mat[k][2] = B.S_Mat[j][2];
			j++;k++;
		} //end of while3
		C.S_Mat[0][2]=k-1;
		return C;		
	} //end of if1
	else
		cout <<"Sorry, matrices cannot be added because dimensions do not match.\n";
} //end of function


Sparse_Matrix Sparse_Matrix::Fast_Transpose()
{
	Sparse_Matrix B;
	int M,T,i,j,k,Row,Col,Freq[20],RowStartPos[20];
	Row=S_Mat[0][0];
	Col=S_Mat[0][1];
	M=S_Mat[0][2];

    B.S_Mat[0][0]=Col;
	B.S_Mat[0][1]=Row;
	B.S_Mat[0][2]=M;
	for(i=0;i<Col;i++)
	{
		Freq[i]=0;
	}
	for(i=1;i<=M;i++)
	{
		T=S_Mat[i][1];
		Freq[T]++;
	}

	RowStartPos[0]=1;
	for(i=1;i<Col;i++)
	{
		RowStartPos[i]=RowStartPos[i-1]+Freq[i-1];
	}
	for(i=1;i<=M;i++)
	{
		j=S_Mat[i][1];
		k=RowStartPos[j];
		B.S_Mat[k][0]=S_Mat[i][1];
		B.S_Mat[k][1]=S_Mat[i][0];
		B.S_Mat[k][2]=S_Mat[i][2];
		RowStartPos[j] = RowStartPos[j] + 1;
	}
	return B;
}

Sparse_Matrix Sparse_Matrix::Simple_Transporse()
{
	Sparse_Matrix B;
	int Row,Col,i,j,k,T;
	Row=S_Mat[0][0];
	Col=S_Mat[0][1];
	T=S_Mat[0][2];
	B.S_Mat[0][0]=Col;
	B.S_Mat[0][1]=Row;
	B.S_Mat[0][2]=T;
	i=1;
	for(j=0;j<Col;j++)
	{
		for(k=1;k<=T;k++)
		{
			if(S_Mat[k][1]==j)
			{
				B.S_Mat[i][0]=S_Mat[k][1];
				B.S_Mat[i][1]=S_Mat[k][0];
				B.S_Mat[i][2]=S_Mat[k][2];
				i++;
			}	
		}
	}
	return B;
}

int main()
{
	Sparse_Matrix A,B,C; 
	A.Read_SparseMatrix();
	//A.Display_SparseMatrix();
	//B.Read_SparseMatrix();
	//C=A.Add_SparseMatrix(B);
	//C=A.Fast_Transpose();
    C=A.Simple_Transporse();
	cout<<"Matrix A:\n";
	A.Display_SparseMatrix();
	//cout<<"Matrix B:\n";
	//B.Display_SparseMatrix();
	cout<<"Matrix C:\n";
	C.Display_SparseMatrix();
}