#include <stdio.h>

int reverse_bit (int a)
{
	int rev = 0;
	int i = 0;

	for (i = 0; i <= 7; i++)
	{
		if (((a & (1 << i)) >> i) != 0)
		{
			rev |= (1 << (7 - i));
		}
	}
	
	return rev;
}
int main()
{
	int a = 0xAB;
	int b = reverse_bit (a);
	
	printf("bit original: %.2x\r\n", a);
	printf("bit reverse: %.2x\r\n", b);
	
	return 0;
}
