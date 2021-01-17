/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:43:16 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/23 23:47:31 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	j;
	unsigned long	k;

	k = 1;
	j = 0;
	if (n == 0)
		return (0);
	while ((s1[j] != '\0' && s2[j] != '\0') && (k < n))
	{
		if (s1[j] == s2[j])
		{
			j++;
		}
		k++;
	}
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
