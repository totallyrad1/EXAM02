#include <unistd.h>
#include <stdio.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_ischar(char c)
{
	if(c >= 'a' && c <= 'z')
		return 1;
	if(c >= 'A' && c<= 'Z')
		return 1;
	return 0;
}

int getcharindex(char c)
{
	if(c >= 'a' && c <= 'z')
		return c - 'a' + 1;
	if(c >= 'A' && c<= 'Z')
		return c - 'A' + 1;
	return 0;
}

int main(int ac ,char **av)
{
	if(ac == 2)
	{
		int i = 0;
		while(av[1][i])
		{
			if(ft_ischar(av[1][i]))
			{
				int index = getcharindex(av[1][i]);
				while(index > 0)
				{
					ft_putchar(av[1][i]);
					index--;
				}
			}
			else {
				ft_putchar(av[1][i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
}