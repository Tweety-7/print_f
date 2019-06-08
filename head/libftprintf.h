/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:08:36 by qgilbert          #+#    #+#             */
/*   Updated: 2019/05/05 14:11:38 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

#define MIN_LL -9223372036854775807
typedef struct	s_print
{
	int 	len;
	int 	width;
	int 	rr;
	int 	space;
	int 	plus;
	int 	minus;
	int 	zero;
	int 	prec;
	int 	prec_p;
	int 	mod; // от 0 до 7
	int 	net;
	int 	leftzero;
	int 	format; // от 0 до 11
	int 	pr_x;
	int 	pr_0;
	int 	pr_4erez_0;

	//unsigned long long	num;
	//char ch; // используется??

}			t_print;

// typedef struct	s_print
// {
// 	int 	len;
// 	int 	width;
// 	int 	rr : 2;
// 	int 	space : 2;
// 	int 	plus : 2;
// 	int 	minus : 2;
// 	int 	zero : 2;
// 	int 	prec;
// 	int 	prec_p : 2;
// 	int 	mod : 4; // от 0 до 7
// 	int 	net : 2;
// 	int 	leftzero : 2;
// 	int 	format : 5; // от 0 до 11

// 	unsigned long long	num;
// 	char ch; // используется??

// }			t_print;

const char *ft_format(const char *format, va_list ap, t_print *pr);

int ft_printf(const char *format, ...);
int ft_strlen_num(int num);
char				*ft_itoa_ll(unsigned long long int n);
char				*ft_itoa_lu(unsigned long long int n);
char *ft_int_base(unsigned long long one, int base);

const char *ft_flag_check(const char *format, t_print *pr);
const char *ft_width_check(const char *format, t_print *pr, va_list ap);
const char *ft_precision_check(const char *format, t_print *pr, va_list ap);
const char *ft_mod_check(const char *format, t_print *pr);
const char *ft_format_check(const char *format, t_print *pr);


char *ft_print_str2(int len_str, t_print *pr);
const char *ft_print_str(const char *format, char *str, t_print *pr);


const char *ft_print_num(const char *format, char *str, t_print *pr);

int			ft_size_int_lu(unsigned long long n);
#endif