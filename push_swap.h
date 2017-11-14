/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:35:06 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/11 13:43:49 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_swap
{
	int				data;
	struct s_swap	*next;
}					t_swap;

typedef struct		s_info
{
	int				count;
	int				v;
	int				c;
	int				a;
	int				f;
	int				e;
	int				nbr;
	int				rot;
	int				min;
}					t_info;

t_info				*ft_init(t_swap **stacka, t_swap **stackb,
						char **tab, int end);
void				ft_error(int i, t_info **info);
t_info				*ft_bonusdetector(char **tab, int *i,
						t_info **info);
t_swap				*ft_lstnew(int i, t_info **info);
void				ft_lstadd(t_swap **begin, t_swap *new);
void				ft_lstprint(t_swap *lst);
void				ft_checknbr(t_swap *lst, t_info **info);
int					ft_atoi(const char *str, t_info **info);
void				ft_putchar(char c);
void				ft_putnbr(long int n);
void				ft_putstr(char const *s);
int					ft_issort(t_swap **begin, char ordre);
void				ft_push_swap(t_swap **stacka, t_swap **stackb,
						t_info **info);
void				ft_oneswap(t_swap **stacka, t_swap **stackb,
						t_info **info);
int					ft_oneswapspl(t_swap **stacka, int *c);
void				ft_middlealgo(t_swap **stacka, t_swap **stackb,
						t_info **info);
void				ft_middlealgoret(t_swap **stackb, t_swap **stacka,
						t_info **info);
void				ft_swap(t_swap **stacka, t_swap **stackb,
						t_info **info, char s);
void				ft_push(t_swap **stacka, t_swap **stackb,
						t_info **info, char s);
void				ft_rotate(t_swap **stacka, t_swap **stackb,
						t_info **info, char s);
void				ft_reverse(t_swap **stacka, t_swap **stackb,
						t_info **info, char s);
void				ft_swapdbl(t_swap **stacka, t_swap **stackb,
						t_info **info);
void				ft_rotatedbl(t_swap **stacka, t_swap **stackb,
						t_info **info);
void				ft_reversedbl(t_swap **stacka, t_swap **stackb,
						t_info **info);
void				ft_bonus(t_swap **stacka, t_swap **stackb,
						t_info **info);
void				ft_bigalgotry(t_swap **stacka, t_swap **stackb,
						t_info **info);
int					ft_pivotfinal(t_swap **stacka, int *nbr, t_info **info);
int					ft_pivotmax(t_swap **stacka, int *nbr, t_info **info);
int					ft_pivotmin(t_swap **stacka, int *nbr, t_info **info);
void				ft_revhelp(t_info **info, char s);
void				ft_bigalgoret(t_swap **stacka, t_swap **stackb,
						t_info **info);
void				ft_printstack(t_swap **stacka, t_info **info);

#endif
