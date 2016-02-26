#include <stdio.h>
#include <stdlib.h>
typedef struct _SparseMat
{
	int row;
	int col;
	int value;
}SparseMat;

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
	
	return 0;
}
