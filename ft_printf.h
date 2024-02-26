/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:46:03 by eel-alao          #+#    #+#             */
/*   Updated: 2024/02/26 20:14:25 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libc.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	print_it(va_list arg, char c, int *len);
int		ft_putchar(char c);
int		ft_printstr(const char *s);
int		print_nbr(long nb);
int		print_nbr_unsigned(long nb);
int		print_hexa(unsigned long nbr, int type);
int		print_address(void *nbr);

#endif