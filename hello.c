#include <stdio.h>
#include <stdlib.h>
int main()
{
	typedef struct hello
	{
		int member;
		int* p_member;
		char name;
	} hello;

	hello* hello_ = (hello*)malloc(sizeof(hello));

	int num = 5;

	//hello_->member = num;
	//hello_->p_member = &num;
	//hello_->name = 'a';

	printf("%p\n", hello_);
	//printf("%d\n", hello_->member);
	//printf("%d\n", *(hello_)->p_member);
	//printf("%c", hello_->name);

	int a[10];
	printf("%p\n", a);
}
