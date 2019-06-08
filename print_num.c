#include <libftprintf.h>

// char	*ft_strjoin_free(char *s1, char *s2)
// {
// 	char	*new;
// 	int		i;
// 	int		len1;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	new = NULL;
// 	new = (char*)malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!new)
// 		return (NULL);
// 	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	i = -1;
// 	while (s1[++i])
// 		new[i] = s1[i];
// 	len1 = i;
// 	i = 0;
// 	while (s2[i])
// 	{
// 		new[len1 + i] = s2[i];
// 		i++;
// 	}
// 	//free(s1);
// 	free(s2);
// 	return (new);
// }

static char *ft_print_num2(int len_str, t_print *pr) // максимальный размер из трех
{//строка которая должна быть напечатана в зависимости от ширины и точности
	char 	*str2;
	int 	len_max;

	if ((*pr).width && len_str <= (*pr).width) // создаем строку большего размера
		len_max = (*pr).width;
	else if ((*pr).prec_p && (*pr).prec > len_str)
		len_max = (*pr).width;
	else 
		len_max = len_str;
	str2 = (char*)malloc(sizeof(char)*len_max + 1);
	str2[len_max] = '\0';
	ft_memset(str2, ' ', len_max);
	//printf("str2 = %s, len = %d\n",  str2, len_max);
	return (str2);
}
static int	ft_str_format(t_print *pr, char *st_cat)
{
	int len_z; 

	len_z = 0;//!(*pr).prec_p &&
	if ( (*pr).space && !(*pr).leftzero && !(*pr).plus && !(*pr).pr_x)
			ft_memset(st_cat + len_z++, ' ', 1);
	if ((*pr).rr == 1)// и если чило не 0
	{
		if (((*pr).format == 7 || (*pr).format == 9 
			|| (*pr).format == 8 || (*pr).format == 5))// && (*pr).pr_0 == 0)
		{
			ft_memset(st_cat + len_z++, '0',  1);

			//if (!ft_strncmp(format, "x", 1) || !ft_strncmp(format, "p", 1))
			if ((*pr).format == 7  || (*pr).format == 9)
				ft_memset(st_cat + len_z++, 'x',  1);
			// else if (!ft_strncmp(format, "X", 1))
			else if ((*pr).format == 8)
				ft_memset(st_cat + len_z++, 'X', 1);
		}
	}
return(len_z);
}
static int ft_str_len_v(t_print *pr,  int len, int len_str)
{
	int len_str_v;
	int pr_x;
	
	//printf("len_str = %d, len %d = \n ", len_str, len);
	len_str_v = 0;
	if ((*pr).prec_p && (*pr).prec > (len_str)) //если точность есть и если она ноль 
	// нужно заполнить разницу нулями
		len_str_v = len_str + (*pr).prec - len;
	else 
		len_str_v = len_str;
	if (((*pr).width - len_str - len) > (*pr).prec && (*pr).zero && !(*pr).minus)
			len_str_v += ((*pr).width - len_str - len) - (*pr).prec;
	if ((*pr).space )//&& !(*pr).leftzero && !(*pr).plus)//нужен пробел
		len_str_v += 1;
	if ((*pr).leftzero || (*pr).plus)
		(*pr).space = 0;
	//if ((*pr).rr == 1 || !ft_strncmp(format, "p", 1))// и если чило не 0
	if ((*pr).rr == 1 || (*pr).format == 9)// и если чило не 0
		{

		// if (!ft_strncmp(format, "x", 1) || !ft_strncmp(format, "p", 1) 
		// 	|| !ft_strncmp(format, "X", 1) || !ft_strncmp(format, "o", 1))
		if ((*pr).format == 7 || (*pr).format == 9 
			|| (*pr).format == 8 || (*pr).format == 5 )//
		{
				len_str_v += 1;
			// if (!ft_strncmp(format, "x", 1) || !ft_strncmp(format, "p", 1))
			if ((*pr).format == 7  || (*pr).format == 9)
				len_str_v += 1;
			else if ((*pr).format == 8)
				len_str_v += 1;
		}
	}
	if ((*pr).leftzero == 1 || ((*pr).plus && !(*pr).leftzero))//если есть знак минус
		len_str_v += 1;
 	pr_x = (!(*pr).zero && ((*pr).format == 7 || (*pr).format == 8 || (*pr).format == 9 )) ? 1 : 0;
// 	//(*pr).prec = pr_x == 1 ? (*pr).prec + 2 : (*pr).prec;	
// printf("pr_x = %d\n", pr_x);
	//printf("len = %d, pr_x = %d\n ", len_str_v, pr_x);
	return (len_str_v + 2 * pr_x);
}


