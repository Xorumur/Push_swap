/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:26:56 by mlecherb          #+#    #+#             */
/*   Updated: 2022/02/09 14:50:45 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

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
	if (ft_det_pos(stb, content) == ft_lstsize(*stb))
	{
		ft_rrb(stb);
		fill_node(stb);
	}
	else
	{
		while (ft_det_pos(stb, content) != 1)
		{
			ft_rrb(stb);
			tmp = *stb;
			fill_node(stb);
		}
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
