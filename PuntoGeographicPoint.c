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

   double mem = 0;
    int iteracion = 2000;
	i = 0;
	
    double nuevo = 0;
    double viejo = 0;
    while(i<iteracion){
          

                 nCordenada();          
          nuevo = rad(xCan,yCan);
          viejo = rad(xActual,yActual);
            double alpha = exp(nuevo - viejo);
	  
	     if(nuevo>radioRta){//Tener el del radio mas grande 
                            xRta = xCan;
                            yRta = yCan;
                            radioRta = nuevo;                                      
                                      }
                   if(alpha > 1){
                            alpha = 1;
                            }
                   mem = (double) rand()/RAND_MAX;
                   if(alpha>mem){
                                 xActual = xCan;
                                 yActual = yCan;

                                 }
//                 printf("Iteracion %d : %d %d, %f\n", i, xRta, yRta,radioRta);
//                 printf("Iteracion %d : %d %d, %f\n", i, xActual, yActual,radioRta);

	i = i+1;
          }
//Imprime los resultados para el .py
// x y radio
    FILE *apy =fopen("resultados.txt","w+");    
    fprintf(apy,"%d %d %.2f",xRta, yRta, radioRta);


printf("Las coordenadas del punto mas alejado son: %.3f %.3f\n", longitud(yActual), latitud(xActual));


    
}




//Imprime el mapa
void imprimirMapa(char s[]){
    
    FILE *arch =fopen(s,"w+");    
    for(i = 0;i<alto;i++){
      for(j = 0;j<largo;j++){
            fprintf(arch,"%d ",mapa[i][j]);
            }
            fprintf(arch,"\n");
    } 
    
}
	
//Calcula la distancia al punto más cercano en tierra
double rad(int x0, int y0){
       double rta = (double) RAND_MAX;
       for(k = 0;k<totalTierra;k++){
             memoria = sqrt( pow(((double) x0- (double) xT[k]),2) + pow(((double) y0-(double) yT[k]),2));

             if(memoria<rta){
                       rta = memoria;
                       }
             }
//                    printf("Radio = %f \n", memoria);
       return rta;
       }

//Calcula un punto cercano al actual
void nCordenada(){
          double rx= ((double)rand()/RAND_MAX);     
          double ry= ((double)rand()/RAND_MAX);     
          xCan = xActual;
          yCan = yActual;
if(rx > 0.5){ //Decide si cambiar x o y
           if(ry > 0.5){
                 xCan += 1;
                      }
          else{
               xCan -= 1;
               }
}
else{
          if(ry > 0.5){
                yCan += 1;
                }
          else{
               yCan -= 1;
               }     
               }          

     }  
	
//Retorna la latitud de ese punto en x
double latitud(int x){
       double xx = (double) x; 
       double m = (-90.0/250)*xx + 90.0;
       return m;
       }
double longitud(int y){
       double yy = (double) y; 
       double m = (360.0/744.0)*yy - 180.0;
       return m;
       } 

}
