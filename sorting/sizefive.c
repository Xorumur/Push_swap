/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizefive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:17:46 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/15 15:42:37 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	send_top_by_ra(t_list **sta, int content)
{
	t_list	*tmp;

	tmp = *sta;
	while (ft_det_pos(sta, content) != 1)
	{
		ft_ra(ft_lstnew(tmp->content), sta);
		tmp = *sta;
		fill_node(sta);
	}
}

void	send_top_by_rra(t_list **sta, int content)
{
	t_list	*tmp;

	tmp = *sta;
	fill_node(sta);
	if (ft_det_pos(sta, content) == ft_lstsize(*sta))
	{
		ft_rrb(sta);
		fill_node(sta);
	}
	else
	{
		while (ft_det_pos(sta, content) != 1)
		{
			ft_rra(sta);
			tmp = *sta;
			fill_node(sta);
		}
	}
}

void	push_min(t_list **sta, t_list **stb)
{
	t_list	*tmp;
	int		*log;

	log = NULL;
	log = log_stb(sta, log);
	tmp = *sta;
	fill_node(sta);
	if (bot_or_top(sta, ft_det_pos(sta, log[0])) == 0)
		send_top_by_ra(sta, log[0]);
	else if (bot_or_top(sta, ft_det_pos(sta, log[0])) == 1)
		send_top_by_rra(sta, log[0]);
	tmp = *sta;
	ft_pb(ft_lstnew(tmp->content), sta, stb);
	free(log);
}

void	sizefive(t_list **sta, t_list **stb)
{
	t_list	*tmp;

	tmp = *sta;
	push_min(sta, stb);
	push_min(sta, stb);
	sizetree(sta);
	tmp = *stb;
	ft_pa(ft_lstnew(tmp->content), sta, stb);
	tmp = *stb;
	ft_pa(ft_lstnew(tmp->content), sta, stb);
	delete_linked_list(sta);
	delete_linked_list(stb);
}
