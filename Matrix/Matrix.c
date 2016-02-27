#include <stdio.h>
#include <stdlib.h>
typedef struct _SparseMat
{
	int row;
	int col;
	int value;
}SparseMat;

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

int main()
{
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
	add_items(A[5],10,102,3,-6);
	add_items(A[6],10,4,0,91);
	add_items(A[7],10,5,2,28);
	
	return 0;
}
