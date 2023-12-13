#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int i = 0;
	if(ac == 2)
	{
		while(av[1][i])
		{
			if((av[1][i] >= 'A' && av[1][i] <= 'Z') && av[1][i] && av[1][i - 1])
			{
				ft_putchar('_');
				ft_putchar(av[1][i] + 32);
			}
			else 
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}