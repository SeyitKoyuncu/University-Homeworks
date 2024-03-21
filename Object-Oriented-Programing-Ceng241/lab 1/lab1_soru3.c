#include <stdio.h>
#include <stdlib.h>


struct component{
	int id[5];
	char name[5][100];
	int price[5];
};

struct person{
	int bill;
	int choice[5];
	struct component device;
};




int main()
{
	int add;
	
	printf("Enter the number of product you want to add : \n");
	scanf("%d",&add);
	
	struct person buyer; 
	struct component buy;
	
	int i,k;
	
	for(i = 0; i < add; i++)
	{
		printf("Enter the product id and product name and price: \n");
		scanf("%d",&(buyer.device.id[i]));
		
		scanf("%s",&buyer.device.name[i]);
		
		scanf("%d",&buyer.device.price[i]);		
	}
	
	printf("Displaying information : \n");
	 
	int control = 0;
	int count = 0;
	int id;
	int j;
	
	buyer.bill = 0;
	
	int holder = 0;
	
	do
	{	
		for(i = 0; i < add; i++)
		{
			printf("Name: %s \n",buyer.device.name[i]);
			
			printf("id: %d  price : %d\n",buyer.device.id[i], buyer.device.price[i]);			
		}
			
		k = 0;
			
		printf("Choice item from list with the id: \n");
		scanf("%d",&holder);	
		
		for(k = 0; k < add; k++)
		{
			if(buyer.device.id[k] == holder)
			{
				buy.id[count] = holder;
				
				for(j = 0; j < 20; j++)
				{
					buy.name[count][j] = buyer.device.name[k][j];	
				}
				
				buy.price[count] = buyer.device.price[k];
				buyer.bill += buyer.device.price[k];
				count = count + 1;
			}
		}
			
		printf("Press 1 if you want to continue. \n");
		scanf("%d",&control);	
			
	}while(control == 1);
	
	for(i = 0; i < count; i++)
	{
		int k = buyer.choice[i];
		
		printf("Your order: \n");
		
		printf("Name: %s \n",buy.name[i]);
		
		printf("id: %d  price : %d\n",buy.id[i], buy.price[i]);	
	}
	
	printf("Bill : %d ",buyer.bill);
}
