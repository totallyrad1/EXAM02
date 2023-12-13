#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int newlineexists(char *str)
{
	if(!str)
		return 0;
	int i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}

char *ft_strdup(char *str)
{
	char *res;

	if(!str)
		return NULL;
	int len = ft_strlen(str);
	int i = 0;
	res = malloc(len + 1);
	while(str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return res;
}

char *ft_strjoin(char *s1, char *s2)
{
	char *res;
	int i = 0;
	int j = 0;

	if(!s1 && !s2)
		return NULL;
	if(!s1)
		return (ft_strdup(s2));
	if(!s2)
	{
		res = ft_strdup(s1);
		free(s1);
		return (res);
	}
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while(s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (free(s1), res);
}

char *ft_substr(char *str, int start, int len)
{
	int i = 0;
	char *res;

	if(!str)
		return NULL;
	if(start > ft_strlen(str))
		return NULL;
	if(len == 0)
		return NULL;
	res = malloc(len + 1);
	while(i < len && str[start + i])
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return res;
}

char *ft_read(char *buffer, int fd, char *hold)
{
	int bytes_read = 1;
	while(bytes_read > 0 && newlineexists(hold) == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read < 0)
			return (free(buffer), free(hold), NULL);
		buffer[bytes_read] = '\0';
		hold = ft_strjoin(hold, buffer);
	}
	free(buffer);
	if(hold)
	{
		if(hold[0] == '\0')
			return (free(hold), NULL);
	}
	return hold;
}

char *ft_get_line(char *hold)
{
	if(!hold)
		return NULL;

	int i = 0;
	char *res;
	while(hold[i] && hold[i] != '\n')
		i++;
	if(hold[i] == '\n')
		i++;
	res = ft_substr(hold, 0, i);
	return res;
}

char *ft_remreturnedline(char *hold)
{
	if(!hold)
		return NULL;

	int i = 0;
	char *res;
	while(hold[i] && hold[i] != '\n')
		i++;
	if(hold[i] == '\n')
		i++;
	res = ft_strdup(&hold[i]);
	free(hold);
	return res;
}

char *get_next_line(int fd)
{
	static char *hold;
	char *buffer;
	char *line;

	if(fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	hold = ft_read(buffer, fd , hold);
	line = ft_get_line(hold);
	hold = ft_remreturnedline(hold);
	return line;
}
