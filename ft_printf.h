/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:46:03 by eel-alao          #+#    #+#             */
/*   Updated: 2024/02/09 22:48:44 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <libc.h>
int ft_printf(const char *format, ...);
void print_it(va_list arg, char c, int *len);
int ft_putchar(char c);
int ft_printstr(const char *s);
int print_nbr(long nb);
int print_nbr_unsigned(long nb);
int print_hexa(unsigned long nbr, int type );
int print_address(void *nbr);

#endif