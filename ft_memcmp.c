/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:56:39 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/23 23:37:45 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (*((unsigned char*)s1) == *((unsigned char*)s2))
		{
			s1++;
			s2++;
			i++;
		}
		else
			return (*((unsigned char*)s1) - *((unsigned char*)s2));
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}
