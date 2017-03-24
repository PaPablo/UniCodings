#include <stdio.h>

#define PRODUCTO(a,b) (a)*(b)
int main(int argc, char const *argv[])
{
	/* code */
	int a = 2;
	a = PRODUCTO(a+2,3);

	printf("%d\n",a);
	return 0;
}