#include <stdio.h>

int get_unique (int * arr, int len)
{
	int result = 0;
	int count = 0;
	int i = 0;
	int j = 0;
	
	for (i = 0; i < 32; i++)
	{
		for (j = 0; j < len; j++)
		{
			if ((arr[j] >> i) & 1)
			{
				count++;
			}
		}
		
		if (0 != (count % 3))
		{
			result |= (1 << i);
		}
		
		count = 0;
	}
	
	return result;
}

int main ()
{
	int arr[] = {1, 2, 3, 2, 1, 3, 3, 0, 1, 2};
	int len = sizeof (arr) / sizeof (arr[0]);
	int element = 0;
	
	element = get_unique (arr, len);
	
	printf ("Unique element in array is %d\r\n", element);
	
	return 0;
}
