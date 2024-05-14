#include <stdio.h>



int main() {
	
	int x,y;
	
	
	
	for(x=1,y=5;x<=10;x++,y=y+5)
	printf("%d %d ",x,y);
	
	
	
	printf("\n");
	
	
	y=5;
	for(x=1;x<=10;x++)
	{
	
		printf("%d %d ",x,y);
		y=y+5;
	}
	
	
	printf("\n");
	
	x=1;
	y=5;
	while(x<=10)
	{
			printf("%d %d ",x,y);
			x++;
			y=y+5;
		
	}
	
	

	printf("\n");
	
	x=1;
	y=5;
	do
	{
			printf("%d %d ",x,y);
			x++;
			y=y+5;
		
	}while(x<=10);
	
	
	
	
	printf("\n");
	
	x=0;
	y=0;
	while(x<=9)
	{
			x++;
			y=y+5;	
			printf("%d %d ",x,y);
		
	}
	
	
	
	
	
	
	
	return 0;
}
