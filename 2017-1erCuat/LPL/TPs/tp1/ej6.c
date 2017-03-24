#include<stdio.h>
#include<string.h>

#define MAX 100
int search(char *cadena, char *buscar);
int largoCadena(char *s);

int main(int argc, char *argv[]){
	char cadena[] = "pparcial";
	char subcad[] = "parcial";
	
	printf("Cadena %s empieza en la posicion %d en %s\n", subcad, search(cadena, subcad), cadena);
	
}

int largoCadena(char *s){
	int largo = 0;
	for(int i = 0; s[i] != '\0'; i++){
		largo++;
	}

	return largo;

}

int search(char *cadena, char *buscar) {
	int i=0,j=0,pos=-1;

	/* Largo de Ambas Cadenas */
	int largo_original = largoCadena(cadena);
	int largo_buscar = largoCadena(buscar);

	/*
		Si la longitud de la cadena a buscar es mayor a 
		la original, retornamos -1
	*/ 
	if (largo_original < largo_buscar){
		return pos;
	}

	// diferencia entre longitudes, 
	// para saber hasta donde encajan
	int dif = largo_original - largo_buscar;
	//creo un comienzo a partir de donde analizar la cadena
	int comienzo = 0; 
	while((comienzo <= dif) && (pos == -1) ){
		j = 0;
		int match = 1;
		i = comienzo;
		//dentro de la cadena a buscar
		while((buscar[j] != '\0') && (match)){
			//asigno el primero
			//si son iguales avanzo con ambos y sigo
			if(cadena[i] == buscar[j]){
				i++;
				j++;
				pos = comienzo;
			} 
			else {
				j = 0;
				pos = -1;
				match = 0; 	
			} 
		}
		comienzo++;
	}
	return pos;
}