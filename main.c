/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:37:01 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/09 17:01:56 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	*stacka;
	t_swap	*stackb;
	t_info	*info;

	info = ft_init(&stacka, &stackb, argv, argc);
	info->count = 0;
	info->nbr = argc - 1;
	ft_printstack(&stacka, &info);
	ft_push_swap(&stacka, &stackb, &info);
	if (info->c == 1)
	{
		if (info->a == 0)
			ft_putchar('\n');
		ft_putstr("Nombre total de coups : ");
		ft_putnbr(info->count);
		ft_putchar('\n');
	}
	ft_printstack(&stacka, &info);
	return (0);
}
