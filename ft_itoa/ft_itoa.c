#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int countnblen(int nb, int *sign)
{
	int i = 0;
	// printf("%d", nb);
	if(nb < 0)
	{
		*sign = 1;
		nb *= -1;
		i++;
	}
	if(nb == 0)
		return 1;
	while(nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return i;
}

char	*ft_itoa(int nbr)
{
	int sign = 0;
	int i = 0;
	// printf("%d", nbr);
	int len = countnblen(nbr, &sign);
	// printf("sing %d len %d", sign , len);
	char *res = malloc(len + 1);
	if(!res)
		return NULL;
	if(sign == 1)
	{
		nbr *= -1;
	}
	res[len] = '\0';
	while (len > sign)
	{
		res[len - 1] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	if(sign == 1)
	{
		res[0] = '-';
	}
	return res;
}
