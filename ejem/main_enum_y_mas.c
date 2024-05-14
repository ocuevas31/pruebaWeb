#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#define DEBUG

/*
macros
*/
#define MIMACRO  printf("Hola\n"); 
#define MOSTRAR(x) printf("%d\n",x);


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

enum dias {LUNES,MARTES,MIERCOLES,JUEVES,VIERNES,SABADO,DOMINGO};

union miunion
{
	int c1;
	float c2;
};




typedef int entero;



int main(int argc, char *argv[]) 
{

enum dias d;


d=LUNES;
/*ERROR
d="LUNES";*/


if (d==LUNES) printf ("Dia es Lunes\n");	
/*....*/




/*union*/

union miunion mivar;



mivar.c1=8;

printf("%d\n",mivar.c1);

mivar.c2=3.5;

printf("%.1f\n",mivar.c2);

/*noooo
printf("%d\n",mivar.c1);
*/


/*macros*/

MIMACRO;


int a=5,b=7;
MOSTRAR(a);
MOSTRAR(b);


/*typedef*/


entero k=5;

MOSTRAR(k);



/*  strtod,strtol, atoi...*/

int num=atoi("15");
printf("%d\n",num+5);


num=atoi("hola15");
printf("%d\n",num); /*0*/

char *pana;
double pi;

pi=strtod("3.1415926",&pana);

printf("%f\n",pi);

char str[30] = "2030300 This is test";
   char *ptr;
   long ret;

   ret = strtol(str, &ptr, 10);
   printf("The number(unsigned long integer) is %ld\n", ret);
   printf("String part is |%s|", ptr);


	
	
	#ifdef DEBUG
		printf("\nDepurando\n");
		
	#endif
	
	return 0;
}

#endif
