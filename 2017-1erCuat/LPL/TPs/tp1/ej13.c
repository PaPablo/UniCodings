#include <stdio.h>

//#define SWAP(a,b) { typeof(a) SWAP = (a); (a) = (b); (b) = SWAP; }
#define SWAP(a,b) {int aux;aux=a;a=b;b=aux;}
int main(int argc, char const *argv[])
{
	int a = 1.0,b = 2.0;
	
	printf("a = %d | b = %d\n",a,b);

	printf("SWAP\n");
	SWAP(a,b);

	printf("a = %d | b = %d\n",a,b);

	return 0;
}
