/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:56:27 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/09 11:56:20 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	len_char(unsigned long long one, int base)
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

static char	*base_char(int base)
{
	char	*digits;

	digits = ft_strnew(16);
	if (base == 5)
		ft_memcpy(digits, "01234567", 8);
	else if (base == 8)
		ft_memcpy(digits, "0123456789ABCDEF", 16);
	else
		ft_memcpy(digits, "0123456789abcdef", 16);
	return (digits);
}

char		*ft_int_base(unsigned long long one, int base)
{
	char	*c_base;
	char	*digits;
	int		len;

	if (one == 0)
		return ("0");
	digits = base_char(base);
	len = len_char(one, base == 5 ? 8 : 16);
	c_base = (char*)malloc(sizeof(char) * (len + 1));
	c_base[len--] = '\0';
	if (base == 7 || base == 8 || base == 9)
		while (one > 0)
		{
			c_base[len--] = digits[one % 16];
			one = one / 16;
		}
	else
		while (one > 0)
		{
			c_base[len--] = digits[one % 8];
			one = one / 8;
		}
	free(digits);
	return (c_base);
}
