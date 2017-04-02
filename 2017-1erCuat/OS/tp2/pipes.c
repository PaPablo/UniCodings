#include <unistd.h>
#include <syscall.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]){

	int tuberia[2];
	pipe(&tuberia[0]);

	char *ls[] = {"/bin/ls", "/home/pablo", NULL};
	char *grep[] = {"/bin/grep", "w", NULL};

	if(fork()){
		close(tuberia[0]);
		close(1); //cierro salida estandar del padre

		dup(tuberia[1]); //conecto salida del proceso con entrada de la tuberia

		close(tuberia[1]); //cierro porque puedo
		
		execv(ls[0],&ls[0]);
	}
	else {
		close(tuberia[1]);
		close(0);//cierro mi entrada estandar
		dup(tuberia[0]); // conecto la salida de la tuberia con mi entrada estandar

		close(tuberia[0]); //cierro porque puedo

		execv(grep[0], &grep[0]);	
	}

	return 0;
}


