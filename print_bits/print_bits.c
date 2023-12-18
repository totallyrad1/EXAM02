#include <unistd.h>
void	print_bits(unsigned char octet)
{
	int divide;
	int oct;

	oct = octet;
	divide = 128;
	while(divide != 0)
	{
		if(divide <= oct)
		{
			write(1, "1", 1);
			oct = oct % divide;
		}
		else 
			write(1, "0", 1);
		divide /= 2;
	}
}