#include <stdio.h>

int reverse (int num)
{
	int rev = 0;
	
	while (0 != num)
	{
		rev = (rev * 10) + (num % 10);
		num /= 10;
	}
	
	return rev;
}
int main()
{
	int num = 1234;
	int rev = reverse (num);
	
	printf ("Reverse of the number %d is %d\r\n", num, rev);

	return 0;
}
