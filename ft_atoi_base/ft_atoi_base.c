char ft_tolower(char c)
{
	if(c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}

int	ft_atoi_base(const char *str, int str_base)
{
	char *base = "0123456789abcdef";
	int res = 0;
	int sign = 1;
	int i = 0;
	int j = 0;
	if(str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while(str[i] && j < str_base)
	{
		j = 0;
		while(base[j] && j < str_base && base[j] != ft_tolower(str[i]))
			j++;
		if (j < str_base)
			res = res * str_base + j;
		i++;
	}
	return res * sign;
}