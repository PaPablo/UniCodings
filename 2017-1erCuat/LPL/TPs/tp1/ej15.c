#include <stdio.h>
#include <ctype.h>
#include <math.h>


#define MAX 10
#define MAX_ENTRADA 10

char *pedirLinea(char *s,int max);
int obtenerEntero();
int sumatoria(int numeros[],int tope);


int main(int argc, char const *argv[]) {
	int numeros[MAX];
	int entrada, cantidad = 0;
	while(cantidad < MAX){
		entrada = obtenerEntero();
		if(entrada != 0){
			numeros[cantidad++] = entrada;
		}
		else break;
	}


	int suma = sumatoria(numeros,cantidad-1);
	printf("Sumatoria: %d\n",suma);

	return 0;
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

int sumatoria(int numeros[],int tope){
	if(tope == -1){
		return 0;
	}
	else {
		return numeros[tope] + sumatoria(numeros, tope-1);
	}
}