#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isprime(long nb)
{
	int i = 2;
	if(nb <= 1)
		return 0;
	while(i < nb)
	{
		if(nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int nb = atoi(av[1]);
		int i = 0;
		while(i <= nb)
		{
			while(isprime(i))
			{
				if(nb % i == 0)
					printf("%d", i);
				else
				 	break ;
				if(i < nb)
					printf("*");
				nb = nb / i;
			}
			i++;
		}
	}
	printf("\n");
}