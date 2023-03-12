#include <stdarg.h>
#include "libft.h"

#include <stdio.h>




char	*ft_itoa_base16(long num, int upcase)
{
	char	*symb;
	char	*buffer;
	size_t	buffer_size;
	size_t	i;

	if (upcase)
		symb = "0123456789ABCDEF";
	else
		symb = "0123456789abcdef";
	buffer_size = sizeof(num) * 2;
	buffer = malloc(buffer_size);
	if (!buffer)
		return NULL;
	i = 0;
	while(buffer_size-- > 0)
		buffer[i++] = symb[(num >> (buffer_size * 4)) & 0xf];
	buffer[i] = '\0';
	while (*buffer == '0' && *(buffer+1) != '\0')
	{
		*buffer = '\0';
		buffer++;
	}
	return buffer;
}


int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (format[i] == 's')
				ft_putstr_fd(va_arg(args, char*), 1);
			else if (format[i] == 'p')
				ft_putstr_fd(va_arg(args, void*), 1);					
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i] == 'u')
				ft_putnbr_fd(va_arg(args, int), 1); // restict negative numbers
			else if (format[i] == 'x')
				ft_putstr_fd(ft_itoa_base16(va_arg(args, int), 0), 1);
			else if (format[i] == 'X')
				ft_putstr_fd(ft_itoa_base16(va_arg(args, int), 1), 1);
			else if (format[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return 0;
}


int main()
{
	int arr[] = {INT_MIN, -300, -03, -0, 0, 1, 0111, 456775, INT_MAX, -1};
	int i = 0;
	while (arr[i] != -1)
	{
		//printf("number: %i\n", arr[i]);
		//ft_putchar_fd('\n', 1);
		printf("printf:    %z\n", arr[i]);
		ft_printf("ft_printf: %X\n", arr[i]);
		//ft_putchar_fd('\n', 1);
		//printf("\n");
		i++;
	}

}