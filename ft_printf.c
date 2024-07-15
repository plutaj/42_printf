/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:03:29 by jpluta            #+#    #+#             */
/*   Updated: 2024/07/15 18:00:38 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	form_spec_check(const char *string, va_list args, int *len)
{
	char	str[15];

	if (*string == '%')
		len += write(1, "%", 1);
	else if (*string == 'c')
		is_char(va_arg(args, int), len);
	else if (*string == 's')
		is_string(va_arg(args, char *), len);
	else if (*string == 'p')
		is_pointer(va_arg(args, size_t), len);
	else if (*string == 'i' || *string == 'd')
		is_int(va_arg(args, int), str, len);
	else if (*string == 'u')
		is_uint(va_arg(args, unsigned int), str, len);
	else if (*string == 'x')
		is_shexa(va_arg(args, unsigned int), len);
	else if (*string == 'X')
		is_bhexa(va_arg(args, unsigned int), len);
}

int	ft_printf(const char *string, ...)
{
	int		length;
	size_t	i;
	va_list	args;

	length = 0;
	i = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			form_spec_check(&string[i], args, &length);
			i++;
		}
		else
		{
			length++;
			write(1, &string[i], 1);
			i++;
		}
	}
	va_end(args);
	return (length);
}

// int	main(void)
// {
// 	// char	*a;
// 	int	age = -9;

// 	// a = "jozef";
// 	// age = 4294967291;
// 	int i = ft_printf("num is %i\n", age);
// 	// i = ft_printf("hex num of 9999 is %X\n", age);
// 	printf("%d\n", i);
// 	// i = ft_printf("tvoj vek je %d\n", 0);
// 	// printf("%d\n", i);
// 	// i = ft_printf("tvoj vek je %d\n", -2147483648);
// 	// printf("%d\n", i);
// 	// i = ft_printf("tvoj vek je %d\n", 1298439850);
// 	// printf("orig pointer je %p\n", a);
// 	// printf("%d", i);

// 	return (0);
// }
