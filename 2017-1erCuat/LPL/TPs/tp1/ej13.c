#include <stdio.h>

#define SWAP(a,b) { typeof(a) SWAP = (a); (a) = (b); (b) = SWAP; }

int main(int argc, char const *argv[])
{
	float a = 1.0,b = 2.0;
	
	printf("a = %f | b = %f\n",a,b);

	printf("Swap\n");
	SWAP(a,b);

	printf("a = %f | b = %f\n",a,b);

	return 0;
}
