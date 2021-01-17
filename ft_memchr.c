/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:53:24 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/23 20:34:33 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	l;
	unsigned int	i;

	i = 0;
	l = (unsigned char)c;
	src = (unsigned char*)s;
	while (i < n)
	{
		if (*src == l)
			return (src);
		src++;
		i++;
	}
	return (0);
}
