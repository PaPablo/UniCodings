#include <stdio.h>

/*
	Ejercicio 2
*/



int main(int argc, char *argv[]) {
	
	int entrada;
	scanf("%d", &entrada);
	
	int i;
	for(i = 1; i <= 12 ; i++){
		printf("%d * %d = %d\n", entrada, i, entrada*i);
	}

	return 0;
	
}

