#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
int count = 0;

int putnbr (int n)
{
	int nb = n;

	if (n < 0)
	{
		write(1, "-", 1);
		nb = n * -1;
		count++;
	}
	if (nb >= 10)
		count += putnbr(nb / 10);
	char c = nb % 10 + '0';
	write(1,&c , 1);
	count++;
	return (0);
}

int puthexa (int n, char *base)
{

	if (n >= 16)
		count += puthexa(n / 16, base);
	write(1, &base[n %16], 1);
	count++;
	return (0);
}

int putstr(char *str)
{
	int i = 0;
	if (str ==  NULL)
	{
		write(1, "(null)", 6);
		return 6;
	}
	while(str[i])
		write(1, &str[i++], 1 );
	return i;
}
int ft_printf(const char *format, ...)
{
	va_list	arg;
	va_start(arg, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'd'  )
		{
			count += putnbr(va_arg(arg, int));
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'x' )
		{
			count += puthexa(va_arg(arg, int), "0123456789abcdef");
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 's')
		{
			count += putstr(va_arg(arg, char *));
			format += 2;
		}
		else
		{
			count += write(1, format++, 1);
		}
	}
	return (count);
}

int main(void)
{
	int i = printf("%d %s %x return=\n", 42, "coucou", 42);
	int j = ft_printf("%d %s %x return=\n", 42, "coucou", 42);

	printf("%d %d\n", i, j);
}