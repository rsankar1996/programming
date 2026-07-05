#include <stdio.h>

int get_sum (int num)
{
	int sum = 0;

	if (num != 0)
	{
		sum = get_sum(num - 1);
	}
	
	return (num + sum);
}

int main()
{
	int num = 10;
	int sum = 0;
	
	sum = get_sum (num);
	
	printf("sum: %d\r\n", sum);
	
	return 0;
}
