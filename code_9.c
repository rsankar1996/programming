#include <stdio.h>

int main()
{
	int a = 5;
	
	if ((a & (a - 1)) == 0)
	{
		printf("number is power of two\r\n");
	}
	else
	{
		printf("number is not power of two\r\n");
	}
	
	return 0;
}
