#include "libftprintf.h"
#include <stdio.h>
// https://cdn.intra.42.fr/pdf/pdf/883/ft_printf.en.pdf
// https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019
// http://www.c-cpp.ru/content/printf
// http://all-ht.ru/inf/prog/c/func/printf.html
// https://www.opennet.ru/man.shtml?topic=printf&category=3&russian=0
// https://ru.wikipedia.org/wiki/Stdarg.h

// о и х отличаются одной строкой =(


const char *ft_print_d(const char *format, va_list ap, t_print *pr)
{//знак сохраняю отдельно, в атои передаю тольео положительное
	int	num;
	long long  num_ll;
	char 			*str;

	str = NULL;
	if ((*pr).mod == 1)
		num = (short int)va_arg(ap, int);
	else if ((*pr).mod == 4)
		num = (signed char)va_arg(ap, int);
	else if ((*pr).mod == 5  || (*pr).mod == 2 || (*pr).mod == 7 || (*pr).mod == 6 )
	{
		num_ll = (long long)va_arg(ap, long long);
		if (num_ll < 0 || num_ll == MIN_LL)
		{
			(*pr).leftzero = 1;
			num_ll = -num_ll;
		}
		str = (num_ll == MIN_LL) ? ft_strdup("9223372036854775807") : ft_itoa_lu(num_ll);
	}
	else
	{
		num = va_arg(ap, int);
		if (num < 0 || num == -2147483648)
		{
			(*pr).leftzero = 1;
			num = -num;
		}
		str = (num ==  -2147483648) ? ft_strdup("2147483648") : ft_itoa_lu(num);
	}
	if (!str)
	{
		if (num < 0)
		{
			(*pr).leftzero = 1;
			num = -num;
		}
		str = ft_itoa_lu(num);
	}
	if (str[0] == '0' && !(*pr).mod &&(*pr).prec_p && (*pr).prec == 0)
		ft_print_str(format, "", pr);
	else 
		{
			ft_print_num(format, str, pr);
	
}
	if (str)
		free(str);
	return (format);
}
const char *ft_print_c(const char *format, va_list ap, t_print *pr)
{
	int c;
	char *str;
	int len;
// для 0 не надо молочить тогда
	c = (char)va_arg(ap, int);
	len = ((*pr).width) ? ((*pr).width) : 1;
	str = (char*)malloc(sizeof(char)*len + 1);
	str[len] = '\0';
	if (c)
	{//если по левому краю
		(*pr).minus ? ft_memset(str, c, 1) : ft_memset(str, ' ', len);
		(*pr).minus ? ft_memset(str + 1, ' ', len - 1) : ft_memset(str + (len - 1) , c, 1);
	}
	else
	{
		if ((*pr).minus)
				write(1, "\0", 1);
		((*pr).zero == 1) ? ft_memset(str, '0', len - 1) : ft_memset(str, ' ', len - 1);
	}
	ft_putstr(str);
	if (!c && !(*pr).minus)
		write(1, "\0", 1);
	(*pr).len += ft_strlen(str) + 1 * (!c);
	free (str);
	return (format);
}

// const char *ft_print_c(const char *format, va_list ap, t_print *pr)
// {
// 	int c;
// 	char *str;
// 	int len;

// 	c = (char)va_arg(ap, int);
// 	len = ((*pr).width) ? ((*pr).width) + (!c) : 1 + (!c);
// 	str = (len > 1) ? (char*)malloc(sizeof(char)*(*pr).width + 1 + (!c)) : (char*)malloc(sizeof(char)*(2 + (!c)));
// 	str[len] = '\0';
// 	if (c)
// 	{//если по левому краю
// 		(*pr).minus ? ft_memset(str, c, 1) : ft_memset(str, ' ', len);
// 		(*pr).minus ? ft_memset(str + 1, ' ', len - 1) : ft_memset(str + (len - 1) , c, 1);
// 	}
// 	else
// 	{
// 		if ((*pr).minus)
// 			write(1, "\0", 1);
// 		//printf("len = %d\n", len);
// 		//ft_memset(str, ' ', len);
// 		(*pr).minus ?  ft_memset(str, ' ', len - 2) : ft_memset(str, ' ', len);

