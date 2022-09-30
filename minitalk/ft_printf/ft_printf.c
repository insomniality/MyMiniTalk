/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:35:43 by mikarzum          #+#    #+#             */
/*   Updated: 2022/07/11 21:22:48 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	engine(const char *str, int i, int j, va_list list)
{
	int	bkt;

	if (str[i] == 37 && str[i + 1] == 'c')
	{
		bkt = (unsigned char)va_arg(list, int);
		j += -(write (1, &bkt, 1));
	}
	else if (str[i] == 37 && str[i + 1] == 's')
		j += ft_putstr(va_arg(list, char *)) - 2;
	else if (str[i] == 37 && str[i + 1] == 'p')
	{
		write(1, "0x", 2);
		j += ft_putnbr_base_p(va_arg(list, unsigned long), "0123456789abcdef");
	}
	else if (str[i] == 37 && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		j += ft_putnbr_base(va_arg(list, int), "0123456789") - 2;
	else if (str[i] == 37 && str[i + 1] == 'u')
		j += ft_putnbr_base(va_arg(list, unsigned int), "0123456789") - 2;
	else if (str[i] == 37 && str[i + 1] == 'x')
		j += ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef") - 2;
	else if (str[i] == 37 && str[i + 1] == 'X')
		j += ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF") - 2;
	else if (str[i] == 37 && str[i + 1] == '%')
		j += -(write (1, "%", 1));
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int				i;
	int				j;
	va_list			list;

	i = 0;
	j = 0;
	va_start (list, str);
	while (str[i])
	{
		if (str[i] != 37)
			write (1, &str[i++], 1);
		else
		{
			j = engine(str, i, j, list);
			i += 2;
		}
	}
	return (i + j);
}
