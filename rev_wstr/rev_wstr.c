#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int i = 0;
		int j = 0;
		while(av[1][i])
			i++;
		i--;
		while(i >= 0)
		{
			while(av[1][i] && (av[1][i] == '\t' || av[1][i] == ' '))
			{
				ft_putchar(av[1][i]);
				i--;
			}
			while(av[1][i] && av[1][i] != '\t' && av[1][i] != ' ')
				i--;
			j = i;
			i++;
			while(av[1][i] && av[1][i] != '\t' && av[1][i] != ' ')
			{
				ft_putchar(av[1][i]);
				i++;
			}
			i = j;
		}
	}
	ft_putchar('\n');
}