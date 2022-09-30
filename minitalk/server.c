/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:26:50 by mikarzum          #+#    #+#             */
/*   Updated: 2022/09/30 12:55:04 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.c"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int	vk;

int	pW(int n, int pw)
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

char	*hello(void)
{
	static char barev[1000000];
	return barev;
}

void one(int signum)
{
	//write(1, "0", 1);
	//fin += ((int)o8[i] - 48) * pw(2, 7 - i);
	//hello()[10] = 'a';
	vk = 0;
}

void two(int signum)
{
	//write(1, "1", 1);
	vk = 1;
}

int main()
{
	char	o8[9];
	int		pid;
	int		fin;
	int		i;


	pid = getpid();
	ft_printf("%d\n", pid);
	
	i = 0;
	fin = 0;
	o8[8] = '\0';
	struct sigaction sa; //check why?
	sa.sa_flags = SA_SIGINFO; //check why?
	sigemptyset(&(sa.sa_mask));
	sa.sa_handler = &one; //check why?
	sigaction(SIGUSR1, &sa, NULL); //check why?

	struct sigaction sb; //check why?
	sb.sa_flags = SA_SIGINFO;
	sigemptyset(&(sb.sa_mask)); //check why?
	sb.sa_handler = &two; //check why?	
	sigaction(SIGUSR2, &sb, NULL);

	//ft_printf("%s\n", str);
	//while (1)
	//	pause();
	while(1) 
	{
		pause();
		//if (i == 7)
		//{
		//	fin = 0;
		//	i = 0;
		//	while (i < 8)
		//	{
		//		fin += vk * pW(2, 7 - i);
		//		i++;
		//	}
		//	write(1, &fin, 1);
		//	i = 0;
		//	fin = 0;
		//}

		fin += vk * pW(2, 7 - i);
		//printf( "i is %d AND fin is%d\n", i, fin);
		i++;
		if (i == 8)
		{
			write(1, &fin, 1);
			i = 0;
			fin = 0;
		}
	}
}
