#include <stdio.h>


void met()
{
	
	printf("Hola  ");
}


int dev()
{
	return 5;
}

int sig(int n)
{
	
	return n+1;
}

char fun(char x[])
{
	return x[0];
}


char funfun(char x[],int p)
{
	return x[p];
}


void mos(int w[],int tam)
{
	int ind;
	
	printf("\n|");
	
	for(ind=0;ind<tam;ind++)
	printf("%d ",w[ind]);
	printf("|\n");
	
	
}

int funA(int p)
{
	
	return p+p;
}
int funB(int x)
{
	return x*x;
}

int mifun(int k)
{
	int local;
	
	printf("Dentro k=%d ",k);
	local= funA(k)+funB(k);
	printf("Dentro devuelve=%d ",local);
	
	return local;
}

int main() 
{
	int ind,res;
	int v[10];	
	
	met();	
	
	for(ind=0;ind<10;ind++)
	{
		met();
		
		
	}
	printf("\n");
	
	
	printf("%d\n",res);
	res=dev();
	printf("%d\n",res);
	
	printf("%d\n",dev());
	res=dev()*dev();
	printf("%d\n",res);
	
	
	res=sig(3);
	printf("%d\n",res);
	printf("%d\n",sig(res));
	
	printf("%d\n",sig(sig(7)));
	
	res=sig(dev());
	printf("%d\n",res);
	
	
	
	for(ind=dev();ind<10;ind=sig(ind))
	printf("%d,",ind);
	
	
	printf("\n%c\n",fun("Pepe"));
	
	
	
	for(ind=9;ind>=0;ind=sig(ind)-2)
	printf("%c",funfun("Multiverso",ind));
	
	
	printf("\n%d\n",v[0]);
	
	for(ind=0;ind<6;ind++)
	v[ind]=dev();
	
	
	for(ind=5;ind<10;ind++)
	v[ind]=sig(dev());
	
	
	mos(v,10);
		
	mos(v,5);
	mos(v,8);
	
	printf("Main llamando a mifun con parametro valiendo =%d\n",2);
	ind=mifun(2);
	printf("\nMain ind=%d ",ind);

	ind=3;
	printf("Main llamando a mifun con parametro valiendo =%d\n",ind);
	ind=mifun(ind);
	printf("\nMain ind=%d ",ind);

	
	//getch();
	return 0;
}





/*
Hola  Hola  Hola  Hola  Hola  Hola  Hola  Hola  Hola  Hola  Hola
31
5
5
25
4
5
9
6
5,6,7,8,9,
P
osrevitluM
4203184

|5 5 5 5 5 6 6 6 6 6 |

|5 5 5 5 5 |

|5 5 5 5 5 6 6 6 |
Main llamando a mifun con parametro valiendo =2
Dentro k=2 Dentro devuelve=8
Main ind=8 Main llamando a mifun con parametro valiendo =3
Dentro k=3 Dentro devuelve=15
Main ind=15


*/



