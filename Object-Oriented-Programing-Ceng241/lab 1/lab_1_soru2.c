#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int total;
	
	printf("input total number of elements (1 to 100):  \n");
	scanf("%d",&total);
	
	int i = 0;
	int * arr = (int *)malloc(total *sizeof(int));
	
	
	for(i = 0; i < total; i++)
	{	
		printf("Number %d: ",i+1);
		scanf("%d",&arr[i]);
		
		printf("\n");
	}
	
	double max = 0;
	
	for(i = 0; i < total; i++)
	{	
		if(arr[i] > max)
			max = arr[i];
	}
	
	printf("your largest value is = %lf",max);
	
	free(arr);
	
	return 0;
	
}