// 		//(*pr).minus ? ft_memcpy(str, "\0", 2) : ft_memset(str, ' ', len);
// 		(*pr).minus ? ft_memset(str + 1, ' ', len - 2) : ft_memcpy(str + (len - 2) , "\0", 2);
// 	}
// 	if (!c && !(*pr).minus)
// 		write(1, "\0", 1);
// 	ft_putstr(str);

// 	(*pr).len += ft_strlen(str) + 1 * (!c);
// 	free (str);
// 	return (format);
// }


const char *ft_print_o(const char *format, va_list ap, t_print *pr)
{
	long long	int num;
	unsigned long long int n;
	char *str;


	if ((*pr).mod == 5 || (*pr).mod == 2  )
			n = (long long)va_arg(ap, long long);

	else if ((*pr).mod == 7 || (*pr).mod == 6)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else if ((*pr).mod == 1 )
	{
		num = (int)va_arg(ap, int);
		//printf("num = %o\n", num);
		n = (num < 0) ? 65536 + num : num;//32767
	}
	else if ((*pr).mod == 2)
		n = (long)va_arg(ap, long int);
	else if ((*pr).mod == 4)
		{
			num = (signed char)va_arg(ap, int);

			n = (num < 0) ? 256 + num : num;
			//printf("num = %o\n", n);
		}
	else 
	{
		num = va_arg(ap, int);
		n = (num < 0) ? 4294967296 + num : num;
	}
	if ((*pr).prec > 0)
		(*pr).rr = 0;
	str = n == 0 ? ft_strdup("0") : ft_int_base(n, (*pr).format);
	if (str[0] == '0' && (((*pr).prec_p && (*pr).prec == 0 )|| (*pr).rr == 1 ))
		((*pr).rr == 1 ) ? ft_print_num(format, "\0", pr): ft_print_str(format, "\0", pr);
	else
			ft_print_num(format, str, pr);
	free(str);
	return (format);
}

const char *ft_print_u(const char *format, va_list ap, t_print *pr)
{
	unsigned long long  num;
	char 			*str;



	if (!(*pr).mod && !((*pr).format == 11))
		num = (unsigned int)va_arg(ap, unsigned int);
	else if ((*pr).mod == 4)
		num = (unsigned char)va_arg(ap, int);
	else
		num = (unsigned long long)va_arg(ap, unsigned long long);
	(*pr).space = 0;
	(*pr).plus = 0;
	str = ((*pr).mod == 5 ||(*pr).mod == 2 || (*pr).mod == 6|| (*pr).mod == 7) ? ft_itoa_lu(num) : ft_itoa_lu(num);
	if (str[0] == '0' && !(*pr).mod &&(*pr).prec_p && (*pr).prec == 0 )
		ft_print_str(format, "\0", pr);
	else 
		ft_print_num(format, str, pr);
	free(str);
	return (format);
}


// # 0046 (int)
//   ft_printf("@moulitest: %#.x %#.0x", 0, 0);
//   1. (   15) -->@moulitest: 0 0<--
//   2. (   13) -->@moulitest:  <--
// # 0095 (int)
//   ft_printf("@moulitest: %#.o %#.0o", 0, 0);
//   1. (   13) -->@moulitest:  <--
//   2. (   15) -->@moulitest: 0 0<--

