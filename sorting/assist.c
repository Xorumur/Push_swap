/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:26:14 by mlecherb          #+#    #+#             */
/*   Updated: 2022/02/08 15:39:51 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	assist_cutting(t_list **sta, t_list **stb, int end, int *log)
{
	t_list	*tmp;

	tmp = *sta;
	while (tmp->content != end)
	{
		if (tmp->content <= log[0])
			bottom_b(sta, stb);
		else if (tmp->content > log[0] && tmp->content <= log[1])
			top_b(sta, stb);
		else if (tmp->content > log[1])
			bottom_a(sta);
		tmp = *sta;
	}
	free(log);
}

void	last_four(t_list **stb)
{
	t_list	*tmp;
	int		min;

	tmp = *stb;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	put_min_bot(stb, min);
}

void	put_min_bot(t_list **stb, int min)
{
	t_list	*tmp;

	tmp = *stb;
	while (tmp->content != min)
	{
		ft_rb(ft_lstnew(tmp->content), stb);
		tmp = *stb;
	}
	ft_rb(ft_lstnew(tmp->content), stb);
}

void	push_elem(t_list **sta, t_list **stb)
{
	t_list	*tmp;

	tmp = *stb;
	ft_pa(ft_lstnew(tmp->content), sta, stb);
	tmp = *stb;
	tmp = *stb;
	ft_pa(ft_lstnew(tmp->content), sta, stb);
	tmp = *stb;
	ft_pa(ft_lstnew(tmp->content), sta, stb);
}
