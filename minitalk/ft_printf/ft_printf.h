/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:21:57 by mikarzum          #+#    #+#             */
/*   Updated: 2022/10/01 20:50:50 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_putnbr_base(long long nbr, const char *base);
int		ft_putnbr_base_p(unsigned long long nbr, const char *base);
int		ft_putstr(char	*str);
int		ft_printf(const char *str, ...);

#endif
