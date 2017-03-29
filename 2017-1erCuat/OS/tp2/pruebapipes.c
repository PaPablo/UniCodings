#include <unistd.h>
#include <syscall.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdlib.h>
#include <string.h>

#define MAX_ARGUMENTOS 10
#define MAX_PIPES 10
#define MAX_LINEA 100

int nueva_linea(char *linea,int tope);
int print_prompt();

typedef char *comando[MAX_ARGUMENTOS];

int main(int argc, char const *argv[])
{


	char linea[MAX_LINEA];
	pid_t child_pid;
	int status;

	
	//pido input desde la entrada estandar
  	nueva_linea(linea, MAX_LINEA);

	//delimitador para separar comandos
 	char delim1[] = " ";
	char pipe[] = "|";


 	comando cmds[MAX_PIPES];

 	char *partes[MAX_PIPES];
 	//palabras spliteadas
 	char *parte;

 	int i = 0;
 	parte = strtok(linea,pipe);

 	while(parte != NULL){
	 	//comienzo tokenización
	 	partes[i] = malloc(strlen(parte)+1);
	 	strcpy(partes[i],parte);
 		i++;		
 		parte = strtok(NULL,pipe);
 	}
 	partes[i] = NULL;
 	int cantidad_comandos = i-1;
 	for (int i = 0; partes[i] != NULL; i++){
 		int j = 0; 
		char *palabra = strtok(partes[i],delim1);

		while(palabra != NULL){

			cmds[i][j] = malloc(strlen(palabra) + 1);

			strcpy(cmds[i][j],palabra);
			j++;
			palabra = strtok(NULL,delim1);

		}
		cmds[i][j] = NULL; 		
 	}


 	i = 0;
 	int j= 0; 
 	while((cmds[i][j] != NULL) && (i <= cantidad_comandos)){
 		while(cmds[i][j] != NULL){
 			printf("%s\n", cmds[i][j]);
 			j++;
 		}
 		j=0;
 		printf("%d\n", i);
 		i++;
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


