#include <stdio.h>

int main()
{
	int *a;
	int num = 3;

	printf("%p\n", a);
	printf("%d\n", *a);

	a = &num;

	printf("%p\n", a);
	printf("%d\n", *a);
}
