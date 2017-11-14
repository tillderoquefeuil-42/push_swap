/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:49:24 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/11 13:43:34 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*ft_lstnew(int i, t_info **info)
{
	t_swap	*lst;

	lst = (t_swap*)malloc(sizeof(t_swap));
	if (lst == NULL)
		ft_error(03, info);
	lst->data = i;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd(t_swap **begin, t_swap *new)
{
	new->next = *begin;
	*begin = new;
}

void	ft_lstprint(t_swap *lst)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	if (lst)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			ft_putnbr(tmp2->data);
			if (tmp != NULL)
				ft_putstr(" | ");
		}
	}
	ft_putchar('\n');
}

void	ft_checknbr(t_swap *lst, t_info **info)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp = lst;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->data == tmp2->data)
				ft_error(1, info);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
