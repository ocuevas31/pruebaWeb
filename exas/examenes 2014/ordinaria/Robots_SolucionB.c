#include <stdio.h>

# define RANGE 1.0
# define MAX_ROBOTS 10
# define MAX_CICLOS 10000

// Apartado 1. Definición estructura
struct t_sensor{
 char nombre_s[5]; // nombre del sensor
 double peso[2];   // vector con el peso del sensor para cada rueda 1
};

struct t_robot{
	char nombre_r[20];
	int n_sensores;
	struct t_sensor sensor[16];
};

// prototipos de las funciones
void inicializar_simulacion(int *robots, int *ciclos);
void inicializar_robot(struct t_robot *robotillo);
void inicializar_sensor(char nombre[4]);
void wheels_set_speed(double v1, double v2);

// ---------------Funciones que se asume que existen 
// ---------------y por lo tanto no se piden en el examen
void inicializar_sensor(char nombre[4]){
	// función que inicializa el sensor
	printf ("\n\nel sensor % s ha sido activado\n", nombre);
}

double sensor_get_value(char nombre[4]){
	// función que devuelve la lectura de distancia del sensor
	// para probar, siempre un valor fijo
	return 0.4;
}

void wheels_set_speed(double v1, double v2){
	printf ("establecida la velocidad de la rueda 1, valor %f\n", v1);
	printf ("establecida la velocidad de la rueda 2, valor %f\n", v2);	
}  
// --------------------------------------------------   
    
// Apartado 2. Inicializar simulación
void inicializar_simulacion(int *robots, int *ciclos){
	do{
		printf("Numero de robots?\n");
		scanf("%i", robots);
	} while ( (*robots <1) || (*robots >MAX_ROBOTS));
			
	do{
		printf("Numero de ciclos de simulacion?\n");
		scanf("%i", ciclos);
	} while ( (*ciclos <1) || (*ciclos >MAX_CICLOS));
}

// Apartado 3. Inicializar un robot
void inicializar_robot(struct t_robot *robotillo){
	// función que recibe como parámetro una variable de tipo robot
	// paso por referencia: se va a modificar el contenido de la variable
    int i,r;
    
	printf("\nNombre del robot?\n");
	scanf("%s", (*robotillo).nombre_r);
	
	// se inicializan los sensores de distancia
	do{
	   printf("Numero de sensores de distancia?:(8 o 16)\n");
		  scanf("%i",&(*robotillo).n_sensores);
	}while (((*robotillo).n_sensores!= 8) && ((*robotillo).n_sensores!=16));
    
	for (i=0; i < (*robotillo).n_sensores; i++){
		   // damos nombre al sensor: ds1, ds2,..
		   // usando la función sprintf
		   sprintf((*robotillo).sensor[i].nombre_s, "ds%i", i);
		   // llamamos a la función inicializar sensor
     inicializar_sensor((*robotillo).sensor[i].nombre_s);
		   // leemos los valores de los pesos
		   for (r=0; r<=1;r++){
         printf("Introduzca el peso del sensor %s ",(*robotillo).sensor[i].nombre_s,r );
         printf("para la rueda %i\n",r );
				     scanf("%lf", &(*robotillo).sensor[i].peso[r]);
     }
	}
}

// Apartado 4. Mover robot
void mover_robot(struct t_robot *robotillo){
	int i,r;
	double distancia; //lectura de distancia de los sensores
	double velocidad[2]={0.0,0.0}; // vector con la velocidad de las dos ruedas.
	
	// se calcula la velocidad de cada rueda de ese sensor
	for (i = 0; i < (*robotillo).n_sensores; i++) {	// para todos los sensores
		// obtenemos la distancia medida por el sensor
		distancia = sensor_get_value((*robotillo).sensor[i].nombre_s);
		// sumamos a la velocidad la aportación ponderada de ese sensor
		// esto se repite para cada rueda
	   	for (r = 0; r <=1; r++){
        	velocidad[r]= velocidad[r]+((*robotillo).sensor[i].peso[r] * (1.0 - (distancia / RANGE)));
        }
    }
	
    // se establece la velocidad usando la función wheels_set_speed
    printf("\n\nmoviendo robot %s \n", (*robotillo).nombre_r);
    wheels_set_speed(velocidad[0], velocidad[1]);
}


// Apartado 5. Programa principal
int main (void){
    int n_ciclos; // numero de ciclos de la simulacion
	   int n_robots; // numero de robotos en la simulación
	   struct t_robot robots[MAX_ROBOTS];
	   int i, c;
	
    // incializar simulacion
	   inicializar_simulacion ( &n_robots, &n_ciclos);
    printf("Numero de robots %i\, Numero de ciclos %i\n",n_robots, n_ciclos);
   
	  // inicializar robots
	  for (i=0; i< n_robots;i++){
		     inicializar_robot (&robots[i]);
   }
	
	  // simulación
	  printf("\n\n\n Iniciando simulacion\n");
   for (c=0; c<n_ciclos;c++){
       printf("\n\n--- simulacion. ciclo %i ---\n", c);
		     // para cada ciclo, mover todos los robots
		     for (i=0; i< n_robots;i++){
			        mover_robot (&robots[i]);
       }
   }
	  system("pause");
}

