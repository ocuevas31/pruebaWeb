#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <preguntas.h>

#define NUM_PREGUNTAS 100
#define NUM_TEMAS 3
#define NOTA_CORTE 8


struct fichaPregunta{	
	int tema;       /*tema sobre el que se pregunta*/
	char texto[50]; /*texto de la pregunta*/
	int respuesta;  /*0:falso, 1:verdadero*/
};

struct resultados{
	int preguntadas;
	int acertadas;
	float nota;
};

void inicializar(int usadas[], struct resultados recuento[]);

void cargarPreguntas(struct fichaPregunta cuestiones[]);

int preguntarTema(int tema, 
                  struct fichaPregunta cuestiones[], 
	          int usadas[], 
                  struct resultados recuento[]);

int elegirPregunta(int tema, struct fichaPregunta cuestiones[], int usadas[]);

void calificar(struct resultados recuento[]);

void recomendar (struct resultados recuento[]);


/* definición de cargar preguntas (V. preguntas.h) SÓlo se ha incluido, como muestra, una
   pregunta

void cargarPreguntas(struct fichaPregunta cuestiones[]){
	
	cuestiones[0].tema=1;                			 	
	strcpy (cuestiones[0].texto, "El creador de lenguaje C fue Dennis M. Ritchie");		
	cuestiones[0].respuesta=1; 		
} */



/*============================================================================*
 *                                    main                                    *
 *============================================================================*/ 

int main(void){

	int tema=1;
	int correctasTema;        /*respuestas correctas sobre un determinado tema*/
	int numeroPregunta;
	struct fichaPregunta lasPreguntas[NUM_PREGUNTAS];
	struct resultados recuento[NUM_TEMAS];
	int usadas[NUM_PREGUNTAS];     			  /*0:no usada, 1:usada*/
	int salirPorTestSuperado=0;
	int salirPorUsuario=0;                            /*0:no salir, 1:salir*/

	
	
	inicializar(usadas, recuento);	
	cargarPreguntas(lasPreguntas);

	
	/*bucle principal para preguntar*/
	do {
		
		correctasTema=preguntarTema (tema, lasPreguntas, usadas, recuento);
		
		if ((tema==NUM_TEMAS) && (correctasTema==2))
			salirPorTestSuperado=1;
		if ((tema <NUM_TEMAS)&&(correctasTema==2))
			tema++;
		else if ((tema !=1)&& (!salirPorTestSuperado)) 
			tema--;	
		printf("Para continuar pulse [0]. Para salir pulse [1] > "); 
		scanf("%d", &salirPorUsuario);
		
	
	} while ((!salirPorTestSuperado)&& (!salirPorUsuario));
	
	
	if (salirPorTestSuperado){
		 calificar(recuento);
		 recomendar(recuento);
        }

	system("pause");	
	return 0;
}


/*============================================================================*
 *                                inicializar                                 *
 *============================================================================*/   
 
void inicializar (int usadas[], struct resultados recuento[]){
	int i;

	for (i=0;i<NUM_PREGUNTAS;i++) usadas[i]=0;
	
	for (i=0;i<NUM_TEMAS;i++){
		recuento[i].preguntadas=0;
		recuento[i].acertadas=0;
		recuento[i].nota=0;
	}
	
}


/*============================================================================*
 *                                 preguntarTema                              *
 *============================================================================*/


int preguntarTema(int tema, 
		  struct fichaPregunta cuestiones[], 
	          int usadas[],
		  struct resultados recuento[]){
					
	int i;
	int respuesta;
	int numeroPregunta;
	int respuestasCorrectas;    /*las respuestas correctas en una
		                      tanda de preguntas*/
  				

	do {
		respuestasCorrectas=0; 
			
		/*una tanda son dos preguntas*/
		for (i=1;i<3;i++){	    
			/*elige la pregunta*/
			numeroPregunta= elegirPregunta(tema, cuestiones, usadas);
			/*haz la pregunta*/
			printf ("%s\n", cuestiones[numeroPregunta].texto);
			printf ("Introduzca Verdadero:[1] o Falso: [0] >");			 
			/*lee la respuesta*/
			scanf ("%d", &respuesta);
			/*evalua la respuesta*/
			recuento[tema-1].preguntadas++;
			if(respuesta == cuestiones[numeroPregunta].respuesta){
				respuestasCorrectas++; /*incrementa aciertos en tanda*/
				recuento[tema-1].acertadas++;
			}
		}
				
	} while (respuestasCorrectas ==1); /*mientras falle una */
	
	return (respuestasCorrectas);		
}

/*============================================================================*
 *                                 elegirPregunta                             *
 *============================================================================*/

int elegirPregunta(int tema, struct fichaPregunta cuestiones[], int usadas[]){

	int i=0;
	int numeroPregunta;
	
	/*busca pregunta no usada de tema*/
	
	while ((usadas[i]==1) || (cuestiones[i].tema != tema)) {
	        i++;
		
	}
	usadas[i]=1;
	numeroPregunta=i;
	
	return (numeroPregunta);
}

/*============================================================================*
 *                                 calificar                                  *
 *============================================================================*/

void calificar(struct resultados recuento[]){
	float notaTema;
	int i;
	
	for (i=0;i<NUM_TEMAS;i++){
		printf ("Numero de preguntas del tema %d= %d\n", i+1,
		         recuento[i].preguntadas);
		printf ("Numero de respuestas correctas del tema %d= %d\n", i+1,
		          recuento[i].acertadas);

		notaTema= (	(float)recuento[i].acertadas / 	
	            		(float)recuento[i].preguntadas )*10;

	        recuento[i].nota=notaTema;
    		printf ("Nota del tema %d = %.2f\n", i+1, notaTema);
	}
}

/*============================================================================*
 *                                 recomendar                                 *
 *============================================================================*/

void recomendar(struct resultados recuento[]){
	int i;
	for (i=0;i<NUM_TEMAS;i++){
		if (recuento[i].nota<NOTA_CORTE)
			printf ("Se recomienda repasar el tema %d\n", i+1);
		
	}
	
}



