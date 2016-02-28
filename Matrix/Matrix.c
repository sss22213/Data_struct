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

void Transpose(SparseMat **Mat,int Mat_len)
{
	for(int i=0;i<Mat_len;i++)
	{
		int temp=0;
		temp=Mat[i]->row;
		Mat[i]->row=Mat[i]->col;
		Mat[i]->col=temp;
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
void Sorting(SparseMat **Mat,int Mat_len)
{
	
	for(int i=0;i<Mat_len;i++)
	{
		SparseMat *Min=Mat[i];
		for(int j=i+1;j<Mat_len;j++)
		{
			if((Min->row)*10+Min->col>(Mat[j]->row)*10+Mat[j]->col)
			{
				Min=Mat[j];
			}
		}
			Swap_row_col(Min,Mat[i]);
			print(Mat,8);
	}                       
			
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
	add_items(A[5],10,2,3,-6);
	add_items(A[6],10,4,0,91);
	add_items(A[7],10,5,2,28);
	Transpose(A,8);
	Sorting(A,8);
	return 0;
}
