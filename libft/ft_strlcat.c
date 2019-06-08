/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:21:15 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/06 15:21:22 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t    ft_strlcat(char *dst, const char *src, size_t size)
{
    unsigned long i;
    unsigned long j;
    unsigned long s;

    i = 0;
    j = 0;
    s = size;
    if (size == 0)
        return (ft_strlen(src));
    while (dst[i] && s-- != 0)
        i++;
    if (s == 0)
        return (i + ft_strlen(src));
    s = i;
    while (src[j])
        if (i < size - 1 )
        	dst[i++] = src[j++];
    dst[i] = '\0';
    return (s + ft_strlen(src));
}


// size_t	ft_strlcat(char *d, const char *s, size_t n)
// {
// 	size_t		s_d;
// 	size_t		s_n;
// 	size_t		s_s;

// 	s_n = n;
// 	s_d = 0;
// 	while (s_n-- != 0 && *d != '\0')
// 	{
// 		d++;
// 		s_d++;
// 	}
// 	n = n - s_d;
// 	if (n <= 0)
// 		return (s_d + ft_strlen(s));
// 	s_s = -1;
// 	while (s[++s_s])
// 	{
// 		if (n > 1)
// 		{
// 			*d++ = s[s_s];
// 			n--;
// 		}
// 	}
// 	*d = '\0';
// 	return (s_d + s_s);
// }
