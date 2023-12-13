#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int *arr;
	int sizearr = end - start;
	if (sizearr >= 0)
	{
		arr = (int *)malloc((sizearr + 1) * sizeof(int)); 
		if(!arr)
			return NULL;
		while(sizearr >= 0)
		{
			arr[sizearr--] = end--;
		}
	}
	else {
		sizearr *= -1;
		arr = (int *)malloc((sizearr + 1) * sizeof(int)); 
		if(!arr)
			return NULL;
		while(sizearr >= 0)
		{
			arr[sizearr--] = end++;
		}
	}
	return &arr[0];
}
