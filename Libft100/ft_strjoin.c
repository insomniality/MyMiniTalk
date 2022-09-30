/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikarzum <mikarzum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:28:56 by mikarzum          #+#    #+#             */
/*   Updated: 2022/05/15 18:59:21 by mikarzum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		x[2];

	if (!s1 || !s2)
		return (0);
	x[0] = 0;
	while (s2[x[0]++])
		;
	x[1] = x[0];
	while (s1[x[0]++ - x[1]])
		;
	sum = (char *) malloc(x[0] - 1);
	if (!sum)
		return (NULL);
	while (x[0] - 1 != 0)
	{
		if (x[1] != 0)
		{
			sum[(--x[0]) - 1] = s2[--x[1]];
			continue ;
		}
		x[0]--;
		sum[x[0] - 1] = s1[x[0] - 1];
	}
	return (sum);
}
