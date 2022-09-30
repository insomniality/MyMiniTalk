/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:15:53 by mikarzum          #+#    #+#             */
/*   Updated: 2022/09/30 13:46:21 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
//#include <unistd.h>
#include <signal.h>
#include "ft_atoi.c"
//#include "ft_printf/ft_putnbr_base.c"

int idx = 0;

int	ft_putnbr_base_r(long long nbr, const char *base, int pid)
{
	long long	blen;
	long long	n;
	
	n = 0;
	blen = ft_strlen(base);
	if (!(nbr / blen == 0 && nbr % blen != 0 && idx >= 7) && (nbr != 0 || idx < 7))// && n + 1 < 8
	{
		idx++;	
		n += ft_putnbr_base_r(nbr / blen, base, pid); // + (idx++) * 0
	}
	else if (nbr / blen == 0 && nbr % blen != 0 && idx >= 7) // && idx < 8
	{
		if (base[nbr % blen] - 48 == 0)
		{
			usleep(600);
			kill(pid, SIGUSR1); //0
		}
		else
		{
			usleep(600);
			kill(pid, SIGUSR2); //1
		}
		return (1 + n);
	}
	if (base[nbr % blen] - 48 == 0)
	{
		usleep(600);
		kill(pid, SIGUSR1); //0
	}
	else
	{
		usleep(600);
		kill(pid, SIGUSR2); //1
	}
	return (1 + n);
}

int main(int argc, char **argv) // Hello World!
{
	int	i;
	int u8;
	int pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	//kill(pid, SIGUSR1); // SIGINT stops the process
	//write(1, "a",1);
	
	while (argv[2][i] != '\0')
	{
		u8 = ft_putnbr_base_r(argv[2][i], "01", pid);
		// while (u8 < 8) // sxala piti skzbic ani
		// {
		// 	kill(pid, SIGUSR1); //0
		// 	u8++;
		// }
		//write(1,"hm\n", 3);
		idx = 0;
		i++;
	}
}

/*
int idx = 0;

int    ft_putnbr_base_r(long long nbr, const char *base)
{
    long long    blen;
    long long    n;
    
    n = 0;
    blen = strlen(base);
    if (!(nbr / blen == 0 && nbr % blen != 0 && idx >= 8) && (nbr != 0 || idx < 8))
    {
        idx++;
        n += ft_putnbr_base_r(nbr / blen, base);
    }
    else if (nbr / blen == 0 && nbr % blen != 0)
    {
        if (base[nbr % blen] - 48 == 0)
             write(1, "0", 1); //0
        else
             write(1, "1", 1); //1
        //idx++;
        return (1 + n);
    }
    if (base[nbr % blen] - 48 == 0)
        write(1, "0", 1); //0
    else
        write(1, "1", 1); //1

    //idx++;
    return (1 + n);
}

int main() // Hello World!
{
    int    i;
    int    u8;
    char* argv = "!ell8";
    
    i = 0;
    //kill(pid, SIGUSR1); // SIGINT stops the process
    //write(1, "a",1);
    
    while (argv[i] != '\0')
    {
        u8 = ft_putnbr_base_r(argv[i], "01");
        // while (u8 < 8) // sxala piti skzbic ani
        // {
        //     kill(pid, SIGUSR1); //0
        //     u8++;
        // }
        write(1,"\n",1);
        idx = 0;
        i++;
    }
}
*/