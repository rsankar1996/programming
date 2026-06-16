#include <stdio.h>

#define BITMAP	(0x55555555)

int main()
{
	int a = 9;

	if ((a & BITMAP) != 0)
	{
		printf("number is not power of four\r\n");
	}
	else
	{
		printf("number is power of four\r\n");
	}
		
	return 0;
}
