#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return res;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void printhexa(long nb)
{
	if(nb > 16)
	{
		printhexa(nb / 16);
		printhexa(nb % 16);
	}
	if(nb < 16)
		ft_putchar("0123456789abcdef"[nb]);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		long nb = ft_atoi(av[1]);
		printhexa(nb);
	}
	write(1, "\n", 1);
}