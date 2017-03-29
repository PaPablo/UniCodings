#include <stdio.h>


void swapEntero(int *a, int *b);
void swapFlotante(float *a, float *b);
int main(int argc, char const *argv[])
{
	int a = 1,b = 2;
	float p,q;

	printf("a: %d\nb: %d\n",a,b);
	swapEntero(&a,&b);
	printf("a: %d\nb: %d\n",a,b);	
	return 0;
}

void swapEntero(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}


void swapFlotante(float *a, float *b){
	float aux;
	aux = *a;
	*a = *b;
	*b = aux;
}