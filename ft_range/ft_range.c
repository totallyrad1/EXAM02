#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int size = end - start;
	int *res;
	if(size >= 0)
	{
		res = malloc((size  + 1)	 * sizeof(int));
		if(!res)
			return res;
		while(size >= 0)
		{
			res[size] = end;
			end--;
			size--;
		}
	}else{
		size *= -1;
		res = malloc((size  + 1) * sizeof(int));
		if(!res)
			return res;
		while(size >= 0)
		{
			res[size] = end;
			size--;
			end++;
		}
	}
	return &res[0];
}
