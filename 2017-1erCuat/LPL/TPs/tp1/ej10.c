#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PALABRAS_RESERVADAS 12

char *palabras_reservadas[] = {"#include","break","case","default","do","else","for","if","return","switch","void","while"};

int inicializar_arreglo(int *arreglo, int tope){
	for(int i = 0; i < tope;i++){
		arreglo[i] = 0; 
	}
	return 0;
}

int esPalabraReservada(char *cadena){
	for(int i = 0; i < MAX_PALABRAS_RESERVADAS; i++){
		if(!strcmp(cadena, palabras_reservadas[i]))
			return i;	
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	
	int ocurrencias[MAX_PALABRAS_RESERVADAS];
	inicializar_arreglo(ocurrencias,MAX_PALABRAS_RESERVADAS);


	FILE *archivo;
	char *line = NULL;
	size_t len = 0; 
	ssize_t read;



	char *token;
	char delim[] = " \t(){};\n!=";
	archivo = fopen("stdcopy.c","r");

	int cant = 0;
	int reservada;
	if(archivo == NULL)
		exit(EXIT_FAILURE);

	while((read = getline(&line, &len, archivo)) != -1){
		token = strtok(line, delim);

		while(token != NULL){

			if((reservada = esPalabraReservada(token)) != -1){
				ocurrencias[reservada]++;
			}
			
			token = strtok(NULL, delim);

		}

	}

	for(int i = 0; i < MAX_PALABRAS_RESERVADAS; i++){
		printf("%s : %d\n", palabras_reservadas[i],ocurrencias[i]);
	}
	return 0;
}
