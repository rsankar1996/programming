#include <stdio.h>
#include <string.h>

int is_palindrome (char * str, int len)
{
	int tlen = len / 2;
	int i = 0;

	for (i = 0; i < tlen; i++)
	{
		printf("DBG: %c - %c\r\n", *(str + i), *(str + (len - i - 1)));

		if (*(str + i) != *(str + (len - i - 1)))
		{
			return -1;
		}
	}

	return 0;
}

int main ()
{
	char * str = "malaalam";
	int len = strlen (str);
	
	if (0 == is_palindrome(str, len))
	{
		printf("string is panindrome\r\n");
	}
	else
	{
		printf("string is not palindrome\r\n");
	}
	
	return 0;
}
