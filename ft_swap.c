/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:30:49 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/09 16:49:08 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_swap **stacka, t_swap **stackb, t_info **info, char s)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	if (*stacka != NULL && (*stacka)->next != NULL)
	{
		tmp = *stacka;
		tmp2 = (*stacka)->next;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
		*stacka = tmp2;
	}
	if ((s == 'a' || s == 'b') && (*info)->a == 0)
	{
		if ((*info)->count != 0 && (*info)->v == 0)
			ft_putchar(' ');
		ft_putchar('s');
		ft_putchar(s);
	}
	if (s == 'a')
		ft_bonus(stacka, stackb, info);
	else
		ft_bonus(stackb, stacka, info);
}

void	ft_push(t_swap **stacka, t_swap **stackb, t_info **info, char s)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp = *stackb;
	tmp2 = (*stackb)->next;
	*stackb = tmp2;
	ft_lstadd(stacka, tmp);
	if ((s == 'a' || s == 'b') && (*info)->a == 0)
	{
		if ((*info)->count != 0 && (*info)->v == 0)
			ft_putchar(' ');
		ft_putchar('p');
		ft_putchar(s);
	}
	if (s == 'a')
		ft_bonus(stacka, stackb, info);
	else
		ft_bonus(stackb, stacka, info);
}

void	ft_rotate(t_swap **stacka, t_swap **stackb, t_info **info, char s)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	if ((*stacka)->next != NULL)
	{
		tmp = *stacka;
		tmp2 = (*stacka)->next;
		*stacka = tmp2;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
	if ((s == 'a' || s == 'b') && (*info)->a == 0)
	{
		if ((*info)->count != 0 && (*info)->v == 0)
			ft_putchar(' ');
		ft_putstr("r");
		ft_putchar(s);
	}
	if (s == 'a')
		ft_bonus(stacka, stackb, info);
	else
		ft_bonus(stackb, stacka, info);
}

void	ft_reverse(t_swap **stacka, t_swap **stackb, t_info **info, char s)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp2 = *stacka;
	if (tmp2 != NULL)
	{
		while (tmp2->next != NULL)
		{
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
		tmp->next = NULL;
		tmp2->next = *stacka;
		*stacka = tmp2;
	}
	ft_revhelp(info, s);
	if (s == 'a')
		ft_bonus(stacka, stackb, info);
	else if (s == 'b')
		ft_bonus(stackb, stacka, info);
}

void	ft_revhelp(t_info **info, char s)
{
	if ((s == 'a' || s == 'b') && (*info)->a == 0)
	{
		if ((*info)->count != 0 && (*info)->v == 0)
			ft_putchar(' ');
		ft_putstr("rr");
		ft_putchar(s);
	}
}
