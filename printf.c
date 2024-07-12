/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:03:29 by jpluta            #+#    #+#             */
/*   Updated: 2024/07/12 19:28:15 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	form_spec_check(const char *string, va_list args, int *len)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
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
	int		age;

	a = "jozef";
	age = 26;
	int i = ft_printf("ahoj %s, mas %d rokov\n", a, age);
	printf("%d", i);

	return (0);
}
