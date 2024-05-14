#include <stdio.h>



void m(char c[])
{
	printf("\n%s\n",c);
}

int  mm(char c[])
{
	printf("\n%s\n",c);
	
	return 1;
}



int main() 
{
	int x;
	
	
	
	for(x=0;x<10;x++)
	printf("%d ",x);
	
	
	x=0;
	for(m("x=0");x<10 && mm("x<10 ?");m("x++"))
	{
		m("printf(\"%d \",x);");
		x++;
	}
	
	
	
	
	return 0;
}
