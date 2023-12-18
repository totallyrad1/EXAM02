#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if(ac == 4)
	{
		int i = 0;
		if(av[2][1] != '\0' || av[3][1] != '\0')
		{
			ft_putchar('\n');
			return 0;
		}
		while(av[1][i])
		{
			if(av[1][i] == av[2][0])
				ft_putchar(av[3][0]);
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}