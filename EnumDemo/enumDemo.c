#include <stdio.h>


void main()
{
	enum
	{
		b,
		c,
		a = 0,
	};
	printf("%d",a); //0
	printf("%d", b);//0
	printf("%d", c);//1
}