/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:31:09 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/24 22:37:29 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	l;
	unsigned long	i;

	i = 0;
	p = b;
	l = c;
	while (i < len)
	{
		p[i] = l;
		i++;
	}
	return (p);
}
