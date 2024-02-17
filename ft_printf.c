/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:45:02 by eel-alao          #+#    #+#             */
/*   Updated: 2024/02/17 02:31:01 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

void print_it(va_list arg, char y, int *len)
{
    if (y == 'c')
        *len += ft_putchar(va_arg(arg, int));
    else if (y == 's')
        *len += ft_printstr(va_arg(arg, char *));
    else if (y == 'd' || y == 'i')
        *len += print_nbr(va_arg(arg, int));
    else if (y == 'u')
        *len += print_nbr_unsigned(va_arg(arg, unsigned int));
    else if (y == 'p')
    {
        ft_printstr("0x");
        *len += 2;
        *len += print_address(va_arg(arg, void *));
    }
    else if (y == 'x')
        *len += print_hexa(va_arg(arg, unsigned int), 0);
        
    else if (y == 'X')
        *len += print_hexa(va_arg(arg, unsigned int), 1);
    else 
        *len += ft_putchar(y);
}

int ft_printf(const char *format, ...)
{
    int i;
    int lenght;
    va_list arg;
    
    if (write(1, "", 0) < 0)
        return (-1);
    va_start(arg, format);
    i = 0;
    lenght = 0;
    while (format[i])
    {
        if(format[i] == '%' && format[i + 1] != '\0')
            print_it(arg, format[++i], &lenght);
        else if (format[i] != '%')
        {
            ft_putchar(format[i]);
            lenght++;
        }
        i++;
    }
    va_end(arg);
    return(lenght);
}
#include <libc.h>

int main()
{
    //fclose(stdout);
    //close(1);
    // int a;
    // int b;

    // a = 0;
    // b = 0;

    // scanf("%d", &a);
    // printf("\n");
    // scanf("%i", &b);
    // printf("%d\n", a);
    // printf("%i\n", b);

    //char c = r + '0';
    //fprintf(stderr, "%d\n", r);
}
// // // #include <libc.h>
// int main ()
// {
//     //char s[] = "bachir";
//     int i = 9;
//     // ft_printf("the add is %c", 'a');
//     int j = ft_printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
//     int r = printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
//     printf("dyali %d  dyalhom %d",j,r);
// }