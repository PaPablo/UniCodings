#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int esPalabraReservada(char *cadena){

	if(!strcmp(cadena,"while"))
		return 1;
	else
		return 0;
}

int main(int argc, char const *argv[])
{
	FILE *archivo;
	char *line = NULL;
	size_t len = 0; 
	ssize_t read;



	char *token;
	char delim[] = " \t(){};\n!=";
	archivo = fopen("stdcopy.c","r");

	int cant = 0;
	int a;
	if(archivo == NULL)
		exit(EXIT_FAILURE);

	while((read = getline(&line, &len, archivo)) != -1){
		token = strtok(line, delim);

		while(token != NULL){
			if(a = esPalabraReservada(token)){
				printf("%s es while: %d\n", token,a);
				printf("yey\n" );
			}

			
			token = strtok(NULL, delim);

		}

	}

	return 0;
}
