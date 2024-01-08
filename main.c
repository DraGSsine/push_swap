#include <stdio.h>

void inc(int *i)
{
	(*i)++;
}

int main()
{
	int i = 0;
	inc(&i);
	printf("%i",i);
}
