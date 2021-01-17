/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:56:59 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/23 20:31:18 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	char			*s;
	unsigned int	i;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (d == 0 && !src)
		return (dst);
	else if (d == 0 && s == 0)
		return (NULL);
	else
	{
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
