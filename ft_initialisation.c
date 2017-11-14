/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:39:16 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/11 13:47:08 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*ft_init(t_swap **stacka, t_swap **stackb, char **tab, int end)
{
	int		i;
	t_swap	*tmp;
	t_info	*info;

	i = 1;
	if (end < 2)
		ft_error(0, &info);
	info = (t_info*)malloc(sizeof(t_info));
	if (!info)
		ft_error(3, &info);
	info = ft_bonusdetector(tab, &i, &info);
	*stacka = (t_swap*)malloc(sizeof(t_swap));
	if (!stacka)
		ft_error(3, &info);
	*stacka = ft_lstnew(ft_atoi(tab[end - 1], &info), &info);
	*stackb = NULL;
	if (end == 2)
		ft_error(0, &info);
	while (i < (end--) - 1)
	{
		tmp = ft_lstnew(ft_atoi(tab[end - 1], &info), &info);
		ft_lstadd(stacka, tmp);
	}
	ft_checknbr(*stacka, &info);
	return (info);
}

void	ft_error(int i, t_info **info)
{
	if (i == 0)
		write(1, "\0", 1);
	else if ((*info)->e == 0)
		write(2, "Error\n", 6);
	else if (i == 1)
		write(2, "Error01\nDucplicated numbers found\n", 34);
	else if (i == 2)
		write(2, "Error02\nInvalid Number!\n", 25);
	else if (i == 3)
		write(2, "Error03\nMalloc Failed\n", 22);
	else if (i == 4)
		write(2, "Error04\nSort Bug\n", 17);
	else if (i == 5)
		write(2, "Error05\nEmpty stack\n", 20);
	else if (i == 6)
		write(2, "Error06\nNumber is not an INT!\n", 30);
	exit(0);
}
