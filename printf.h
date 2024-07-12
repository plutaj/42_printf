/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:18:04 by jpluta            #+#    #+#             */
/*   Updated: 2024/07/12 19:27:28 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		ft_printf(const char *string, ...);
void	form_spec_check(const char *string, va_list args, int *len);
void	is_pointer(size_t pointer, int *len);
void	is_char(char a, int *len);
void	is_string(char *s, int *len);
void	is_int(int num, char *str, int *len);

#endif
