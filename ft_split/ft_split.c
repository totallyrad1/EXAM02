#include <stdlib.h>

int checkseparator(char c)
{
	if(c == 32)
		return 1;
	if(c >= 9 && c <= 13)
		return 1;
	if(c == '\t')
		return 1;
	if(c == '\n')
		return 1;
	return 0;
}

int wordcount(char *str)
{
	 int i = 0;
	 int wc = 0;
	while(str[i])
	{
		while(str[i] && checkseparator(str[i]) == 1)
			i++;
		if(str[i])
			wc++;
		while(str[i] && checkseparator(str[i]) == 0)
			i++;
	}
	return wc;
}

char *getword(char *str, int *i)
{
	int tpos = 0;
	int j = 0;
	char *res;

	while(str[*i] && checkseparator(str[*i]) == 1)
		(*i)++;
	tpos = *i;
	while(str[*i] && checkseparator(str[*i]) == 0)
		(*i)++;
	res = malloc(*i - tpos + 1);
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
	if(str)
	{
		while(str[i])
			free(str[i++]);
		free(str);
	}
	return NULL;
}

char    **ft_split(char *str)
{
	char **res;
	int i = 0;
	int j = 0;
	int wc= 0;

	if(!str)
		return NULL;
	wc = wordcount(str);
	res = (char **)malloc((wc + 1) * sizeof(char *));
	if(!res)
		return NULL;
	while(j < wc)
	{
		res[j] = getword(str, &i);
		if(!res[j])
			return ft_free(res);
		j++;
	}
	res[wc] = NULL;
	return res;
}