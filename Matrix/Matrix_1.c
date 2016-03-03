#include <stdio.h>
#include <stdlib.h>
typedef struct _SparseMat
{
	int row;
	int col;
	int value;
}SparseMat;

typedef struct _index
{
	int RowSize;
	int RowStart;
}index;

void add_items(SparseMat *Mat,int Mat_len,int row,int col,int value)
{
	if(row*col>Mat_len)
	{
		perror("The row and col is bigger than Mat");
		exit(1);
	}
	Mat->row=row;
	Mat->col=col;
	Mat->value=value;			
}

void Transpose(SparseMat **MatA,int MatA_len,SparseMat **MatB,int MatB_len,index *ind,int ind_len)
{
	
	//Count
	for(int i=0;i<MatA_len;i++)
	{
	}
}


void print(SparseMat **Mat,int Mat_len)
{
	printf("divid....\n");
	for(int i=0;i<Mat_len;i++)
	{
		printf("row=%d,col=%d,value=%d\n",Mat[i]->row,Mat[i]->col,Mat[i]->value);
	}
}
void Swap_row_col(SparseMat *Mat1,SparseMat *Mat2)
{
	int Temp;
	//Swap row
	Temp=Mat1->row;
	Mat1->row=Mat2->row;
	Mat2->row=Temp;
	//Swap col
	Temp=Mat1->col;
        Mat1->col=Mat2->col;
        Mat2->col=Temp;
	//Swap value
	Temp=Mat1->value;
        Mat1->value=Mat2->value;
        Mat2->value=Temp;
}

int main()
{
	index *ind[4]=NULL;
        for(int i=0;i<4;i++)
        {
                ind[i]=(index*)malloc(sizeof(index));
                if(ind[i]==NULL)
                {
                        perror("Memory leak");
                        exit(1);
                }
        }
	//Source A
	SparseMat *A[10];
	for(int i=0;i<10;i++)
	{
		A[i]=(SparseMat*)malloc(sizeof(SparseMat));
		if(A==NULL)
		{
			perror("Memory leak");
			exit(1);
		}
	}
	add_items(A[0],10,0,0,15);
	add_items(A[1],10,0,3,22);
	add_items(A[2],10,0,5,-15);
	add_items(A[3],10,1,1,11);
	add_items(A[4],10,1,2,3);
	add_items(A[5],10,2,3,-6);
	add_items(A[6],10,4,0,91);
	add_items(A[7],10,5,2,28);
	//Result B
	SparseMat *B[10];
        for(int i=0;i<10;i++)
        {
                B[i]=(SparseMat*)malloc(sizeof(SparseMat));
                if(A==NULL)
                {
                        perror("Memory leak");
                        exit(1);
                }
        }
	ind[0]->RowSize=0;
	ind[1]->RowSize=1;
	ind[2]->RowSize=2;
	ind[3]->RowSize=4;
	Transpose(A,8,B,8,index,4);
	return 0;
}
