/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:23:33 by mlecherb          #+#    #+#             */
/*   Updated: 2022/02/09 14:48:50 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

void	to_top(t_list **stb, int min, int max)
{
	int		pos;
	t_list	*tmp;

	tmp = *stb;
	pos = found_node(stb, min, max);
	if (bot_or_top(stb, pos) == 0)
		send_top_by_rb(stb, get_content(stb, pos));
	else
		send_top_by_rrb(stb, get_content(stb, pos));
}

void	alpha(t_list **sta, t_list **stb, int *log)
{
	t_list	*tmp;
	int		len;
	int		pushed;

	pushed = 0;
	tmp = *stb;
	log = log_stb(stb, log);
	len = ft_lstsize(*stb) - 1;
	while (pushed < 3)
	{
		if (ft_det_pos(stb, log[len]) == 1 || ft_det_pos(stb, log[len - 1]) == 1
			|| ft_det_pos(stb, log[len - 2]) == 1)
		{
			ft_pa(ft_lstnew(tmp->content), sta, stb);
			pushed++;
		}
		else
			to_top(stb, log[len -2], log[len]);
		tmp = *stb;
	}
	free(log);
}
