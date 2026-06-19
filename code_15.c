#include <stdio.h>
#include <string.h>

const char * custom_str_str (const char * st1, const char * st2)
{
	int len1 = 0;
	int len2 = 0;
	
	if ((st1 == NULL) || (st2 == NULL))
	{
		return NULL;
	}
	
	len1 = strlen (st1);
	len2 = strlen (st2);

	if (len1 < len2)
	{
		return NULL;
	}
	
	if (*st2 == '\0')
	{
		return st1;
	}
	
	while (strlen(st1) >= len2)
	{
		if (memcmp (st1, st2, len2) == 0)
		{
			return st1;
		}

		st1++;
	}
	
	return NULL;
}

int main()
{
	char * str1 = "abcdabcd";
	char * str2 = "dab";
	
	const char * check = custom_str_str(str1, str2);
	
	printf("str1: %s\r\n", str1);
	printf("str2: %s\r\n", str2);
	
	if (NULL != check)
	{
		printf("check: %s\r\n", check);
	}
	
	return 0;
}
