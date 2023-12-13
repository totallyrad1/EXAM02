#include <stdio.h>
#include <string.h>

int ftcheck(char c, const char *set)
{
	int i = 0;
	while(set[i])
	{
		if(c == set[i])
			return 1;
		i++;
	}
	return 0;
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	while(s[i] && ftcheck(s[i], reject) == 0)
	{
		i++;
	}
	return i;
}
