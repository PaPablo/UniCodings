#include <stdio.h>

#define MAX 30
//
int nueva_linea(char *s,int max){
	int i;
	char c;
	
	while(((c = getchar())!=EOF) || (c != '\n')){
		s[i++] = c;
	}
	s[i] = '\0';

	return i;
}

int main(int argc, char *argv[]){
	
	char cadena[MAX];
	nueva_linea(cadena, MAX);
	int i;
	for(i = 0; cadena[i] !='\0'; i++){
		printf("%c",cadena[i]);
	}
	printf("\n");
}
