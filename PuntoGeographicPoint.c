#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define PI 3.14159265
#define largo 744
#define alto 500



int mapa[alto][largo];
int xT[alto*largo];
int yT[alto*largo];
int xActual = 265; //Coordenadas iniciales (265)
int yActual = 70; // En el oceano pacifico (70)
int xRta; //El mejor candidato actualmente
int yRta; //El mejor candidato actualmente
int xCan; //Candidatos a x
int yCan; //Candidatos a y
double radioRta;

//Metodos
void imprimirMapa(char s[]);
double rad(int x0, int y0);
double latitud(int x);
double longitud(int y);
void nCordenada();

FILE *arc;
int i = 0;
int j = 0;
int k = 0;
int totalTierra = 0;
double memoria = 0;

int main(){
 
arc = fopen("map_data.txt", "r");
i = 0;
j = 0;
k = 0;
totalTierra = 0;


if(arc){
        //lee todo el archivo 
         const size_t tam = 10000;
         char* linea = malloc(tam);
         while (fgets(linea, tam, arc) != NULL) //Lee la linea
		{
            if(k<j){
                    k = j;
            }
            j = 0;
			char *recorte = strtok(linea, " ");  //Toma el primer elemento antes de la coma
			while (recorte != NULL)
			{
			      	double temp = strtod(recorte, NULL);
			      	
			      	mapa[i][j] = temp; 
			      	if(mapa[i][j] == 1) 
			      	{
                                  xT[totalTierra] = i;
                                  yT[totalTierra] = j;
                                  totalTierra += 1;
                                  }
				recorte = strtok(NULL, " "); 
				j += 1;
				
			}
            i = i+1;
		}
		free(linea); 
fclose(arc);      
         
}

}
