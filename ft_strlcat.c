/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:53:36 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/26 16:23:10 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *dst, size_t size)
{
	size_t l;

	return (l = (ft_strlen(dst) >= size) ? size : ft_strlen(dst));
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;

	len = ft_strnlen(dst, size);
	if (len == size)
		return (len + ft_strlen(src));
	return (len + ft_strlcpy(dst + len, src, size - len));
}
