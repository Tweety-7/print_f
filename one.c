#include "libftprintf.h"
#include <stdio.h>







static char *ft_itoa_double(double num, t_print *pr)
{
	long long num_i;
	char *str_0;
	char *str;
	int prec;



	(*pr).prec = ((*pr).prec == 0 ? 6 : (*pr).prec);
	prec = (*pr).prec;
	if (num == 0)
	{
		str_0 = ft_strnew((*pr).prec + 1);
		ft_memset(str_0, '0', (*pr).prec + 1);
		ft_memset(str_0, '.', 1);
		return (str_0);
	}
	else
	{
		while ((*pr).prec > 0)
		{
			num *= 10;
			(*pr).prec--;
		}
		num_i = num + 0.5;
		str_0 = ft_itoa_lu(num_i);
	}
	if (ft_size_int_lu(num_i) > prec)
	{
		ft_memset(str_0, '0', prec);
		str_0[prec] = '\0';
		(*pr).pr_4erez_0 = 1;
	}
	else
		(*pr).pr_4erez_0 = 0;
	str = ft_strjoin(".", str_0);
	free(str_0);
	return(str);
}

static char	*ft_strjoin_new(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		len1;

	if (!s1 || !s2)
		return (NULL);
	new = NULL;
	new = (char*)malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	len1 = i;
	i = 0;
	while (s2[i])
	{
		new[len1 + i] = s2[i];
		i++;
	}
	free(s1);
	free(s2);
	return (new);
}

const char		*ft_print_f(const char *format, va_list ap, t_print *pr)
{
	double		num;
	char		*str;
	char 		*str_2;
	long long			str_i;

	num = (double)va_arg(ap, double);
	if (num < 0)
		{
			(*pr).leftzero = 1;
			num = -num;
		}
	str_i = num;
	num = num - str_i;
	str_2 = ft_itoa_double(num, pr);
	if ((*pr).pr_4erez_0 == 1)
		str_i+=1;
	str = ft_itoa_lu(str_i);
	str = ft_strjoin_new(str, str_2);
	ft_print_num(format, str, pr);
	free(str);
	return (format);
}



const char *ft_check(const char *format,va_list ap, t_print *pr)
{
	if ((*pr).format == 1)
		return (ft_print_str(format, va_arg(ap, char *), pr));
	else if ((*pr).format == 2)
		return (ft_print_d(format, ap, pr));
	else if ((*pr).format == 3)
		return (ft_print_c(format, ap, pr));
	else if ((*pr).format == 9)	
		return (ft_print_x(format, ap, pr));
	else if ((*pr).format == 4)
		return (ft_print_d(format, ap, pr));
	else if ((*pr).format == 5)
		ft_print_o(format, ap, pr);
	else if ((*pr).format == 6 || (*pr).format == 11)
		return (ft_print_u(format, ap, pr));	
	else if ((*pr).format == 7)
		return (ft_print_x(format, ap, pr));
	else if ((*pr).format == 8)
		return (ft_print_x(format, ap, pr));
	else if ((*pr).format == 10)
		return (ft_print_f(format, ap, pr));
	else
		(*pr).net = 1;
	return (format);
}


const char *ft_format(const char *format, va_list ap, t_print *pr)
{
	if (ft_strncmp(format, "%", 1) == 0)
	{
		(*pr).len += 1;
		ft_putstr("%");
		format++;
		return (format);
	}
	format = ft_flag_check(format, pr);
	if ((*pr).minus == 1 && (*pr).space == 1 && (*pr).minus == 1)
		(*pr).space = 0;
	format = ft_width_check(format, pr, ap);
	format = ft_precision_check(format, pr, ap);
	format = ft_mod_check(format, pr);
	format = ft_format_check(format, pr);
	format = ft_check(format, ap, pr);
	if ((*pr).net == 1)
		if (ft_strncmp(format, "%", 1) == 0)
		{
			(*pr).space = 0;
			ft_print_str(format, "%", pr);
		}
	return (format);
}

t_print *ft_make_0(int len)
{
	t_print	*pr;

	pr = (t_print*)malloc(sizeof(t_print));
	(*pr).len = len;
	(*pr).minus = 0;
	(*pr).width = 0;
	(*pr).prec_p = 0;
	(*pr).prec = 0;
	(*pr).net = 0; 
	(*pr).rr = 0;
	(*pr).space = 0;
	(*pr).plus = 0;
	(*pr).zero = 0;
	(*pr).mod = -1;
	(*pr).leftzero = 0;
	(*pr).format = 0;
	(*pr).pr_x = 0;
	(*pr).pr_4erez_0 = 0;
	return (pr);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	t_print	*pr;
	int len;

	va_start(ap, format);
	len = 0;
	pr = ft_make_0(len);
	while (*format)
	{
		if (ft_strncmp(format, "%", 1) == 0)
		{
			if (len)
				{
					free(pr);
					pr = ft_make_0(len);
				}
			format++;
			format = ft_format(format, ap, pr);
		}
		else // если не процент печатаем символ
		{
			ft_putchar(*format);
			format++;
			(*pr).len++;
		}
		len = (*pr).len;

	}
	va_end(ap);
	//ft_memdel(pr);
	len = (*pr).len;
free(pr);	
return(len);
}
