#include <stdio.h>

int largoCadena(char *s){
	int largo = 0;
	for(int i = 0; s[i] != '\0'; i++){
		largo++;
	}

	return largo;

}


int esPalindromo(char *s){
	int principio = 0;
	int fin = largoCadena(s);

	int medio = fin / 2;

	int i,j = fin-1;

	for(i=0; i < medio; i++){
		if (s[i] != s[j]){
			return 0;
		}
		j--;
	}

	if(i == medio){
		return 1;
	}


}

int main(int argc, char const *argv[])
{

	char cadena[] = "neuquen";

	printf("%d\n", esPalindromo(cadena));
		
	return 0;
}