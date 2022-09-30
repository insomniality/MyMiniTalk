/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:22:41 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/14 22:24:40 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{	
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*(unsigned char *)&s1[i] == *(unsigned char *)&s2[i] && i < n - 1)
		i++;
	return ((*((unsigned char *)&s1[i]) - *((unsigned char *)&s2[i])));
}
