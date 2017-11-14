/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:55:24 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/09 16:20:40 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issort(t_swap **begin, char ordre)
{
	t_swap	*tmp;
	t_swap	*tmp2;
	int		i;

	if (*begin != NULL)
	{
		i = 0;
		tmp = *begin;
		while (tmp->next != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			if (tmp2->data > tmp->data && ordre == 'a')
			{
				if (tmp->next != NULL && tmp2->data > tmp->next->data)
					i++;
				i++;
			}
			if (tmp2->data < tmp->data && ordre == 'b')
				i++;
		}
		return (i);
	}
	return (-1);
}

void	ft_push_swap(t_swap **stacka, t_swap **stackb, t_info **info)
{
	if (ft_issort(stacka, 'a') == 1)
		ft_oneswap(stacka, stackb, info);
	else if (ft_issort(stacka, 'a') > 1 && (*info)->nbr < 10)
		while (ft_issort(stacka, 'a') != 0)
		{
			ft_middlealgo(stacka, stackb, info);
			ft_middlealgoret(stackb, stacka, info);
		}
	else if (ft_issort(stacka, 'a') > 1)
		ft_bigalgotry(stacka, stackb, info);
}
