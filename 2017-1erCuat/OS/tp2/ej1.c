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
#define MAX_CONDS 10

int print_prompt();

typedef char *pipeds[MAX_ARGUMENTOS];
typedef pipeds comando[MAX_PIPES]; 

int main(int argc, char const *argv[])
{
	while(1){

		char linea[MAX_LINEA];
		pid_t child_pid;
		int status;
		int no_termino_bien; //0 si termino bien, distinto de 0 si no
		
		//pido input desde la entrada estandar

		do{
			linea[0] = '\0';
			print_prompt();
		  	scanf("%[^\n]",linea);
			getchar();
		} while(strlen(linea)==0);

		//delimitador para separar comandos
	 	char delim1[] = " ";
		char pipe[] = "|";
		char ampers[] = "&&";
		int cantidad_condicionados;
		int cantidad_comandos[MAX_CONDS];

		/*	
		*	Acá guardamos todos los comandos
		*	en la fila i guadamos el i-ésimo
		*	comando, y en sucesivas columnas
		*	los argumentos de éste
		*/

	 	comando cmds[MAX_CONDS];
	 	
	 	/*
	 	*	Conseguir los pedazos entre los &&
	 	* 	Cada elemento del arreglo es lo que se encuentra entr &&
	 	*/
		int k = 0;
		char *condicionados[MAX_CONDS];
		char *cond;
		cond = strtok(linea,ampers);
		while(cond != NULL){
			condicionados[k] = malloc(strlen(cond)+1);
			strcpy(condicionados[k],cond);
			k++;
			cond = strtok(NULL,ampers);
		}
		condicionados[k] = malloc(sizeof(NULL));
		condicionados[k] = NULL;
		int cant_condicionados = k;

	 	/*
	 	*	Me genera una matriz en la que el elemento k,i es 
	 	*	el i-esimo comando del pipe en el k-esimo comando 
	 	*	condicional
	 	*	Consigo los pedazos entre los 
	 	*	Si pongo 'ls | grep cosas'
	 	*	me devuelve "ls" y "grep cosas"
	 	*/
	 	char *partes[MAX_CONDS][MAX_PIPES];
	 	char *parte;
	 	for (k = 0; condicionados[k] != NULL;k++){
		 	int i = 0;
		 	parte = strtok(condicionados[k],pipe);
		 	while(parte != NULL){
			 	//comienzo tokenización
			 	partes[k][i] = malloc(strlen(parte)+1);
			 	strcpy(partes[k][i],parte);
		 		i++;		
		 		parte = strtok(NULL,pipe);
		 	}
		 	partes[k][i] = malloc(sizeof(NULL));
		 	partes[k][i] = NULL;
		 	cantidad_comandos[k] = i;
	 	}

	 	/*	
	 	*	Ya con los comandos separados
	 	*	armo el vector de argumentos que 
	 	*	que luego le paso al exec para que 
	 	*	ejecute
	 	*	Cubo donde el elemento k,i,j es 
	 	*	el j-esimo comando del i-esimo elemento 
	 	*	del pipe del k-esimo comando condicional
	 	*/
	 	for(int k = 0, i = 0; partes[k][i] != NULL; k++){
	 		while(i < cantidad_comandos[k]){
		 		int j = 0;
		 		char *argumento = strtok(partes[k][i],delim1);
		 		while(argumento != NULL){
		 			cmds[k][i][j] = malloc(strlen(argumento)+1);
		 			strcpy(cmds[k][i][j],argumento);
		 			j++;
		 			argumento = strtok(NULL,delim1);
		 		}
		 		cmds[k][i][j] = malloc(sizeof(NULL));
		 		cmds[k][i][j] = NULL;
		 		i++;
	 		}
	 		i=0;
	 	}
		if(child_pid = fork()){
			//proceso padre
			waitpid(child_pid,&status, 0);
			no_termino_bien = WIFEXITED(status)?WEXITSTATUS(status):0;	
		}
		else {
			execv(cmds[0][0][0],&cmds[0][0][0]);
		}
		fflush(stdin);
	}	

	return 0;
}

int print_prompt(){
	printf("Milonga$ ");
}


