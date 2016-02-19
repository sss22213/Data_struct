#include <stdio.h>
#include <stdlib.h>
int IsZero(int *array,int length)
{
	//array not exist
	if(array==NULL)return 2;
	//array not zero
	for(int i=0;i<length;i++)
	{
		if(array[i]!=0)return 0;
	}
	//array is zero
	return 1;
}
int Compare(int *a,int *b,int a_length,int b_length,int *result)
{
	//result : element 0 is a or b,element 1 is lead number
	//a and b both zero or NULL
	if(IsZero(a,a_length)!=0 && IsZero(b,b_length)!=0)
	{
                return 1;
	}
	//compare a and b
	int Max_a=0;
	int Max_b=0;
	for(int i=a_length-1;a>=0;i--)
	{	
		if(a[i]!=0)
		{	
			Max_a=i;
			break;
		}	
	}
	for(int i=b_length-1;i>=0;i--)
        {
                if(b[i]!=0)
		{	
			Max_b=i;
			break;
		}
        }
	if(Max_a>Max_b)
	{
		result[0]=1;
		result[1]=Max_a;
	}
	else if(Max_a<Max_b)
	{	
		result[0]=2;
                result[1]=Max_b;
	}
	else
	{
		result[0]=3;
                result[1]=Max_a;
	}
	return 0;
}
int Add(int *a,int *b,int *d,int a_length,int b_length,int d_length)
{
	while(!IsZero(a,a_length) || !IsZero(b,b_length))
	{
		int result[2];
		if(Compare(a,b,a_length,b_length,result))return 1;
		switch (result[0])
		{
			case 1:
				d[result[1]]=a[result[1]];
				a[result[1]]=0;
				break;	
			case 2:
				d[result[1]]=b[result[1]];
                                b[result[1]]=0;
                                break;
			case 3:
				d[result[1]]=a[result[1]]+b[result[1]];
				a[result[1]]=0;
				b[result[1]]=0;
				break;
		}
	}
	return 0;
}
int main()
{
	int d[7]={0};
	int a[5]={2,0,0,2,1};
	int b[6]={0,1,0,2,0,5};
	//check 
	if(Add(a,b,d,5,6,7))printf("ERROR");
	
	for(int i=0;i<7;i++)
	{
		printf("%d\n",d[i]);
	}
	return 0;
}
