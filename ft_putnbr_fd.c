/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:39:04 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/23 21:17:21 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nouvar;

	nouvar = n;
	if (n < 0)
	{
		nouvar = -n;
		ft_putchar_fd('-', fd);
	}
	if (nouvar <= 9)
	{
		ft_putchar_fd(nouvar + 48, fd);
	}
	if (nouvar > 9)
	{
		ft_putnbr_fd(nouvar / 10, fd);
		ft_putchar_fd(nouvar % 10 + 48, fd);
	}
}
