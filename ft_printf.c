/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:45:02 by eel-alao          #+#    #+#             */
/*   Updated: 2024/02/09 22:48:48 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

void print_it(va_list arg, char c, int *len)
{
    if (c == 'c')
        *len += ft_putchar(va_arg(arg, int));
    else if (c == 's')
        *len += ft_printstr(va_arg(arg, char *));
    else if (c == 'd' || c == 'i')
        *len += print_nbr(va_arg(arg, int));
    else if (c == 'u')
        *len += print_nbr_unsigned(va_arg(arg, unsigned int));
    else if (c == 'p')
    {
        ft_printstr("0x");
        *len += 2;
        *len += print_address(va_arg(arg, void *));
    }
    else if (c == 'x')
        *len += print_hexa(va_arg(arg, unsigned int), 0);
    else if (c == 'X')
        *len += print_hexa(va_arg(arg, unsigned int), 1);
    else 
        *len += ft_putchar(c);
}

int ft_printf(const char *format, ...)
{
    int i;
    int lenght;
    va_list arg;
    
    if (write(1, "", 1) < 0)
        return (-1);
    va_start(arg, format);
    i = 0;
    lenght = 0;
    while (format[i])
    {
        if(format[i] == '%' && format[i + 1] != '\0')
            print_it(arg, format[++i], &lenght);
        else
        {
            ft_putchar(format[i]);
            lenght++;
        }
        i++;
    }
    va_end(arg);
    return(lenght);
}
// #include <libc.h>
// int main ()
// {
//     //char s[] = "bachir";
//     int i = 9;
//     // ft_printf("the add is %c", 'a');
//     int j = ft_printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
//     int r = printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
//     printf("dyali %d  dyalhom %d",j,r);
// }