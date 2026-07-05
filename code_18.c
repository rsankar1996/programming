#include <stdio.h>

int get_sum (int num)
{
	if (num != 0)
	{
		return ((num % 10) + get_sum (num / 10));
	}
	else
	{
		return 0;
	}
}

int main()
{
	int num = 12345;
	int sum = 0;
	
	sum = get_sum (num);
	
	printf("sum: %d\r\n", sum);
	
	return 0;
}
