#include <stdio.h>
	
int contarCosas(char *s){

	int lineas = 0,
		palabras = 0,
		caracteres = 0;

	//recorro la cadena y voy contando lo que encuentro
	for(int i = 0; s[i] != '\0' ; i++){
		caracteres++;
		if(s[i] == '\n'){
			lineas++;
			palabras++;
		}
		if((s[i] == ' ') || (s[i] == '\t')){
			palabras++;
		}
		if(s[i] == EOF){
			break;
		}
	}
	
	printf("lineas: %d\npalabras: %d\ncaracteres: %d\n", lineas, palabras, caracteres);	

}

int main(int argc, char const *argv[])
{
	char cadena[]= "asdf asdf\n";
	contarCosas(cadena);
	return 0;
}