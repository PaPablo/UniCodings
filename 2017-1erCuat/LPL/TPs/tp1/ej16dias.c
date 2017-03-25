#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX_ENTRADA 10
int obtenerEntero();
int mostrarDiaSemana(int entrada);
char *pedirLinea(char *s,int max);

int main(int argc, char const *argv[])
{
	int entrada;
	do {
		//pido numero
		entrada = obtenerEntero();
		mostrarDiaSemana(entrada);

	} while (entrada != 0);
	
	return 0;
}

int obtenerEntero(){
	char linea[MAX_ENTRADA];
	int correcto,numero;

	do{
		correcto = 1; numero = 0; 
		pedirLinea(linea, MAX_ENTRADA);
		for(int i = 0; linea[i] != '\0'; i++){
			//si no es digito, corto y pido entrada de nuevo
			if(!isdigit(linea[i])){
				printf("Usted no ingresó un entero, intente nuevamente\n");
				correcto = 0;
				break;	
			}
			/* Si es digito, voy armando el numero.
			* Corro el numero que ya está a la derecha y
			* le agrego al final el numero representado
			* por el caracter en linea[i] 
			* (resto 0x30 para que quede el valor numerico y no de caracter)
			* */
			numero =(numero*pow(10,i)) + linea[i] - 0x30;
		}
	} while(!correcto);
	return numero;
}

char *pedirLinea(char *s,int max){
	int i;
	char c;
	
	for(i=0 ; i<max ; i++ ){
		c = getchar();
		if ((c == '\n') || (c == EOF)){
			s[i] = '\0';
			break;
		}
		s[i]=c;
	}

	return s;
}

int mostrarDiaSemana(int entrada){
	switch(entrada){
		case 1: 
			printf("Lunes\n");
			break;
		case 2: 
			printf("Martes\n");
			break;
		case 3: 
			printf("Miercoles\n");
			break;
		case 4: 
			printf("Jueves\n");
			break;
		case 5: 
			printf("Viernes\n");
			break;
		case 6: 
			printf("Sabado\n");
			break;
		case 7: 
			printf("Domingo\n");
			break;
		default:
			return 1;
	}
	return 0;
}