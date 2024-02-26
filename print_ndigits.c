/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ndigits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:29:32 by eel-alao          #+#    #+#             */
/*   Updated: 2024/02/26 20:15:47 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
		count = print_nbr(nb) + 1;
	}
	else if (nb > 9)
	{
		count = print_nbr(nb / 10);
		count += print_nbr(nb % 10);
	}
	else
		count += ft_putchar(nb + 48);
	return (count);
}

int	print_nbr_unsigned(long nb)
{
	return (print_nbr((unsigned)nb));
}
