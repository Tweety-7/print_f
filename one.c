#include "libftprintf.h"
#include <stdio.h>

const char	*ft_check(const char *format,va_list ap, t_print *pr)
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


const char	*ft_format(const char *format, va_list ap, t_print *pr)
{
	format++;
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

t_print		*ft_make_0(int len)
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

const char	*ft_format_0(const char *format, va_list ap, t_print *pr, int len)
{
	if (len)
	{
		free(pr);
		pr = ft_make_0(len);
	}
	format = ft_format(format, ap, pr);
	return (format);
}

int			ft_printf(const char *format, ...)
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
			format = ft_format(format, ap, pr);
			//format = ft_format_0(format, ap, pr, len);
		}
		else
		{
			ft_putchar(*format++);
			(*pr).len++;
		}
		len = (*pr).len;
	}
	va_end(ap);
	len = (*pr).len;
	free(pr);	
	return (len);
}