const char				*ft_print_x(const char *format, va_list ap, t_print *pr)
{
	long long			num;
	unsigned long long	n;
	long 				nbr;
	char				*str;


	//if ((*pr).mod == 5 || (*pr).mod == 2 || (*pr).format  == 9)
	if ((*pr).mod == 5 || (*pr).mod == 2)
		n = (long long)va_arg(ap, long long);
	else if ((*pr).mod == 4)
		n = (unsigned char)va_arg(ap, int);
	else if ( (*pr).format  == 9)
		n = ((nbr =  (long)va_arg(ap, long)) > 0 ? nbr : nbr);
		//n =  (long)va_arg(ap, long);
	else if ((*pr).mod == 7)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else if ((*pr).mod == 1 )
		n = ((num = (int)va_arg(ap, int)) < 0) ? 32767 + num : num;
	else if ((*pr).mod == 2)
		n = (long)va_arg(ap, long int);
	else if (!(*pr).mod || (*pr).format  == 5 )//|| (*pr).format == 8
		n = ((num = va_arg(ap, int)) < 0) ? 4294967296 + num : num;
	else
		n = (unsigned long long)va_arg(ap, unsigned long long);
	str = n == 0 ? ft_strdup("0") : ft_int_base(n, (*pr).format);
	(*pr).pr_0  = n == 0 ?  1 : 0;
	//printf("srt = %s\n", str);
	// printf("rr = %d\n", (*pr).rr );
	if (str[0] == '0' && (((*pr).prec_p && (*pr).prec == 0 ) || (*pr).rr == 1 ))// && (*pr).format  != 9
		{

			//printf("str1 = %s\n", str);
			if ((*pr).format  == 9 && !(*pr).prec_p)
				ft_print_num(format, str, pr);
			else if ((*pr).format  == 9)
				ft_print_str(format, "0", pr);			
			else if ((*pr).rr == 1 )//&& (*pr).format  != 9
				ft_print_str(format, "0", pr);
				//ft_print_num(format, str, pr);// && printf("str = %s\n", str); // ft_print_str(format, "0", pr);
			else
				ft_print_str(format, "\0", pr);
			// else if ((*pr).prec_p && (*pr).prec == 0 )
			// 	ft_print_str(format,"\0", pr);
			// else // if ((*pr).format  == 9 && !(*pr).prec_p)
			// 	ft_print_num(format, str, pr);

			//printf("daaa\n");
		}

	else
		{
		//((*pr).rr == 1) ? ft_print_str(format, str, pr): ft_print_str(format, str, pr);
		ft_print_num(format, str, pr);
		//printf("str2 = %s\n", str);
	}
	free(str);
	return (format);
}
// const char *ft_print_X(const char *format, va_list ap, t_print *pr)
// {

// 	long long	int num;
// 	unsigned long long int n;
// 	char *str;

// 	if ((*pr).mod == 5 || (*pr).mod == 2)
// 			n = (long long)va_arg(ap, long long);
// 	else if ((*pr).mod == 7)
// 		n = (unsigned long long)va_arg(ap, unsigned long long);
// 	else if ((*pr).mod == 1 )
// 	{
// 		num = (short int)va_arg(ap, int);
// 		n = (num < 0) ? 32767 + num : num;
// 	}
// 	else if ((*pr).mod == 2)
// 		n = (long)va_arg(ap, long int);
// 	else 
// 	{
// 		num = va_arg(ap, int);
// 		n = num < 0 ? 4294967296 + num : num;
// 	}
// 	str = n == 0 ? ft_strdup("0") : ft_int_base(n, 'X');
// 	if (str[0] == '0' && (((*pr).prec_p && (*pr).prec == 0 )|| (*pr).rr == 1 ))
// 		(*pr).rr == 1 ? ft_print_str(format, "0", pr): ft_print_str(format, "", pr);
// 	else
// 		ft_print_num(format, str, pr);
// 	free(str);
// 	return (format);
// }

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
			//printf("%d\n", ft_itoa_lu(num));
		}
		num_i = num + 0.5;
		//printf("num_i = %d\n", num_i);
		str_0 = ft_itoa_lu(num_i);
		//printf("str_0 = %s\n", str_0);
	}
	//printf("s_n = %d, s_p = %d\n", ft_size_int_lu(num_i), prec);
	if (ft_size_int_lu(num_i) > prec)
	{
		ft_memset(str_0, '0', prec);
		str_0[prec] = '\0';
		// printf("str_0! = %s\n", str_0);
		// printf("str_i!! = %d\n", str_i);		
		(*pr).pr_4erez_0 = 1;
	//	printf("str_i! = %d\n", str_i);
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

	str_2 = ft_itoa_double(num, pr);// если стр2 перевалит через десяток добавим 1 к стр
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
		return (ft_print_o(format, ap, pr));
	else if ((*pr).format == 6 || (*pr).format == 11)
		return (ft_print_u(format, ap, pr));	
	else if ((*pr).format == 7)
		return (ft_print_x(format, ap, pr));
	else if ((*pr).format == 8)
		return (ft_print_x(format, ap, pr));
		//return (ft_print_X(format, ap, pr));
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
	// if ((*pr).minus == 1 && (*pr).space == 1 && (*pr).minus == 1)
	// 	(*pr).space = 0;
	format = ft_width_check(format, pr, ap);	//чекаем на минимальную ширину
	//printf("format = %s\n", format);
	format = ft_precision_check(format, pr, ap);	//чекаем на точность
	format = ft_mod_check(format, pr);	//чекаем на модификатор длины
		//чекаем на тип
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
