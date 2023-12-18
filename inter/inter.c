#include <complex.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int check_doubles(char *str, char c, int pos)
{
	int i = 0;
	while(i < pos)
	{
		if(c == str[i])
			return 0;
		i++;
	}
	return 1;
}

int checkifexists(char c, char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int main(int ac, char **av)
{
	if(ac == 3)
	{
		int i = 0;
		while(av[1][i])
		{
			if(check_doubles(av[1], av[1][i], i) == 1 && checkifexists(av[1][i], av[2]) == 1)
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}