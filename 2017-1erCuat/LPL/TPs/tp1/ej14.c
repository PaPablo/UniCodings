#include <stdio.h>


int factorial(int n);

int main(int argc, char const *argv[])
{
	int entrada; 

	scanf("%d", &entrada);

	printf("%d\n", factorial(entrada) );
	return 0;
}
int factorial(int n){

	if(n <= 1){
		return 1;
	}
	else {
		return n * factorial(n-1);
	}
}