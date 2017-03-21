#include <stdio.h>
/* (==,,!,!=,+,/,*,%,+=,-=,*=,/=,>,<,>=,<=) 

	=!+/*%-><*/

//constantes
#define TRUE 1
#define FALSE 0

#define MAX 200
int mostrar_cadena(char *cadena,int tope);
int contar_operadores(char *cadena, int tope);

int main(int argc, char const *argv[]) {

	char cadena[MAX] = "2 == 1";
	
	int i = 0;
	char c;
	do {
		c = getchar();
		cadena[i++] = c;
		if(c == '\n'){
			printf("%d\n", contar_operadores(cadena,i));		
			i = 0;
		}
	} while(c != EOF);
	return 0;
}

int mostrar_cadena(char *cadena,int tope) {
	for(int i = 0; i < tope; i++){
		printf("%c",cadena[i]);
	}
	printf("\n");
}

int contar_operadores(char *cadena, int tope) {

	printf("tope:%d", tope);
	mostrar_cadena(cadena,tope);
	int operadores = 0;
	int puede_ser_doble = FALSE;
	//recorro la cadena
	for(int i = 0; i < tope ; i++) {
		//si puede ser un operador de dos caracteres y encontré un =
		if(puede_ser_doble && (cadena[i] == '=')){
			continue;
		}
		else {
			// si no, analizo el caracter
			switch(cadena[i]){
				case '+':
				case '-':
				case '*':
				case '/':
				case '<':
				case '>':
				case '!':
				case '=':
					//cuento
					operadores++;
					puede_ser_doble = TRUE;
					break;
			}
		}
		
	}
	//regreso la cantidad de operadores
	return operadores;
}

