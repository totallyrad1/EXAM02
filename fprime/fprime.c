#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int j = 2;
		int i = atoi(av[1]);
		while(j <= i)
		{
			while (ft_is_prime(j)) 
			{
				if (i % j == 0)
					printf("%d",j);
				else
				 	break ;
				if(j < i)
					printf("*");
				i = i /j;
			}
			j++;
		}
	}
	printf("\n");
}
