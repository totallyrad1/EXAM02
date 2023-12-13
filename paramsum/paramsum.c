#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	long n = nb;
	if(n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if(n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if(n < 9)
		ft_putchar(n + 48);
}

int main(int ac , char **av)
{
	if(ac != 1)
	{
		ft_putnbr(ac - 1);
	}
	else 
	{
		ft_putchar('0');
	}
	ft_putchar('\n');
}