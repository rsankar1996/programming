#include <stdio.h>

int bin_dec(int bin)
{
	int dec = 0;
	int pow = 1;
	
	while (0 != bin)
	{
		dec += (bin % 10) * pow;
		pow *= 2;
		bin /= 10;
	}
	
	return dec;
}

int main()
{
	int bin = 1101;
	int dec = 0;
	
	dec = bin_dec(bin);
	
	printf("Decimal output for %d is %d\r\n", bin, dec);

	return 0;
}
