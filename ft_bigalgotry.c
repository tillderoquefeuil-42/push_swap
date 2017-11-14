/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 11:20:58 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/09 16:55:49 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_pivotmin(t_swap **stacka, int *nbr, t_info **info)
{
	t_swap	*tmp;
	int		i;
	int		c;

	tmp = *stacka;
	*nbr = tmp->data;
	i = 1;
	c = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->data < *nbr)
		{
			*nbr = tmp->data;
			c = i;
		}
		i++;
	}
	if (c <= i / 2)
	{
		(*info)->rot = 1;
		return (c);
	}
	(*info)->rot = 0;
	return (i - c);
}

int		ft_pivotmax(t_swap **stacka, int *nbr, t_info **info)
{
	t_swap	*tmp;
	int		i;
	int		c;

	tmp = *stacka;
	*nbr = tmp->data;
	i = 1;
	c = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->data > *nbr)
		{
			*nbr = tmp->data;
			c = i;
		}
		i++;
	}
	if (c <= i / 2)
	{
		(*info)->rot = 1;
		return (c);
	}
	(*info)->rot = 0;
	return (i - c);
}

int		ft_pivotfinal(t_swap **stacka, int *nbr, t_info **info)
{
	if (ft_pivotmin(stacka, nbr, info) < ft_pivotmax(stacka, nbr, info) + 1)
	{
		(*info)->min = 1;
		return (ft_pivotmin(stacka, nbr, info));
	}
	else
	{
		(*info)->min = 0;
		return (ft_pivotmax(stacka, nbr, info));
	}
}

void	ft_bigalgotry(t_swap **stacka, t_swap **stackb, t_info **info)
{
	int		nbr;
	t_swap	*tmp;

	while (*stacka != NULL)
	{
		ft_pivotfinal(stacka, &nbr, info);
		tmp = *stacka;
		while (tmp->data != nbr)
		{
			if ((*info)->rot == 1)
				ft_rotate(stacka, stackb, info, 'a');
			else
				ft_reverse(stacka, stackb, info, 'a');
			tmp = *stacka;
		}
		ft_push(stackb, stacka, info, 'b');
		if ((*info)->min == 0)
			ft_rotate(stackb, stacka, info, 'b');
		if (ft_issort(stacka, 'a') == 1)
			ft_oneswap(stacka, stackb, info);
	}
	ft_bigalgoret(stacka, stackb, info);
}

void	ft_bigalgoret(t_swap **stacka, t_swap **stackb, t_info **info)
{
	int		nbr;
	t_swap	*tmp;

	ft_pivotmax(stackb, &nbr, info);
	tmp = *stackb;
	while (tmp->data != nbr)
	{
		if ((*info)->rot == 1)
			ft_rotate(stackb, stacka, info, 'b');
		else
			ft_reverse(stackb, stacka, info, 'b');
		tmp = *stackb;
	}
	while (*stackb != NULL)
		ft_push(stacka, stackb, info, 'a');
}
