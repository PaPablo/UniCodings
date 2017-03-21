#include <stdio.h>

int revisar_balanceo(char *cadena);

int main(){

	char cadena[] = "()[]{}";

	revisar_balanceo(cadena);

	return 0;
}

int revisar_balanceo(char *cadena){
	char apertura = 0;
	for(int i = 0; cadena[i] != '\0'; i++) {
		//primer switch
		switch(cadena[i]){
			case '(':
			case '[':
			case '{':
				if(apertura != 0){
					printf("ERROR\n");
					return 1;
				}
				apertura = cadena[i];
				break;
			default:
				//segundo switch
				switch(cadena[i]){
					case ')':
						if(apertura == '('){
							apertura = 0;
						} 
						else {
							printf("ERROR\n");
							return 1;
						}
						break;
					case ']':
						if(apertura == '['){
							apertura = 0;
						}
						else {
							printf("ERROR\n");
							return 1;
						}
						break;
					case '}':
						if(apertura == '{'){
							apertura = 0; 
						}
						else {
							printf("ERROR\n");
							return 1;
						}
						break;
				}
				break;
				//fin segundo switch
		}
		//fin primer switch


	}
	if((apertura != 0)){
		printf("ERROR\n");
		return 1;
	}
	printf("Todo en orden\n");
	return 0;

}