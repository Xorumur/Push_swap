/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:26:56 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 18:20:27 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

int	det_top(t_list **stb, int *log, int len)
{
	t_list	*tmp;
	int		mid;
	int		i;

	i = 0;
	mid = ft_lstsize(*stb) / 2;
	tmp = *stb;
	fill_node(stb);
	while (i < mid)
	{
		if (tmp->content >= log[len - 2] && tmp->content <= log[len])
			return (tmp->pos);
		tmp = tmp->next;
		i++;
	}
	return (2147483646);
}

int	det_bot(t_list **stb, int *log, int len)
{
	t_list	*tmp;
	int		i;

	i = -10;
	tmp = *stb;
	fill_node(stb);
	while (tmp)
	{
		if (tmp->content >= log[len - 2] && tmp->content <= log[len])
			i = tmp->pos;
		tmp = tmp->next;
	}
	return (i);
}

void	send_top_by_rb(t_list **stb, int content)
{
	t_list	*tmp;

	tmp = *stb;
	while (ft_det_pos(stb, content) != 1)
	{
		ft_rb(ft_lstnew(tmp->content), stb);
		tmp = *stb;
		fill_node(stb);
	}
}

void	send_top_by_rrb(t_list **stb, int content)
{
	t_list	*tmp;

	tmp = *stb;
	while (ft_det_pos(stb, content) != 1)
	{
		ft_rrb(stb);
		tmp = *stb;
		fill_node(stb);
	}
}

void	fill_node(t_list **stb)
{
	int		i;
	t_list	*tmp;

	tmp = *stb;
	i = 1;
	while (tmp->next != NULL)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}
