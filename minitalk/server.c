/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:26:50 by mikarzum          #+#    #+#             */
/*   Updated: 2022/10/03 22:21:39 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	g_vk;

int	pwr(int n, int pw)
{
	int	x;

	x = n;
	if (pw == 0)
		return (1);
	while (pw - 1 != 0)
	{
		x *= n;
		pw--;
	}
	return (x);
}

void	one(int i)
{
	(void) i;
	g_vk = 0;
}

void	two(int i)
{
	(void) i;
	g_vk = 1;
}

int	main(void)
{
	struct sigaction	sa;
	struct sigaction	sb;
	int					fin;
	int					i;

	ft_printf("%d\n", (int)getpid() + (i = 0) + (fin = 0));
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&(sa.sa_mask));
	sa.sa_handler = &one;
	sigaction(SIGUSR1, &sa, NULL);
	sb.sa_flags = SA_SIGINFO;
	sigemptyset(&(sb.sa_mask));
	sb.sa_handler = &two;
	sigaction(SIGUSR2, &sb, NULL);
	while (1)
	{
		pause();
		fin += g_vk * pwr(2, 7 - i++);
		if (i == 8)
		{
			write(1, &fin, 1);
			i = 0;
			fin = 0;
		}
	}
}
