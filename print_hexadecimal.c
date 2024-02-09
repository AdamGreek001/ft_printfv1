/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:06:41 by eel-alao          #+#    #+#             */
/*   Updated: 2024/02/09 22:48:51 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>
int print_hexa(unsigned long nbr, int type )
{
    int count;
    char H[16]="0123456789ABCDEF";
    char h[16]="0123456789abcdef";

    count = 0;
    if (nbr < 16)
    {
        if (type == 1)
            count +=ft_putchar(H[nbr]);
        else if (type == 0)
            count +=ft_putchar(h[nbr]);
            
    }
    else
    {
        count += print_hexa(nbr / 16, type);
        count += print_hexa(nbr % 16, type);
    }
    return (count);
}

int print_address(void *nbr)
{
    int count;
    unsigned long nb;
                                                
    nb = (unsigned long)nbr;
    char h[16] = "0123456789abcdef";
    
    count = 0;
    if (nb < 16)
            count +=ft_putchar(h[nb]);
    else
    {
        count += print_address((void *)(nb / 16));
        count += print_address((void *)(nb % 16));
    }
    return (count);
}