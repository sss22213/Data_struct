#include <stdio.h>
#include <strdlib.h>
typedef struct _Mat
{
	int row;
	int col;
}Mat;

int main()
{
	Mat *A[10];
	for(int i=0;i<10;i++)
	{
		A=(Mat*)malloc(sizeof(Mat));
		if(A==NULL)
		{
			perror("Memory leak");
			exit(1);
		}
	}

	return 0;
}
