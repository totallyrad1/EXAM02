#include <ctype.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_upper(char c)
{
	if(c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int ft_lower(char c)
{
	if(c >= 'a' && c <= 'z')
		return 1;
	return 0;
}

int ft_ischar(char c)
{
	if(c >= 'a' && c <= 'z')
		return 1;
	if(c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int main(int ac , char **av)
{
	if(ac != 1)
	{
		int i = 1;
		int j = 0;
		int cap = 1;
		while(i < ac)
		{
			j = 0;
			cap = 1;
			while(av[i][j] && cap == 1)
			{	
				if(ft_upper(av[i][j]) == 1)
					av[i][j] += 32;
				j++; 
			}
			j = 0;
			while(av[i][j])
			{
				if(ft_lower(av[i][j]) == 1 && !ft_ischar(av[i][j - 1]))
					ft_putchar(av[i][j] - 32);
				else
					ft_putchar(av[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putchar('\n');
}