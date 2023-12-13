#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char *res;
	int i = 0;
	int j = 0;

	if(!src)
		return NULL;
	while(src[i])
		i++;
	res = malloc(i + 1);
	if(!res)
		return NULL;
	while(src[j])
	{
		res[j] = src[j];
		j++;
	}
	return res;
}