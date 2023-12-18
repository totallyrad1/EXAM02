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
		ft_putnbr(nb % 10);
	}
	if(nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
}

int isprime(int nb)
{
	int i = 2;
	while(i < nb)
	{
		if(nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int ft_atoi(char *str)
{
	int sign = 1;
	int res = 0;
	int i = 0;
	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	if(str[i] >= '0' && str[i] <= '9')
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
		int nb = ft_atoi(av[1]);
		int sum = 0;
		int i = 2;
		while(i <= nb)
		{
			if(isprime(i))
				sum += i;
			i++;
		}
		ft_putnbr(sum);
		ft_putchar('\n');
	}
	else {
		ft_putchar('0');
		ft_putchar('\n');
	}
}