/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:18:22 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/09 16:43:03 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_oneswapspl(t_swap **stacka, int *c)
{
	t_swap	*tmp;
	t_swap	*tmp2;
	int		i;

	i = 0;
	tmp = *stacka;
	while (tmp->next != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp2->data > tmp->data)
			*c = i;
		i++;
	}
	return (i);
}

void	ft_oneswap(t_swap **stacka, t_swap **stackb, t_info **info)
{
	int		i;
	int		c;

	i = ft_oneswapspl(stacka, &c);
	if (c <= i / 2)
	{
		i = 0;
		while (i < c && i++ >= 0)
			ft_rotate(stacka, stackb, info, 'a');
		ft_swap(stacka, stackb, info, 'a');
		while (i-- > 0)
			ft_reverse(stacka, stackb, info, 'a');
	}
	else
	{
		i = i - c;
		c = 0;
		while (c++ <= i)
			ft_reverse(stacka, stackb, info, 'a');
		ft_swap(stacka, stackb, info, 'a');
		while (i-- >= 0)
			ft_rotate(stacka, stackb, info, 'a');
	}
}
