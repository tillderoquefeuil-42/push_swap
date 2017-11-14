/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:43:45 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/11 13:46:20 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*ft_bonusdetector(char **tab, int *i, t_info **info)
{
	(*info)->v = 0;
	(*info)->c = 0;
	(*info)->a = 0;
	(*info)->f = 0;
	(*info)->e = 0;
	while (tab[*i][0] == '-' && tab[*i][1] > 95 && tab[*i][1] < 127)
	{
		if (tab[*i][0] == '-' && tab[*i][2] == 0)
		{
			if (tab[*i][1] == 'v')
				(*info)->v = 1;
			else if (tab[*i][1] == 'c')
				(*info)->c = 1;
			else if (tab[*i][1] == 'a')
				(*info)->a = 1;
			else if (tab[*i][1] == 'f')
				(*info)->f = 1;
			else if (tab[*i][1] == 'e')
				(*info)->e = 1;
			*i = *i + 1;
		}
	}
	return (*info);
}

void	ft_bonus(t_swap **stacka, t_swap **stackb, t_info **info)
{
	if ((*info)->v == 1)
	{
		ft_putchar('\n');
		ft_lstprint(*stacka);
		ft_lstprint(*stackb);
	}
	(*info)->count = (*info)->count + 1;
}

void	ft_printstack(t_swap **stacka, t_info **info)
{
	if ((*info)->f == 1 && (*info)->count == 0)
	{
		ft_putstr("Stack avant le tri : ");
		ft_lstprint(*stacka);
	}
	if ((*info)->f == 1 && (*info)->count != 0)
	{
		ft_putstr("Stack apres le tri : ");
		ft_lstprint(*stacka);
	}
	if ((*info)->count != 0)
	{
		if (*stacka)
			free(*stacka);
		if (*info)
			free(*info);
	}
}
