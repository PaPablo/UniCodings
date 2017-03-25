#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX_ENTRADA 10

int obtenerEntero();
int mostrarMes(int entrada);
char *pedirLinea(char *s,int max);

int main(int argc, char const *argv[])
{
	int entrada;
	do {
		//pido numero
		entrada = obtenerEntero();
		mostrarMes(entrada);

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

int mostrarMes(int entrada){
	switch(entrada){
		case 1: 
			printf("Enero\n");
			break;
		case 2: 
			printf("Febrero\n");
			break;
		case 3: 
			printf("Marzo\n");
			break;
		case 4: 
			printf("Abril\n");
			break;
		case 5: 
			printf("Mayo\n");
			break;
		case 6: 
			printf("Junio\n");
			break;
		case 7: 
			printf("Julio\n");
			break;
		case 8: 
			printf("Agosto\n");
			break;
		case 9: 
			printf("Septiembre\n");
			break;
		case 10: 
			printf("Octubre\n");
			break;
		case 11: 
			printf("Noviembre\n");
			break;
		case 12: 
			printf("Diciembre\n");
			break;
		default:
			return 1;
	}
	return 0;
}