/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:56:56 by jpluta            #+#    #+#             */
/*   Updated: 2024/07/14 17:19:37 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	do_conversion(unsigned int num, unsigned int original_n, int digits, char *str)
{
	while (original_n != 0)
	{
		original_n = original_n / 10;
		digits++;
	}
	str[digits--] = '\0';
	while (num != 0)
	{
		str[digits] = (num % 10) + '0';
		num = num / 10;
		digits--;
	}
}
void	is_char(char a, int *len)
{
	*len += write(1, &a, 1);
}
void	is_pointer(size_t pointer, int *len)
{
	char	string[25];
	char	*hexa;
	size_t	i;

	// char	*string;
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
void	is_string(char *s, int *len)
{
	while (*s)
	{
		*len += write(1, s, 1);
		s++;
	}
}
void	is_int(int num, char *str, int *len)
{
	int	original_n;
	int	digits;

	original_n = num;
	digits = 0;
	if (num == 0)
	{
		*len += write(1, "0", 1);
		return ;
	}
	if (num == -2147483648)
	{
		*len += write(1, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		digits++;
		str[0] = '-';
		num = num * (-1);
	}
	do_conversion(num, original_n, digits, str);
	is_string(str, len);
}
void 	is_uint(unsigned int n, char *str, int *len)
{
	unsigned int	original_n;
	int				digits;

	original_n = n;
	digits = 0;
	if (n == 0)
	{
		*len += write(1, "0", 1);
		return ;
	}
	do_conversion(n, original_n, digits, str);
	is_string(str, len);
}
void	is_shexa(unsigned int hexn, int *len)
{
	char	string[25];
	char	*hexa;
	size_t	i;

	hexa = "0123456789abcdef";
	
	
	i = 0;
	if (hexn == 0)
	{
		*len += write(1, "0", 1);
		return ;
	}
	while (hexn != 0)
	{
		string[i] = hexa[hexn % 16];
		hexn = hexn / 16;
		i++;
	}
	while (i--)
	{
		*len += write(1, &string[i], 1);
	}
}
void	is_bhexa(unsigned int hexn, int *len)
{
	char	string[25];
	char	*hexa;
	size_t	i;

	hexa = "0123456789ABCDEF";
	
	
	i = 0;
	if (hexn == 0)
	{
		*len += write(1, "0", 1);
		return ;
	}
	while (hexn != 0)
	{
		string[i] = hexa[hexn % 16];
		hexn = hexn / 16;
		i++;
	}
	while (i--)
	{
		*len += write(1, &string[i], 1);
	}
}