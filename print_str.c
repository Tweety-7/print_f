#include <libftprintf.h>

char		*ft_print_str2(int len_str, t_print *pr)
{//строка которая должна быть напечатана в зависимости от ширины и точности
	char 	*str2;

	if (((*pr).width && len_str <= (*pr).width) || (((*pr).prec < (*pr).width ) && (*pr).prec_p ))//|| ((*pr).prec < (*pr).width && (*pr).prec >  len_str) ) // создаем строку большего размера
	{
		str2 = (char*)malloc(sizeof(char)*(*pr).width + 1);
		str2[(*pr).width] = '\0';
		ft_memset(str2, ' ', (*pr).width);
	}
	else if ((*pr).prec_p && (*pr).prec <=  len_str)
	{
			str2 = (char*)malloc(sizeof(char)*(*pr).prec + 1);
			str2[(*pr).prec] = '\0';
			ft_memset(str2, ' ', (*pr).prec);//printf("drty\n");
	}
	else if ((*pr).format == 9 && (*pr).prec_p && (*pr).prec > 0)
	{
		str2 = (char*)malloc(sizeof(char)*(*pr).prec + 1);
		str2[(*pr).prec] = '\0';
		ft_memset(str2, ' ', (*pr).prec);
	}
	else 
	{
		str2 = (char*)malloc(sizeof(char)*len_str+ 1);
		str2[len_str] = '\0';
		ft_memset(str2, ' ', len_str);
	}
	if ((*pr).zero)// || (*pr).prec_p )
		ft_memset(str2, '0', (*pr).width);
			//!!!//ft_memset(str2, '0', (*pr).width - len_str);
	//printf("s2=%s|\n", str2);
	if ((*pr).format == 9 && (*pr).prec_p && (*pr).prec > 0)
		ft_memset(str2, '0', (*pr).prec);
	return (str2);
}


static char	*ft_print_str3(char *str, t_print *pr)
{
	int		len_str;
	char	*st_cat;
	char	*str2;


	len_str = (ft_strncmp(str, "0x", 2) == 0 ? 0 : ft_strlen(str));
	len_str = ft_strlen(str);
	str2 = ft_print_str2(len_str, pr);
	if (ft_strncmp(str, "0x", 2) == 0)
	{
		st_cat = ft_strjoin(str, str2);
	}
	else if ((*pr).prec_p && ((*pr).prec >= 0 ) && ft_strncmp(str, "%", 1)) //если точность есть и если она ноль && ft_strncmp(str, "%", 1)
	//else if ((*pr).prec_p && ((*pr).prec > 0 )) //если точность есть и если она ноль && ft_strncmp(str, "%", 1)
	{// надо обрезать по точности
		//printf("str22 = %s\n", str);
		st_cat = ft_strnew((*pr).prec);
		st_cat = ft_strncat(st_cat, str, (*pr).prec);
		//printf("st - %s\n", st_cat);
	}
	// else if ((*pr).prec_p && ((*pr).prec == 0))
	// 	st_cat = ft_strdup("");
	else 
	 	{st_cat = ft_strdup(str);
	 	 //printf("ddd\n");
	 	}

	if ((*pr).minus)//если по левому краю
		ft_memcpy(str2, st_cat, ft_strlen(st_cat));
	else 
	{
		if (ft_strncmp(str, "0x", 2))
		{

			len_str = ft_strlen(str2) == 0 ? 0 : ft_strlen(str2) - ft_strlen(st_cat);
			//printf("str2 = %s, st_cat = %s, d = %d\n",str2, st_cat, len_str );
			//len_str = ft_strlen(str2) - ft_strlen(st_cat);
			ft_memcpy(str2 + len_str, st_cat, ft_strlen(st_cat));
		}
		else
		{
			str2 = ft_strdup(st_cat);

		}
	}
	free(st_cat);
	return (str2);
}

  // ft_printf("%.0%");
  // 1. (    0) --><--
  // 2. (    1) -->%<--

const char	*ft_print_str(const char *format, char *str, t_print *pr)
{
	char	*str2;

	if ((!str || str == NULL) && (*pr).zero == 0)
		str = ft_strdup("(null)");
	else if (!str || str == NULL)
	{
		str = ft_strdup("0");
	}
	else if ((*pr).format == 9 && str[0] == '0' )
		str = ft_strdup("0x");
	else if (str[0] == '%')
		str = ft_strdup("%");
	else
		str = ft_strdup(str);
	str2 = ft_print_str3(str, pr);
		//}
	ft_putstr(str2);
	(*pr).len += ft_strlen(str2);
	free(str2);
	free(str);
	return (format);
}
