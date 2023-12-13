#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *firstword = malloc(100); 
	if(!firstword)
		return 0;
	char *string = malloc (1000);
	if(!string)
	{
		free(firstword);
		return (0);
	}
	int i = 0;
	int j = 0;
	if(ac > 1)
	{
		while((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i])
			i++;
		while((av[1][i] != ' ' && av[1][i] != '\t') && av[1][i])
		{
			firstword[j] = av[1][i];
			i++;
			j++;
		}
		j = 0;
		while((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i])
			i++;
		while(av[1][i])
		{
			string[j] = av[1][i];
			i++;
			j++;
		}
		j = 0;
		while(string[j])
		{
			if( string[j - 1] && string[j] == ' ' && string[j + 1] != ' ' && string[j + 1])
				write(1, " ", 1);
			else if (string[j] != ' ')
				write(1, &string[j], 1);
			j++;
			if(string[j] == '\0')
				write(1, " ", 1);
		}
		j = 0;
		while(firstword[j])
		{
			write(1, &firstword[j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	free(firstword);
	free(string);
}