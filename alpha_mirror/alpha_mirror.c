#include <unistd.h>

int main(int ac , char **av)
{
	int i = 0;
	int j = 0;
	char *uc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ucm = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	char *lc = "abcdefghijklmnopqrstuvwxyz";
	char *lcm = "zyxwvutsrqponmlkjihgfedcba";
	if(ac == 2)
	{
		while(av[1][i])
		{
			j = 0;
			if(av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				while(lc[j] != av[1][i])
				{
					j++;
				}
				write(1, &lcm[j], 1);
			}
			else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				while(uc[j] != av[1][i])
				{
					j++;
				}
				write(1, &ucm[j], 1);
			}
			else {
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}