/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:57:43 by qgilbert          #+#    #+#             */
/*   Updated: 2019/05/05 15:00:15 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

#include <limits.h>
int main(void)
{
	char *str=" privetiki";

	// ft_printf("%s, %s \n", str, str);
	// printf("%s, %s \n", str, str);	
	//ft_printf("%s10This is a% X sim%ople test.%d\n", str,15, 7, 123);
	// printf("prf=%0+5d %05d %03.2d %03.2d\n", -42, -42, -1,1);
	// ft_printf("mft%0+5d %05d %03.2d %03.2d\n", -42, -42, -1,1);
	// printf("prf=@moulitest: %c", '^@');
	// ft_printf("mft=@moulitest: %2c\n", 0);
	// printf("prf=@moulitest: %5c\n", 42);
	// ft_printf("mft=@moulitest: %5c\n", 42);
	// printf("prf=%lld\n", -9223372036854775808);
	// ft_printf("m1 = s: %p, p: %p, d:%p\n", &str, &main, 0);
	//    printf("p1 = s: %p, p: %p, d:%p\n", &str, &main, 0);

	// ft_printf("m = %ju\n", 4999999999);
// printf("p = %u\n", 4999999999);
// printf("p = %U\n", 4999999999);
// ft_printf("m = %u\n", 4999999999);
// ft_printf("m = %U\n", 4999999999);

	// ft_printf("m = %ju\n", 4294967296);
	// printf("p = %ju\n", 4294967296);

	// printf("pp = %c\n", 0);
	// ft_printf("mp = %c\n", 0);

	// printf("before %O after\n", 40);
	// ft_printf("before %O after\n", 40);



	//ft_printf("mft=%llx\n", -4294967296);	
	//printf("prf=%d\n", 42);
	//ft_printf("m = the %d\n", 1);	

// 	printf("p=%4.15d\n", 42);
// 	ft_printf("m =%4.15d\n", 42);	
// ft_printf("%s\n", NULL);
//   ft_printf("\n");
//   ft_printf("%%\n");
//   ft_printf("%d\n", 42);
//   ft_printf("%d%d\n", 42, 41);
//   ft_printf("%d%d%d\n", 42, 43, 44);
//   ft_printf("%ld\n", 2147483647);
//   ft_printf("%lld\n", 9223372036854775807);
//   ft_printf("%x\n", 505);
//   ft_printf("%X\n", 505);
//   ft_printf("%p\n", &ft_printf);
//   ft_printf("%20.15d\n", 54321);
//   ft_printf("%-10d\n", 3);
//   ft_printf("% d\n", 3);
//   ft_printf("%+d\n", 3);
//   ft_printf("%010d\n", 1);
//   ft_printf("%hhd\n", 0);
//   ft_printf("%jd\n", 9223372036854775807);
//   ft_printf("%zd\n", 4294967295);
//   ft_printf("%\n");
//   ft_printf("%U\n", 4294967295);
//   ft_printf("%u\n", 4294967295);
//   ft_printf("%o\n", 40);
//   ft_printf("%%#08x\n", 42);
//   ft_printf("%x\n", 1000);
//   ft_printf("%#X\n", 1000);
//   ft_printf("%s\n", NULL);
//   ft_printf("%S\n", L"ݗݜशব");
//   ft_printf("%s%s\n", "test", "test");
//   ft_printf("%s%s%s\n", "test", "test", "test");
//   ft_printf("%C\n", 15000);

	// ft_printf("m = %f\n", 7.5);
	// printf("p = %f\n", 7.5);

	// ft_printf("m = %.*s\n", -5, "42");
	// printf("p = %.*s\n", -5, "42");
	// ft_printf("m0 = %05.*d\n", -15, 42);
	// printf("p0 = %05.*d\n", -15, 42);
	// 	ft_printf("m0 = % 03d\n", 0);
	// printf("p0 = % 03d\n", 0);

	// ft_printf("m1 = %5.*d\n", -15, 42);
	// printf("p1 = %5.*d\n", -15, 42);

// printf("max = %o\n", USHRT_MAX);
// printf("max d= %d\n", USHRT_MAX);

// printf("p = %ho, %ho\n", 0, USHRT_MAX);
// ft_printf("m = %ho\n", USHRT_MAX);
// 	int i;
// printf("p%.5p, %.p\n", 0, 0);
// ft_printf("m%.5p, %.p\n", 0, 0);

// printf("p%.05s, %4.s\n", 0, "42");
// ft_printf("m%.05s, %4.s\n", 0, "42");



// printf("p%05.%\n", 0);
// ft_printf("m%05.%\n", 0);

// printf("p%.0%\n", 0);
// ft_printf("m%.0%\n", 0);


	///////
// printf("p = %4.s|\n", "42");
// ft_printf("m = %4.s|\n", "42");

// printf("p=%.3%|\n");
// ft_printf("m=%.3%|\n");

// printf("p=%#.o, %#.0o\n", 0, 0);
// ft_printf("m=%#.o, %#.0o\n", 0, 0);



// printf("%#.x, %#.0x\n", 0, 0);
// ft_printf("%#.x, %#.0x\n", 0, 0);


// printf("%.p, %.0p", 0, 0);
// ft_printf("%.p, %.0p", 0, 0);


// printf("{%05.c}\n", 0);
// ft_printf("{%05.c}\n", 0);

// printf("{%05.s}", 0);
// ft_printf("{%05.s}", 0);

// printf("{%05.%}", 0);
// ft_printf("{%05.%}", 0);

// printf("{%05.Z}", 0);
// ft_printf("{%05.Z}", 0);

// printf("{%#.5x}", 1);
// ft_printf("{%#.5x}", 1);

// printf("%#.3o", 1);
// ft_printf("%#.3o", 1);

// printf("{%05.S}", L"42 c est cool");
// ft_printf("{%05.S}", L"42 c est cool");

//printf("p=%hhu, %hhu\n", 0, UCHAR_MAX + 42);
// int i = 0;
// while (i++ < 10)
// {
// 	ft_printf("m=%hhx, %hhx\n", 0, UCHAR_MAX + 42);
// 	//ft_printf("%zo, %zo\n", 0, ULLONG_MAX);
// }
// printf("p=%hhx, %hhx\n", 0, UCHAR_MAX + 42);

//printf("p=%zo, %zo\n", 0, ULLONG_MAX);
// printf("p=%#.3o\n", 1);
// printf("p=%.3o\n", 1);
// printf("p=%0.3o\n", 1);
//printf("p=%hhu / %hhu\n", SHRT_MAX - 42,  SHRT_MAX - 4200);

//ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
// ft_printf("%hhx, %hhx\n", 0, UCHAR_MAX + 42);

// ft_printf("m =%#.3o\n", 1);
// ft_printf("m =%.3o\n", 1);
// ft_printf("m =%0.3o\n", 1);


//ft_printf("%hhu / %hhu\n", SHRT_MAX - 42,  SHRT_MAX - 4200);
//^.^/% 010zi^.^/
//ft_printf("^.^/% 010zi^.^/\n",3259974216);
// printf("^.^/% 010zi^.^/\n",3259974216);
// printf("p=^.^/% 010zi\n", 3259974216);
// ft_printf("m=^.^/% 010zi\n",3259974216);

// printf("%zX, %zX\n", 0, ULLONG_MAX);
// ft_printf("%zX, %zX\n", 0, ULLONG_MAX);
// ft_printf("%zx, %zx\n", 0, ULLONG_MAX);
// ft_printf("%zx, %zx\n", 0, ULLONG_MAX);

// printf("% 049i\n", -1828128238);
// ft_printf("% 049i\n",-1828128238);
//////////////////


//"%#.o, %#.0o", 0, 0
printf("%.3f\n", 0.9999);
printf("%.1f\n", 0.999);
ft_printf("%.3f\n", 0.9999);
ft_printf("%.1f\n", 0.99);

// ft_printf("f%.0d, %.d\n", 0, 0);
// ft_printf("p%.0d, %.d\n", 0, 0);

// printf("%+o\n", 1);
// ft_printf("%+o\n", 1);
// printf("p = %hho, %ho\n", -42, -42);
// ft_printf("m = %hho, %ho\n", -42, -42);
	// ft_printf("m3 = %*d\n", 5, 42);
	// printf("p3 = %*d\n", 5, 42);
	// ft_printf("m3 = %*d\n", 5, 42);
	// printf("p3 = %*d\n", 5, 42);

	// 	ft_printf("m33 = {%4*p}\n", 10, 0);
	// printf("p33 = {%4*p}\n", 10, 0);
	// ft_printf("m=% p|%+p|%-p\n", 42, 42, -42);

	// printf("p=% p|%+p|%-p\n", 42, 42, -42);
	
	// ft_printf("mx=% x|%+x|\n", 42, 42);

	// printf("px=% x|%+x|\n", 42, 42);
	// ft_printf("mx3 = %10x\n", 0);
	// printf("px3 = %10x\n", 0);
	// int i;

	// printf("p0 = %p\n", &i);
	// ft_printf("m0 = %p\n", &i);
	// 	ft_printf("m = %5.*d\n", -15, 42);
	// printf("p = %5.*d\n", -15, 42);
	// ft_printf("m = %*s\n", 5, 0);
	// printf("p = %*s\n", 5, 0);
	// ft_printf("m = %5s\n", 0);
	// printf("p = %5s\n", 0);
	// printf("%040.2lld\n", 1270919052);
	// ft_printf("%040.2lld\n", 1270919052);

	// printf("%040lld\n", 1270919052);
	// ft_printf("%040lld\n", 1270919052);

	// printf("%040.2lld\n", 1270919052);
	// ft_printf("%040.2lld\n", 1270919052);
	// 	ft_printf("m0 = %05.*d\n", 15, 42);
	// printf("p0 = %05.*d\n", 15, 42);


	// 	ft_printf("m = %5.*d\n", 15, 42);
	// printf("p = %5.*d\n", 15, 42);
	// ft_printf("m = %05.-15d\n", 42);
	// printf("p = %05.-15d\n", 42);

	// ft_printf("m = %3*p\n", 10, &str);
	// printf("p = %3*p\n", 10, &str);
	// ft_printf("m = %*p\n", 10, &str);
	// printf("p = %*p\n", 10, &str);


	// ft_printf("m = %3*s\n", 4, "qwerrty");
	// printf("p = %3*s\n", 4, "qwerrty");
// 	printf("mm = %d\n", ft_printf("m = %.*s\n", -5, "42"));
// printf("pp = %d\n", printf("p = %.*s\n", -5, "42"));
	ft_printf("m = %f\n", 1.42);
	printf("p = %f\n", 1.42);

	ft_printf("m = %F\n", 1.42);
	printf("p = %F\n", 1.42);


	ft_printf("m = %f\n", -1.42);
	printf("p = %f\n", -1.42);


	ft_printf("m = %F\n", -1.42);
	printf("p = %F\n", -1.42);
	ft_printf("m = %f\n", 1444565444646.6465424242242);
	printf("p = %f\n", 1444565444646.6465424242242);

		ft_printf("m = %f\n", -1444565444646.6465424242242454654);
	printf("p = %f\n", -1444565444646.6465424242242454654);	

	ft_printf("m = %F\n", 1.42);
	printf("p = %F\n", 1.42);

	ft_printf("m = %f\n", 0.0);
	printf("p = %f\n", 0.0);

	// ft_printf("mc = %05c\n", 0);
	// printf("pc = %05c\n", 0);

	// ft_printf("mc = %05.c\n", 0);
	// printf("pc = %05.c\n", 0);

	// ft_printf("ms = %15.4s\n", "42 is the answer");
	// printf("ps = %15.4s\n", "42 is the answer");

	// 	ft_printf("ms = %.4s\n", "42 is the answer");
	// printf("ps = %.4s\n", "42 is the answer");
	// //351/396

	// ft_printf("ms = %05.1s\n", 0);
	// printf("ps = %05.1s\n", 0);

	// ft_printf("mx = %#0.5x\n", 0);
	// printf("px = %#0.5x\n", 0);

	// ft_printf("m = %8f\n", 1.0);
	// printf("p = %8f\n", 1.0);
	// ft_printf("m = %f\n", 1.0);
	// printf("p = %f\n", 1.0);

	// ft_printf("m = %f\n", -7.5);
	// printf("p = %f\n", -7.5);

	// // ft_printf("m = % f\n", 7.5);
	// // printf("p = % f\n", 7.5);

	// // 	ft_printf("m = %.9f\n", 7.5);
	// // printf("p = %.9f\n", 7.5);

	// 	ft_printf("m = %10f\n", -111117.5);
	// printf("p = %10f\n", -111117.5);

	//printf("p = the %d\n", 1);	
	//printf("s = %s\n", ft_int_base(18446744073709551615 ,'o') );	
	// printf("s = %s\n", ft_int_base(9223372036854775807,'x') );
	//printf("%d\n", ft_strlen_num(156) );
	//ft_printf("\n");
	//printf("This is a simple test.\n");
	//ft_printf("%s",str);
	//printf("%x\n", str);
	return(0);
}
