/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstrings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:26:38 by eel-alao          #+#    #+#             */
/*   Updated: 2024/02/09 22:48:54 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// # include <unistd.h>
int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_printstr(const char *s)
{
    int i;
    if (s == NULL)
        return (ft_printstr("null"));
    i = 0;
    while (s[i])
        ft_putchar(s[i++]);
    return (i);
}
