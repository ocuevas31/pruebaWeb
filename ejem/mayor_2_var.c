#include <stdio.h>


int main() 
{
	
	int x,y;
	
	
	
	x=5;	/*Cambiar para probar*/
	y=8;	/*Idem*/
	
	
	if (x>y) printf("El mayor es: %d",x);
	else if (x<y) printf("El mayor es: %d",y);
	else printf("Son iguales");
	
	
	
	printf("\n");
	int max;	/*Mejor declarar las variables todas al principio*/
	
	
	if (x>y) max=x;
	else if (x<y) max=y;
	
	
	if (x==y) printf("Son iguales");
	else printf("El mayor es: %d",max);
	
	
	
	
	
	
	
	
	return 0;
}
