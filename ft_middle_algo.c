/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:26:55 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/09 16:42:48 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_middlealgo(t_swap **stacka, t_swap **stackb, t_info **info)
{
	t_swap	*tmp;
	t_swap	*tmp2;
	t_swap	*tmpend;

	while (ft_issort(stacka, 'a') != 0)
	{
		tmp = *stacka;
		tmpend = *stacka;
		while (tmpend->next != NULL)
			tmpend = tmpend->next;
		tmp2 = tmp->next;
		if (tmp->data > tmp2->data)
			ft_swap(stacka, stackb, info, 'a');
		else if (tmp->data > tmpend->data && tmp->data < tmp2->data)
			ft_reverse(stacka, stackb, info, 'a');
		else
			ft_push(stackb, stacka, info, 'b');
	}
}

void	ft_middlealgoret(t_swap **stackb, t_swap **stacka, t_info **info)
{
	t_swap	*tmp;
	t_swap	*tmp2;
	t_swap	*tmpend;

	if (*stackb != NULL)
	{
		tmp = *stackb;
		while (tmp->next != NULL)
		{
			tmpend = *stackb;
			while (tmpend->next != NULL)
				tmpend = tmpend->next;
			tmp2 = tmp->next;
			if (tmp->data < tmp2->data)
				ft_swap(stackb, stacka, info, 'b');
			else if (tmp->data < tmpend->data)
				ft_reverse(stackb, stacka, info, 'b');
			else
				ft_push(stacka, stackb, info, 'a');
			tmp = *stackb;
		}
		ft_push(stacka, stackb, info, 'a');
	}
}
