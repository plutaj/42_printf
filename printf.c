/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:03:29 by jpluta            #+#    #+#             */
/*   Updated: 2024/07/11 17:56:45 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	form_spec_check(const char *string, va_list args, int *len)
{
	char	a;
	char	*b;
	int		i;

	i = 0;
	if (*string == '%')
	{
		*len += 1;
		write(1, "%", 1);
	}
	else if (*string == 'c')
	{
		a = va_arg(args, int);
		*len += 1;
		write(1, &a, 1);
	}
	else if (*string == 's')
	{
		is_string(va_arg(args, char *), len);
		// b = va_arg(args, char *);
		// while (*b)
		// {
		// 	write(1, b, 1);
		// 	b++;
		// 	*len += 1;
		// }
	}
	else if (*string == 'p')
		is_pointer(va_arg(args, size_t), len);
	else if (*string == 'i' || *string == 'd')
	{
	}
	// else if (*string == 'u')
	// {
	// }
	// else if (*string == 'x' || *string == 'X')
	// {
	// }
}

int	ft_printf(const char *string, ...) // ahoj %%
{
	int length;
	size_t i;
	va_list args;

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

int	main(void)
{
	char	*a;
	a = "jozef";
	// int i = ft_printf("ahoj %s, tvoja znamka je %c", a, b);
	// printf("\n%d", i);
	int i = ft_printf("my address: %s\n", a);
	printf("original address: %p\n", a);
	printf("%d\n", i);
	return (0);
}
