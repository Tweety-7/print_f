#include <stdlib.h>

static int			ft_size_int(long long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		if (n < -9223372036854775807)
		{
			i++;
			n = -922337203685477580;
		}
		n = -n;
	}
	while (n / 10 > 0)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char				*ft_itoa_ll(long long n)
{
	int				len;
	char			*new;

	len = ft_size_int(n);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len--] = '\0';
	// if (n < 0)
	// {
	// 	new[0] = '-';
	// 	if (n < -9223372036854775807)
	// 	{
	// 		new[len--] = '0' + 8;
	// 		n = -922337203685477580;
	// 	}
	// 	n = -n;
	// }
	while (n / 10 > 0)
	{
		new[len--] = n % 10 + '0';
		n = n / 10;
	}
	new[len] = n + '0';
	return (new);
}

int			ft_size_int_lu(unsigned long long n)
{
	int		i;

	i = 0;
	while (n / 10 > 0)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char				*ft_itoa_lu(unsigned long long n)
{
	int				len;
	char			*new;

	len = ft_size_int_lu(n);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len--] = '\0';
	while (n / 10 > 0)
	{
		new[len--] = n % 10 + '0';
		n = n / 10;
	}
	new[len] = n + '0';
	return (new);
}


