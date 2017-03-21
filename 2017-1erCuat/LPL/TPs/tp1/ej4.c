#include <stdio.h>

#define MAX 30
//
char *getline(char *s,int max){
	int i;
	char c;
	
	for(i=0 ; i<max ; i++ ){
		c = getchar();
		if ((c == '\n') || (c == '\0')){
			break;
		}
		s[i]=c;
	}
	return s;
}

int main(int argc, char *argv[]){
	
	char cadena[MAX];
	getline(cadena, MAX);
	int i;
	for(i = 0; i < MAX; i++){
		printf("%c",cadena[i]);
	}
}
