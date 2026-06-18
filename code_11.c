#include <stdio.h>

int check_lsb_idx(int num)
{
	int ls_set = num ^ (num - 1);
	int lsb = 0;
	
	while (0 != ls_set)
	{
		ls_set &= (ls_set - 1);
		lsb++;
	}
	
	return lsb;
}

int main()
{
	int num = 10;
	int lsb = check_lsb_idx(num);
	
	printf("least significant 1 in %d [%.8x] is at %d\r\n", num, num, lsb);
	
	return 0;
}
