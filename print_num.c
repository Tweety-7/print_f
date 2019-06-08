/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 21:26:18 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/08 21:26:19 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static char	*ft_print_num2(int len_str, t_print *pr)
{
	char	*str2;
	int		len_max;

	if ((*pr).width && len_str <= (*pr).width)
		len_max = (*pr).width;
	else if ((*pr).prec_p && (*pr).prec > len_str)
		len_max = (*pr).width;
	else
		len_max = len_str;
	str2 = ft_strnew(len_max + 1);
	ft_memset(str2, ' ', len_max);
	return (str2);
}

static int	ft_str_format(t_print *pr, char *st_cat)
{
	int		len_z;

	len_z = 0;
	if ((*pr).space && !(*pr).leftzero && !(*pr).plus && !(*pr).pr_x)
		ft_memset(st_cat + len_z++, ' ', 1);
	if ((*pr).rr == 1)
	{
		if (((*pr).format == 7 || (*pr).format == 9
			|| (*pr).format == 8 || (*pr).format == 5))
		{
			ft_memset(st_cat + len_z++, '0', 1);
			if ((*pr).format == 7 || (*pr).format == 9)
				ft_memset(st_cat + len_z++, 'x', 1);
			else if ((*pr).format == 8)
				ft_memset(st_cat + len_z++, 'X', 1);
		}
	}
	return (len_z);
}

static int	ft_len_str_v(int len_str_v, t_print *pr)
{
	if ((*pr).format == 7 || (*pr).format == 9 
		|| (*pr).format == 8 || (*pr).format == 5)
	{
			len_str_v += 1;
		if ((*pr).format == 7 || (*pr).format == 9)
			len_str_v += 1;
		else if ((*pr).format == 8)
			len_str_v += 1;
	}
	return (len_str_v);
}

static int	ft_str_len_v(t_print *pr, int len, int len_str)
{
	int		len_str_v;
	int		pr_x;
	
	len_str_v = 0;
	if ((*pr).prec_p && (*pr).prec > (len_str))
		len_str_v = len_str + (*pr).prec - len;
	else 
		len_str_v = len_str;
	if (((*pr).width - len_str - len) > (*pr).prec && (*pr).zero && !(*pr).minus)
			len_str_v += ((*pr).width - len_str - len) - (*pr).prec;
	if ((*pr).space )
		len_str_v += 1;
	if ((*pr).leftzero || (*pr).plus)
		(*pr).space = 0;
	if ((*pr).rr == 1 || (*pr).format == 9)
		len_str_v = ft_len_str_v(len_str_v, pr);
	if ((*pr).leftzero == 1 || ((*pr).plus && !(*pr).leftzero))
		len_str_v += 1;
 	pr_x = (!(*pr).zero && ((*pr).F >= 7 && (*pr).F <= 9)) ? 1 : 0;
	return (len_str_v + 2 * pr_x);
}

typedef struct s_len
{
	int 	len_str;
	int 	len;
	int 	len_z;
	int 	len_0;
}			t_len;

static void num_set(t_print *pr, t_len *len_l, char *st_cat, char *str)
{
	if ((*pr).prec_p && (*pr).prec > ((*len_l).len_str))
	{
		ft_memset(st_cat + (*len_l).len_z, '0', (*pr).prec);
		ft_memcpy(st_cat + ((*pr).prec -  (*len_l).len_str + (*len_l).len_z),
		str, (*len_l).len_str);
	}
	else 
		ft_memcpy(st_cat + (*len_l).len_z, str, (*len_l).len_str);
}

static char	*ft_print_num3(t_print *pr, t_len *len_l, char *str)
{
	char 	*st_cat;

	(*len_l).len_z = 0;
	(*len_l).len_0 = 0;
	st_cat = ft_strnew(ft_str_len_v(pr,  (*len_l).len, (*len_l).len_str));
	st_cat[ft_str_len_v(pr, (*len_l).len, (*len_l).len_str)] = '\0';
	(*len_l).len_z = ft_str_format(pr, st_cat);
	if ((*pr).leftzero == 1)
		ft_memset(st_cat + (*len_l).len_z++, '-', 1);
	if ((*pr).plus && !(*pr).leftzero && !(*pr).pr_x)
		ft_memset(st_cat + (*len_l).len_z++, '+', 1);
	if (!(*pr).prec_p  && (*pr).width && ((*pr).width - (*len_l).len_str -
		(*len_l).len) >= (*pr).prec && (*pr).zero && !(*pr).minus)
	{
		(*len_l).len_0 = ((*pr).width - (*len_l).len_str - (*len_l).len) - (*pr).prec - (*pr).space;
		if ((*len_l).len_0 > 0)
			ft_memset(st_cat + (*len_l).len_z, '0', (*len_l).len_0);
		(*len_l).len_z = (*len_l).len_z + (*len_l).len_0;
	}
	num_set(pr, len_l, st_cat, str);
	return (st_cat);
}

const char	*ft_print_num(const char *format, char *str, t_print *pr)
{
	//int		len_str;
	char	*str2;
	char	*st_cat;
	t_len	*len_l;

	//len_str = 
	len_l = (t_len*)malloc(sizeof(t_len));
	len_l->len_str = ft_strlen(str);//len_str;
	
	str2 = ft_print_num2(len_l->len_str, pr);

	len_l->len = ((*pr).plus) + ((*pr).leftzero)*(!(*pr).plus) + 2 * ((*pr).rr);
	
	st_cat = ft_print_num3(pr, len_l, str);
	if ((len_l->len_str = ft_strlen(str2) - ft_strlen(st_cat)) > 0)
		if ((*pr).minus)
			ft_memcpy(str2, st_cat, ft_strlen(st_cat));
		else 
			ft_memcpy(str2 + len_l->len_str, st_cat, ft_strlen(st_cat));
	else
		{
			free(str2);
			str2 = ft_strdup(st_cat);
		}
	free(st_cat);
	free(len_l); 
	ft_putstr(str2);
	(*pr).len += ft_strlen(str2);
	if (str2)
		free(str2);
	return (format);
}
