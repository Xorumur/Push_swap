/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:50:33 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/19 17:53:57 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void fill_node(t_list **stb)
{
	int	i;
	t_list *tmp;

	tmp = *stb;
	i = 1;
	while (tmp->next != NULL)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

void	send_top_by_rb(t_list **stb, int content)
{
	t_list *tmp;

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
	t_list *tmp;

	tmp = *stb;
	while (ft_det_pos(stb, content) != 1)
	{
		ft_rrb(stb);
		tmp = *stb;
		fill_node(stb);
	}
}

int	ft_det_pos(t_list **stb, int content)
{
	t_list	*tmp;

	tmp = *stb;
	while (tmp->content != content)
		tmp = tmp->next;
	return (tmp->pos);
}

void	ft_pushback(t_list **sta, t_list **stb, v_list st)
{
	t_list *tmp;
	int len;

	len = st.lenlog - 1;
	tmp = *stb;
	while (stb && ft_lstsize(*stb) > 2)
	{
		if (ft_det_pos(stb ,st.log[len]) >= (ft_lstsize(*stb)/2))
			send_top_by_rrb(stb, st.log[len]);
		else if (ft_det_pos(stb ,st.log[len]) <= (ft_lstsize(*stb)/2))
			send_top_by_rb(stb, st.log[len]);
		tmp = *stb;
		ft_pa(ft_lstnew(tmp->content), sta, stb);
		len--;
	}
	ft_afflst(*sta);
	ft_afflst(*stb);
	// while (stb && ft_lstsize(*stb) > 2) // Changer le copilateur aime pas trop la 
	// {
	// 	while (ft_det_pos(stb, st.log[len]) != 1)
	// 	{
	// 		ft_rb(ft_lstnew(tmp->content), stb);
	// 		tmp = *stb;
	// 		fill_node(stb);
	// 		len--;
	// 		ft_afflst(*sta);
	// 	}
	// 	ft_pa(ft_lstnew(tmp->content), sta, stb);
	// }
	tmp = *stb;
	if (tmp->content > tmp->next->content)
	{
		ft_pa(ft_lstnew(tmp->content), sta, stb);
		tmp = *stb;
		ft_pa(ft_lstnew(tmp->content), sta, stb);
	}
	else
	{
		ft_rb(ft_lstnew(tmp->content), stb);
		tmp = *stb;
		ft_pa(ft_lstnew(tmp->content), sta, stb);
		tmp = *stb;
		ft_pa(ft_lstnew(tmp->content), sta, stb);
	}
}