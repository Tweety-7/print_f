#include <libftprintf.h>

static int len_char(unsigned long long one, int base)
{
	int count;

	count = 0;
	while (one > 0)
	{
		count++;
		one = one / base;
	}
	return (count);
}

char *ft_int_base(unsigned long long one, char base)
{
	char *c_base;
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";
	char digits8[9] = "01234567";
	int len;

	if (one == 0)
		return ("0");
	len =  len_char(one, base == 'o' ? 8 : 16);
	c_base = (char*)malloc(sizeof(char)*(len+1));
	c_base[len--] = '\0';
	if (base == 'x' || base == 'X')
		while (one > 0)
		{
			c_base[len--] = (base == 'x') ? digits[one%16] : digits2[one%16];
			one = one / 16;
		}
	else
		while (one > 0)
		{
			c_base[len--] = digits8[one%8];
			one = one / 8;
		}
	return (c_base);
}