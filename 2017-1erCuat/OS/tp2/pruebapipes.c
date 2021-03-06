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
int nueva_linea(char *linea,int tope);
int print_prompt();

typedef char *pipeds[MAX_ARGUMENTOS];
typedef pipeds comando[MAX_PIPES]; 

int main(int argc, char const *argv[]){

	char linea[MAX_LINEA];
	pid_t child_pid;
	int status;	
	//pido input desde la entrada estandar
  	scanf("%[^\n]",linea);
	getchar();

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
	 	partes[k][i] = NULL;
	 	cantidad_comandos[k] = i;
 	}

 	/*	
 	*	Ya con los comandos separados
 	*	armo el vector de argumentos que 
 	*	que luego le paso al exec para que 
 	*	ejecute
 	*	Cubo donde el elemento i,j,k es 
 	*	el j-esimo comando del i-esimo elemento 
 	*	del pipe del k-esimo comando condicional
 	*/
 	for(int k = 0, i = 0; partes[k][i] != NULL; k++){
 		while(i < cantidad_comandos[k]){
	 		int j = 0;
	 		char *argumento = strtok(partes[k][i],delim1);
	 		while(argumento != NULL){
	 			cmds[i][j][k] = malloc(strlen(argumento)+1);
	 			strcpy(cmds[i][j][k],argumento);
	 			j++;
	 			argumento = strtok(NULL,delim1);
	 		}
	 		cmds[i][j][k] = NULL;
	 		i++;
 		}
 		i=0;
 	}
 	/*int p= 0,q = 0,r;
 	printf("%d\n",cant_condicionados);
 	for(r = 0; r < cant_condicionados; r++){
 		while(p < cantidad_comandos[r]){
 			for(q = 0; cmds[p][q][r] != NULL;q++){
 				printf("%s ", cmds[p][q][r]);
 			}
 			printf("\n");
 			p++;
 		}
 		p=0;
 		printf("\n");
 	}*/

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


