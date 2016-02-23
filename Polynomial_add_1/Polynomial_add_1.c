#include <stdio.h>
#include <stdlib.h>
typedef struct _Polynomial Polynomial;
typedef struct _term term;

//Polynomial
typedef struct _Polynomial
{
	int start;
	int finish;
	term *items[20];
}Polynomial;

//term
typedef struct _term
{
        float coef;
        int exp;
}term;

void add_term_items(term **array,int length,Polynomial *Pol)
{
	if(Pol->finish-Pol->start>=length)
	{
		perror("The length is too long");
		exit(1);
	}
	for(int i=Pol->start;i<=Pol->finish;i++)
	{
		if(array[i]==NULL)
		{
			perror("The items is NULL");
			exit(1);
		}
		array[i]=Pol->items[i-Pol->start];
	}
}

int main()
{
	//term array
	term *array[100];
	for(int i=0;i<100;i++)
	{
		array[i]=(term*)malloc(sizeof(array[i]));
		if(array[i]==NULL)
		{
			perror("Heap leak");
                        exit(1);
		}
	}
	//A Polynomial
	Polynomial *A;
	A=(Polynomial*)malloc(sizeof(Polynomial));
	A->start=0;
	A->finish=19;
	for(int i=0;i<20;i++)
	{
		A->items[i]=(term*)malloc(sizeof(term));
		if(A->items[i]==NULL)
		{
			perror("The items is NULL");
                        exit(1);
		}
	}
	for(int i=0;i<20;i++)
        {
        	A->items[i]->exp=i;
		A->items[i]->coef=i*0.2;
	}	
	//B Polynomial
	Polynomial *B;
	B=(Polynomial*)malloc(sizeof(Polynomial));
        B->start=20;
        B->finish=25;
	for(int i=0;i<=(B->finish-B->start);i++)
        {
               	B->items[i]=(term*)malloc(sizeof(term));
                if(B->items[i]==NULL)
                {
                        perror("The items is NULL");
                        exit(1);
                }
        }
        for(int i=0;i<=(B->finish-B->start);i++)
        {
                B->items[i]->exp=i;
                B->items[i]->coef=i*0.2;
        }

	//implement
	add_term_items(array,20,A);
	add_term_items(array,6,B);
	return 0;

}
