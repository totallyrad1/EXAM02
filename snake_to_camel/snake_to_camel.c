#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_islower(char c)
{
	if(c >= 'a' && c <= 'z')
		return 1;
	return 0;
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int i = 0;
		while(av[1][i])
		{
			if(ft_islower(av[1][i]) && av[1][i - 1] == '_')
			{
				ft_putchar(av[1][i] - 32);
			}
			else if(av[1][i] != '_')
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}