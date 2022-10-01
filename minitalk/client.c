/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:15:53 by mikarzum          #+#    #+#             */
/*   Updated: 2022/10/01 21:31:22 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	g_i = 0;

int	ft_putnbr_base_r(long long nb, const char *base, int pid)
{
	long long	blen;
	long long	n;

	n = 0;
	blen = ft_strlen(base);
	if (!(nb / blen == 0 && nb % blen != 0 && g_i >= 7) && (nb != 0 || g_i < 7))
	{
		g_i++;
		n += ft_putnbr_base_r(nb / blen, base, pid);
	}
	else if (nb / blen == 0 && nb % blen != 0 && g_i >= 7)
	{
		usleep(600);
		if (base[nb % blen] - 48 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		return (1 + n);
	}
	usleep(600);
	if (base[nb % blen] - 48 == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	return (1 + n);
}

int	main(int argc, char **argv)
{
	int	i;
	int	u8;
	int	pid;

	if (argc == 3)
	{	
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			u8 = ft_putnbr_base_r(argv[2][i], "01", pid);
			g_i = 0;
			i++;
		}
	}
	else
		write(1, "Error\n", 6);
}
