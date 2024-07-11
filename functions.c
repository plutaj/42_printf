/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:56:56 by jpluta            #+#    #+#             */
/*   Updated: 2024/07/11 17:56:50 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	is_pointer(size_t pointer, int *len)
{
	char	string[25];
	// char	*string;
	char	*hexa;
	size_t	i;

	// string = NULL;
	hexa = "0123456789abcdef";
	i = 0;
	if (pointer == 0)
	{
		*len += write(1, "(nil)", 5);
		return ;
	}
	*len += write(1, "0x", 2);
	while (pointer != 0)
	{
		string[i] = hexa[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		*len += write(1, &string[i], 1);
	}
}

void	is_string(char *s, int len)
{
	b = va_arg(args, char *);
		while (*b)
		{
			write(1, b, 1);
			b++;
			*len += 1;
		}
}
