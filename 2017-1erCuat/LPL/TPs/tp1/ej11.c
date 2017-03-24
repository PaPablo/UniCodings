#include <stdio.h>

#define MAX(a,b,c) (( ((a) > (b) && (b) > (c)) ? (a) :  (((b)>(c) ? (b) : (c))  )))
int main(int argc, char const *argv[])
{
	int x = 8,y = 5,z = 3;

	printf("x = %d, y = %d, z = %d, maximo entre los tres :) %d\n", x,y,z, MAX(x,y,z));
	return 0;
}