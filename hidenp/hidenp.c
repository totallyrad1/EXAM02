#include <sys/_types/_null.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int existsafterpost(int pos, char c, char *str)
{
	int i = 0;
	while(str[i + pos])
	{
		if(str[i + pos] == c)
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
		int j = 0;
		while(av[2][i])
		{
			if(existsafterpost(i, av[1][j], av[2]) == 1)
				j++;
			i++;
		}
		if(av[1][j] == '\0')
			ft_putchar('1');
		else
		 	ft_putchar('0');
	}
	ft_putchar('\n');
}