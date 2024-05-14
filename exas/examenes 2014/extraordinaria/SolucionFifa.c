#include <stdio.h>
#include <stdlib.h>

#define MAXSEL 16
#define MAXJUG 20
#define NUMGRUPOS 4
#define NUMSELECCIONES 4

struct jugador {
int id;
char nombre [20];
int numgoles;
};

struct seleccion {
int id;
char nombre [20];
int cabezaserie;
float coeficienteUEFA;
struct jugador jugadores[MAXJUG];
};

void anadir_seleccion(struct seleccion selecciones[MAXSEL], int numsel);
void generar_grupos(struct seleccion selecciones [MAXSEL], int grupos [NUMGRUPOS][NUMSELECCIONES]);
void ganadores_fase_inicial (struct seleccion selecciones [MAXSEL], int grupos [NUMGRUPOS][NUMSELECCIONES], int ganadores_fase1 [NUMGRUPOS]);
void ordenar_jugadores(struct seleccion sel, struct jugador jugadores_ordenados[MAXJUG]);

int main(int argc, char *argv[])
{
  struct seleccion selecciones[MAXSEL]; 
  int grupos [NUMGRUPOS][NUMSELECCIONES];
  int ganadores_fase1[NUMGRUPOS];
  struct jugador jugadores_ordenados[MAXJUG];
  int i;
  
  for(i = 0; i < MAXSEL; i++){
     anadir_seleccion(selecciones,i);
     }
     
  generar_grupos(selecciones, grupos); 
  ganadores_fase_inicial (selecciones, grupos, ganadores_fase1);
  
  printf("Los ganadores de la fase inicial son: ");
  for(i = 0; i < NUMGRUPOS; i++){
          printf("El ganador del grupo %i es %s\n", i+1, selecciones[ganadores_fase1[i]].nombre);
          ordenar_jugadores(selecciones[ganadores_fase1[i]], jugadores_ordenados);
          printf("Su maximo goleador es %s\n",jugadores_ordenados[0].nombre);       
  }


  
  
  system("PAUSE");	
  return 0;
  
  
  
}

void anadir_seleccion(struct seleccion selecciones[MAXSEL], int numsel){
     int i;
   
     printf("Nombre seleccion: ");
     scanf("%s",&selecciones[numsel].nombre);
     printf("Coeficiente UEFA: ");
     scanf("%f",&selecciones[numsel].coeficienteUEFA);
     printf("Introduzca ahora los jugadores: ");

     for(i = 0; i < MAXJUG; i++){
         selecciones[numsel].jugadores[i].id=i+1;
         printf("Nombre jugador: ");
         scanf("%s",&selecciones[numsel].jugadores[i].nombre);
         selecciones[numsel].jugadores[i].numgoles=0;
     }
     
     selecciones[numsel].id = numsel+1;
     
     if(numsel<4)
      selecciones[numsel].cabezaserie=1;
     else
      selecciones[numsel].cabezaserie=0;
}

void generar_grupos(struct seleccion selecciones [MAXSEL], int grupos [NUMGRUPOS][NUMSELECCIONES]){
     int i, j;
     for(i = 0; i < NUMSELECCIONES; i++){
        for(j = 0; j < NUMGRUPOS; j++){
              grupos[i][j]=selecciones[(i*NUMGRUPOS)+j].id;
              }}
              
     }

void ganadores_fase_inicial (struct seleccion selecciones [MAXSEL], int grupos [NUMGRUPOS][NUMSELECCIONES], int ganadores_fase1 [NUMGRUPOS]){
     int id_ganadora=0;
     int id_actual=0;
     float coef_ganadora=0;
     int i,j;
     
     for(i=0; i<NUMGRUPOS; i++){
         id_ganadora=0;
         coef_ganadora=0;

         for(j=0; j<NUMSELECCIONES; j++){
             id_actual = grupos[i][j];
             
             if(selecciones[id_actual].coeficienteUEFA>coef_ganadora)
             {
                 id_ganadora=id_actual;
                 coef_ganadora=selecciones[id_ganadora].coeficienteUEFA;                                                
             }
         }
         ganadores_fase1[i]=id_ganadora;
     }     
     
     }

void ordenar_jugadores(struct seleccion sel, struct jugador jugadores_ordenados[MAXJUG]){
     int i, hay_cambio = 1;
     struct jugador jug_aux;
     
     for(i = 0; i < MAXJUG; i++){
           jugadores_ordenados[i] = sel.jugadores[i];
     }
     
     while(hay_cambio){
        hay_cambio = 0;
        for(i = 0; i < MAXJUG-1; i++){
              if(jugadores_ordenados[i+1].numgoles > jugadores_ordenados[i].numgoles){
                  jug_aux = jugadores_ordenados[i];
                  jugadores_ordenados[i] = jugadores_ordenados[i+1];
                  jugadores_ordenados[i+1] = jug_aux;
                  hay_cambio = 1;
              }
        }
     }
}




