#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	if(ac == 4)
	{
		int n1 = atoi(av[1]);
		int n2 = atoi(av[3]);
		if(av[2][0] == '-')
			printf("%d", n1 - n2);
		if(av[2][0] == '+')
			printf("%d", n1 + n2);
		if(av[2][0] == '*')
			printf("%d", n1 * n2);
		if(av[2][0] == '/')
			printf("%d", n1 / n2);
		if(av[2][0] == '%')
			printf("%d", n1 % n2);
	}
	printf("\n");
}