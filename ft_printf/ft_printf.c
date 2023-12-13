#include <limits.h>
#include <sys/_types/_null.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int i = 0;
	int r = 0;
	if(!s)
	{
		r += ft_putstr("(null)");
	}
	else
	{
		while(s[i])
		{
			r += ft_putchar(s[i++]);
		}
	}
	return r;
}

int ft_puthexa(unsigned int nb)
{
	int r = 0;
	char *base = "0123456789abcdef";
	if(nb >= 16)
	{
		r += ft_puthexa(nb / 16);
		r += ft_puthexa(nb % 16);
	}
	if(nb >= 0 && nb < 16)
	{
		r += ft_putchar(base[nb]);
	}
	return r;
}

int ft_putnbr(long long nb)
{
	int r = 0;
	if(nb < 0)
	{
		r += ft_putchar('-');
		nb *= -1;
	}
	if(nb > 9)
	{
		r += ft_putnbr(nb / 10);
		r += ft_putnbr(nb % 10);
	}
	if(nb >= 0 && nb <= 9)
	{
		r += ft_putchar(nb + '0');
	}
	return r;
}

int handlecategory(va_list args, const char *s, int i)
{
	if(s[i])
	{
		if(s[i] == 's')
			return (ft_putstr(va_arg(args, char *)));
		if(s[i] == 'd')
			return (ft_putnbr(va_arg(args, int)));
		if(s[i] == 'x')
			return (ft_puthexa(va_arg(args, unsigned int)));
		else 
			return (ft_putchar(s[i]));
	}
	return 0;
}

int ft_printf(const char *s, ... )
{
	va_list args;
	va_start(args, s);
	int i = 0;
	int r = 0;
	if(write(1, "", 0) < 0)
		return -1;
	while(s[i])
	{
		if(s[i] == '%')
		{
			r += handlecategory(args, s, i + 1);
			i++;
		}
		else {
			r += ft_putchar(s[i]);
		}
		if(s[i])
			i++;
	}
	va_end(args);
	return r;
}

// int main()
// {
// 	int i = ft_printf("\n%x", INT_MAX);
// 	int j = printf("\n%x", INT_MAX);
// 	printf("%d, %d", i , j);
// }