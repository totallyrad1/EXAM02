#include <stdlib.h>
#include <stdio.h>
#include <sys/_types/_null.h>

int checkifcvalid(char c)
{
	if(c == 32)
		return 1;
	if(c >= 9 && c <= 13)
		return 1;
	if (c == '\t')
		return 1;
	if (c == '\n')
		return 1;
	return 0;
}

int wordcount(char *str)
{
	int wc = 0;
	int i = 0;
	while(str[i])
	{
		while(str[i] && checkifcvalid(str[i]) == 1)
			i++;
		if(str[i])
			wc++;
		while(str[i] && checkifcvalid(str[i]) == 0)
			i++;
	}
	return wc;
}

char *splitwords(char *str, int *i)
{
	int j = 0;
	int tpos = 0;
	while(str[*i] && checkifcvalid(str[*i]) == 1)
			(*i)++;
	tpos = *i;
	while(str[*i] && checkifcvalid(str[*i]) == 0)
			(*i)++;
	char *res = malloc(*i - tpos + 1);
	if(!res)
		return NULL;
	while(tpos + j < *i)
	{
		res[j] = str[tpos + j];
		j++;
	}
	res[j] = '\0';
	return res;
}

char **ft_free(char **str)
{
	int i = 0;
	if(str[i])
	{
		while(str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	return NULL;
}

char    **ft_split(char *str)
{
	if(!str)
		return NULL;
	int i = 0;
	int j = 0;
	int wc = wordcount(str);
	char **res = (char **)malloc((wc + 1) * sizeof(char *));
	if(!res)
		return NULL;
	while(j < wc)
	{
		res[j] = splitwords(str, &i);
		if(!res[j])
			return ft_free(res);
		j++;
	}
	res[wc] = NULL;
	return res;
}
