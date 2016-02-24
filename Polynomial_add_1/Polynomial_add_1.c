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

//Polynumial add
void add_Poly(term **array,Polynomial *PolA,Polynomial *PolB)
{
	int a=0;
	int b=0;
	//array C location
	int start=(PolB->finish)+1;
	while(a<=PolA->finish && b<=PolB->finish)
	{
		//compare
		int cmp_num=array[a+(PolA->start)]->exp-array[b+(PolB->start)]->exp;
		if(cmp_num>0)cmp_num=1;
		else if(cmp_num==0)cmp_num=0;
		else cmp_num=-1;
		
		//add items
		switch(cmp_num)
		{
			case 1:
				array[start]->exp=PolA->items[a]->exp;
				array[start]->coef=PolA->items[a]->coef;
				a++;			
				break;
			case 0:
				array[start]->exp=PolA->items[a]->exp+PolB->items[b]->exp;
                                array[start]->coef=PolA->items[a]->coef;
				a++;
				b++;
				break;
			case -1:
				array[start]->exp=PolB->items[b]->exp;
                                array[start]->coef=PolB->items[b]->coef;
                                b++;
				break;						
		}
		start++;
	}

}

int main()
{
	//term array
	term *array[100];
	for(int i=0;i<100;i++)
	{
		array[i]=(term*)malloc(sizeof(term));
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
		A->items[i]->coef=i;
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
                B->items[i]->coef=i;
        }

	//implement
	add_term_items(array,20,A);
	add_term_items(array,6,B);
	add_Poly(array,A,B);
	return 0;

}
