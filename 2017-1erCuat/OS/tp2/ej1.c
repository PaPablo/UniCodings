#include <unistd.h>
#include <syscall.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdlib.h>
#include <string.h>

#define MAX_ARGUMENTOS 10
#define MAX_LINEA 100

int nueva_linea(char *linea,int tope);
int print_prompt();

int main(int argc, char const *argv[])
{
	while(1){

		char linea[MAX_LINEA];
		pid_t child_pid;
		int status;

		
		//pido input desde la entrada estandar
	 	print_prompt();
	 	
	 	scanf("%[^\n]",linea);
	 	getchar();
		//delimitador para separar comandos
	 	char delim1[] = " ";
	 	char *comando[MAX_ARGUMENTOS];
	 	//palabras spliteadas
	 	char *palabra;

	 	//comienzo tokenización
	 	palabra = strtok(linea,delim1);
	 	int i = 0; 
	 	while(palabra != NULL){
	 		comando[i] = malloc(strlen(palabra) + 1);

	 		strcpy(comando[i],palabra);
	 		i++;
	 		palabra = strtok(NULL,delim1);
	 	}
	 	comando[i] = NULL;
	 	
	 	//cerré mi arreglo de argumentos
	 	
		if(child_pid = fork()){
			//proceso padre
			waitpid(child_pid,&status, 0);
			
		}
		else {
			//proceso hijo
			execv(comando[0],comando);
		}


	}	

	return 0;
}

int nueva_linea(char *linea,int tope){
	int i = 0; 
	char c;
	do{
		c = getchar();
		if((c == '\n') || (c == EOF))
			break;
		linea[i] = c;
		i++;
	} while(i < tope);
	linea[i] = '\0';
	return i-1;
}

int print_prompt(){
	printf("Milonga$ ");
}


