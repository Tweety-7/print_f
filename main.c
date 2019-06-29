#include "libftprintf.h"
#include <stdio.h>
int main(void)
{
	int i1;
	int i2;
	i1 = ft_printf("m = %.1f\n", 1.999);
	i2 = printf("p = %.1f\n", 1.999);

	i1 = ft_printf("m = %.0f\n", 12.5);
	i2 = printf("p = %.0f\n", 12.5);

	i1 = ft_printf("m = %.0f\n", 13.5);
	i2 = printf("p = %.0f\n", 13.5);

	printf("%d %d\n", i1, i2);
}
