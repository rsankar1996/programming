#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse (char * str, char * rev, int len)
{
	if (NULL == rev)
	{
		return -1;
	}
	
	while (0 != len)
	{
		*(rev + len - 1) = *str;
		str++;
		len --;
	}
	
	return 0;
}

int main()
{
	char * str = "rakesh";
	char * rev = NULL;
	int len = 0;
	
	len = strlen(str);
	
	rev = (char *) malloc (len);
	
	if (0 != reverse (str, rev, len))
	{
		printf("Error in reversing string\r\n");
	}
	
	printf("rev: %s\r\n", rev);

	return 0;
}