static char *ft_print_num3(int len_str, t_print *pr, int len, char *str) // максимальный размер из трех
{// len - длина служебных символов
	char 	*st_cat;
	int 	len_0;
 	int 	len_z;
 // 	int pr_x;
 // 	
 // 	pr_x = (!(*pr).zero && ((*pr).format == 7 || (*pr).format == 8 || (*pr).format == 9 )) ? 1 : 0;
	// (*pr).prec = pr_x == 1 ? (*pr).prec + 2 : (*pr).prec;

	st_cat = ft_strnew(ft_str_len_v(pr,  len, len_str));//вот это строка все вмещать должна
	st_cat[ft_str_len_v(pr, len, len_str)] = '\0';
	//printf("t_str_len = %d\n", ft_str_len_v(pr, len, len_str));

	len_z =	ft_str_format(pr, st_cat);//добавление пробела, нуля, пробелами и 0x если надо

	if ((*pr).leftzero == 1)//если есть знак минус
		ft_memset(st_cat + len_z++, '-', 1);
	if ((*pr).plus && !(*pr).leftzero && !(*pr).pr_x)
		ft_memset(st_cat + len_z++, '+', 1);
	//тут еще все ок
	
	if ( !(*pr).prec_p  && (*pr).width && ((*pr).width - len_str - len) >= (*pr).prec && (*pr).zero && !(*pr).minus)
	{//(*pr).prec_p &&

		len_0 = ((*pr).width - len_str - len) - (*pr).prec - (*pr).space;
		if (len_0 > 0)
			ft_memset(st_cat + len_z, '0', len_0);///тут сега!!!!!!!
		//printf("st_cat1 = %s\n", st_cat);
		len_z = len_z + len_0; //уже заполненные 
		//write(1,"!!!",3);
	}

	//printf("prec_p = %d\n", (*pr).prec);
	//printf("prec_p = %d, f = %d\n", (*pr).prec, (*pr).format);
	if ((*pr).prec_p && (*pr).prec > (len_str)) //если точность есть и если она ноль 
	{
		
		//printf("prec  =  %d, len_str = %d, len_z = %d , len = %d st_cat = %s \n",(*pr).prec,len_str , len_z, len, st_cat);
		ft_memset(st_cat + len_z, '0', (*pr).prec);
		//ft_memset(st_cat + len_z, '0', (*pr).prec - len);
		//printf("prec  =  %d, len_str = %d, len_z = %d , len = %d st_cat = %s \n",(*pr).prec,len_str , len_z, len, st_cat);
 		// if ((*pr).rr == 1)
 		// 	len_z = 0;
		ft_memcpy(st_cat+((*pr).prec -  len_str + len_z), str, len_str);
		//ft_memcpy(st_cat+((*pr).prec - len_str + len_z), str, len_str);

 	//printf("prec  =  %d, len_str = %d, len_z = %d , len = %d str = %s \n",(*pr).prec,len_str , len_z, len, str);

	}
	else 
		ft_memcpy(st_cat + len_z, str, len_str);
	//printf("str_num = %s\n", st_cat);
	return (st_cat);
}


const char *ft_print_num(const char *format, char *str, t_print *pr)
{
	int len_str;
	char 	*str2;
	char 	*st_cat;
	int 	len;
//str - это число без знака
	
	len_str = ft_strlen(str);
	str2 = ft_print_num2(len_str, pr);//строка в зависимости от минимальной ширины
	// если есть '-' 0 игнорируется
	//длина служебных знаков
	len = 1 * ((*pr).plus) + 1 * ((*pr).leftzero)*(!(*pr).plus) + 2 *((*pr).rr);
	st_cat = ft_print_num3(len_str, pr, len, str);
	if ((len_str = ft_strlen(str2) - ft_strlen(st_cat)) > 0)//если была минимальная ширина
		if ((*pr).minus)//если по левому краю
			ft_memcpy(str2, st_cat, ft_strlen(st_cat));
		else 
			ft_memcpy(str2 + len_str, st_cat, ft_strlen(st_cat));
	else
		{
			free(str2);
			str2 = ft_strdup(st_cat);
		}
	free(st_cat);
	ft_putstr(str2);
	(*pr).len += ft_strlen(str2);
	if (str2)
		free(str2);
	return (format);
}