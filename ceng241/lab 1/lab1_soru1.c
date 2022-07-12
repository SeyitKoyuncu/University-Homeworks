#include<stdio.h>

void swap_value(int*, int*);
void swap_value(int*, int*);

void swap_value(int* a, int* b)
{
	int holder;
	
	holder = *a;
	
	*a = *b;
	
	*b = holder;

}

void swap_adress(int *pa , int * pb)
{
	int *holder;
	
	holder = pa;
	
	pa = pb;
	pb= holder;
	
	printf("pa adress = %p\n",pa);
	printf("pb adress = %p\n",pb);
}


int main()
{
	int a;
	int *pa = &a;
	
	printf("a =  \n");
	scanf("%d",&a);
	
	int b;
	int *pb = &b;
	
	printf("b =  \n");
	scanf("%d",&b);
	
	printf("--------------- SWAP 1 ---------------\n");
	
	swap_value(&a, &b);
	
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	
	printf("pa adress = %p\n",pa);
	printf("pb adress = %p\n",pb);

	
	printf("----------- SWAP 2 ------------ \n");
	
	swap_adress(pa, pb);
	
	return 0;
	
}

