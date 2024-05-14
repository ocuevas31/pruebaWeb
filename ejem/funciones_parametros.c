#include <stdio.h>
#include <stdlib.h>



void fun(int a,char b)
{
	
	
	printf("\nEjecutando fun(%d,%c)\n",a,b);
}

void funfun(void (*mifun)(int a,char b),int par,char par2)
{
	

	printf("Ejecutando funfun  con params:(%d,%c))",par,par2);
		

	
	mifun(par,par2);

	
}

int main(int argc, char *argv[]) {
	
	
	funfun(fun,8,'b');
	return 0;
}
