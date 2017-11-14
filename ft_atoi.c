/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:32:51 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/11 13:44:03 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_info **info)
{
	int			i;
	long long	nbr;
	int			n;

	i = 0;
	nbr = 0;
	n = 0;
	if (str[i] == 43 || str[i] == 45)
		n = str[i++];
	if (47 > str[i] || str[i] > 58)
		ft_error(2, info);
	while (47 < str[i] && str[i] < 58)
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != 0)
		ft_error(2, info);
	if (n == 45)
		nbr = -nbr;
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_error(6, info);
	return (nbr);
}
