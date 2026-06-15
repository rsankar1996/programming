#include <stdio.h>

int set_bit_mask (int a, int b)
{
	int a_bm = (1U << a) - 1U;
	int b_bm = (1U << (b + 1)) - 1U;
	
	return (b_bm & ~a_bm);
}

int main ()
{
	int a = 3;
	int b = 5;
	
	printf("%x\r\n", set_bit_mask(a, b));

	return 0;
}
