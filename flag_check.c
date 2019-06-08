#include <libftprintf.h>

const char *ft_flag_check(const char *format, t_print *pr)
{// следующий опять может быть флаг
	while (ft_strncmp(format, "#", 1) == 0 || ft_strncmp(format, " ", 1) == 0 ||
		ft_strncmp(format, "+", 1) == 0 || ft_strncmp(format, "-", 1) == 0 ||
		ft_strncmp(format, "0", 1) == 0 )
	{
		if (ft_strncmp(format, "#", 1) == 0)// возможно после решетки обязательно тип
			(*pr).rr = 1;
		else if (ft_strncmp(format, " ", 1) == 0)
			(*pr).space = 1;
		else if (ft_strncmp(format, "+", 1) == 0)
			(*pr).plus = 1;
		else if (ft_strncmp(format, "-", 1) == 0)
			(*pr).minus = 1;
		else
			(*pr).zero = 1;
		format++;
	}
	return(format);
}

const char *ft_width_check(const char *format, t_print *pr, va_list ap)
{//значит ширина указана - минимальный размер выводимого числа


	if (format[0] == '*')
	{
		(*pr).width = (int)va_arg(ap, int);
		if ((*pr).width < 0)
			{
				(*pr).width = -(*pr).width;
				(*pr).minus = 1;
			}
		format++;

	}
	(*pr).width = (ft_isdigit(*format)) ? 0 : (*pr).width;
	while (ft_isdigit(*format))//в приоритете то что последнее
	{
		(*pr).width = (*pr).width * 10 + (*format - '0');
		format++;
	}
	if (format[0] == '*')
	{
		(*pr).width = (int)va_arg(ap, int);
		if ((*pr).width < 0)
			{
				(*pr).width = -(*pr).width;
				(*pr).width = 1;
			}
		format++;
		//printf("w = %d\n", (*pr).width);
	}	
	return (format);
}

const char *ft_precision_check(const char *format, t_print *pr, va_list ap)
{
	
	if (ft_strncmp(format, ".", 1) == 0) // точность есть
	{
		format++;

		
		(*pr).prec_p = 1;
		if (format[0] == '*')
		{
			(*pr).prec = (int)va_arg(ap, int);
			if ((*pr).prec < 0)
				{
					//(*pr).prec_p = (*pr).width != 0 ? 0 : 0;
					(*pr).prec =  (*pr).width;
					if ((*pr).zero != 1)
						(*pr).prec_p = 0;
					//printf("fl = %d\n", (*pr).zero );

					//(*pr).prec_p =  (*pr).width != 0 ? 0 : 0; 


					//(*pr).space = 1; 
				}
			return (++format);
		}

		while (ft_isdigit(*format))
		{
			(*pr).prec = (*pr).prec * 10 + (*format - '0');
			format++;
		}	
	}
	
	return(format);
}
const char *ft_mod_check(const char *format, t_print *pr)
{
	if (!ft_strncmp(format, "hh", 2) || !ft_strncmp(format, "ll", 2)) // точность есть
	{
		if (ft_strncmp(format, "hh", 2) == 0)
			(*pr).mod = 4;
		else
			(*pr).mod = 5;
		format++;
	}
	else if (ft_strncmp(format, "h", 1) == 0)
		(*pr).mod = 1;
	else if (ft_strncmp(format, "l", 1) == 0)
		(*pr).mod = 2;
	else if (ft_strncmp(format, "j", 1) == 0)
		(*pr).mod = 7;		
	else if (ft_strncmp(format, "z", 1) == 0)
		(*pr).mod = 6;		
	else if (!ft_strncmp(format, "L", 1))
		(*pr).mod = 3;
	else
		(*pr).mod = 0;
	if ((*pr).mod != 0)
		format++;
	return(format);
}

const char *ft_format_check(const char *format, t_print *pr)
{
	if (ft_strncmp(format, "s", 1) == 0 || ft_strncmp(format, "S", 1) == 0)
		(*pr).format = 1;
	else if (ft_strncmp(format, "d", 1) == 0)// || !ft_strncmp(format, "D", 1)
		(*pr).format = 2;
	else if (!ft_strncmp(format, "D", 1))
		{
			(*pr).format = 2;
			(*pr).mod = 5;
		}
	else if (ft_strncmp(format, "c", 1) == 0 || ft_strncmp(format, "C", 1) == 0 )
		(*pr).format = 3;
	else if (ft_strncmp(format, "p", 1) == 0)	
	{
		(*pr).rr = 1;
		(*pr).format = 9;
	}
	else if (ft_strncmp(format, "i", 1) == 0)
		(*pr).format = 4;
	else if (ft_strncmp(format, "o", 1) == 0 )//|| ft_strncmp(format, "O", 1) == 0)
		(*pr).format = 5;
	else if (!ft_strncmp(format, "O", 1))
		{
			(*pr).format = 5;
			(*pr).mod = 5;
		}
	else if (ft_strncmp(format, "u", 1) == 0 )
		(*pr).format = 6;
	else if (!ft_strncmp(format, "U", 1))
		(*pr).format = 11;			
	else if (ft_strncmp(format, "x", 1) == 0)
		(*pr).format = 7;
	else if (ft_strncmp(format, "X", 1) == 0)
		(*pr).format = 8;
	else if (!ft_strncmp(format, "f", 1) || !ft_strncmp(format, "F", 1))
		(*pr).format = 10;
	else
		(*pr).net = 1;
	if (((*pr).format >= 7 && (*pr).format <= 9 )|| (*pr).format == 5)
		(*pr).pr_x = 1;
	if ((*pr).format != 0)
		format++;
	return(format);
}
