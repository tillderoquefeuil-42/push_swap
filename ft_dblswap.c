/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:49:42 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/09 15:44:40 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapdbl(t_swap **stacka, t_swap **stackb, t_info **info)
{
	ft_swap(stacka, stackb, info, 's');
	ft_swap(stackb, stacka, info, 's');
	if ((*info)->a == 0)
	{
		if ((*info)->count != 0 && (*info)->v == 0)
			ft_putchar(' ');
		ft_putstr("ss");
	}
	ft_bonus(stacka, stackb, info);
}

void	ft_rotatedbl(t_swap **stacka, t_swap **stackb, t_info **info)
{
	ft_rotate(stacka, stackb, info, 'r');
	ft_rotate(stackb, stacka, info, 'r');
	if ((*info)->a == 0)
	{
		if ((*info)->count != 0 && (*info)->v == 0)
			ft_putchar(' ');
		ft_putstr("rr");
	}
	ft_bonus(stacka, stackb, info);
}

void	ft_reversedbl(t_swap **stacka, t_swap **stackb, t_info **info)
{
	ft_reverse(stacka, stackb, info, 'r');
	ft_reverse(stackb, stacka, info, 'r');
	if ((*info)->a == 0)
	{
		if ((*info)->count != 0 && (*info)->v == 0)
			ft_putchar(' ');
		ft_putstr("rrr");
	}
	ft_bonus(stacka, stackb, info);
}
