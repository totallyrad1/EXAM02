#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if(nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if(nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb  % 10);
	}
	if(nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
}

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	int sign = 1;
	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return res * sign;
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int i = 1;
		int nb = ft_atoi(av[1]);
		while(i <= 9)
		{
			ft_putnbr(i);
			ft_putchar(' ');
			ft_putchar('x');
			ft_putchar(' ');
			ft_putnbr(nb);
			ft_putchar(' ');
			ft_putchar('=');
			ft_putchar(' ');
			ft_putnbr(i * nb);
			if(i < 9)
				ft_putchar('\n');
			i++;
		}
	}
	ft_putchar('\n');
}