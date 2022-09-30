/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:10:29 by mikarzum          #+#    #+#             */
/*   Updated: 2022/07/11 21:12:47 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long nbr, const char *base)
{
	long long	blen;
	long long	n;

	n = 0;
	blen = ft_strlen(base);
	if (nbr < 0 && blen == 10)
	{
		write(1, "-", 1);
		nbr *= (-1);
		n++;
	}
	if (!(nbr / blen == 0 && nbr % blen != 0) && nbr != 0)
		n += ft_putnbr_base(nbr / blen, base);
	else if (nbr / blen == 0 && nbr % blen != 0)
	{
		write(1, &base[nbr % blen], 1);
		return (1 + n);
	}
	write(1, &base[nbr % blen], 1);
	return (1 + n);
}
