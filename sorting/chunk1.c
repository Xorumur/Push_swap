/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CHunk1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:51:35 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/19 16:06:55 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	ft_cone(v_list st, t_list **sta, t_list **stb)
{
	t_list *last = NULL;
	t_list *tmp;

	tmp = *stb;
	while (ft_elvalidator(*sta, st.l2, st.l1, st) == 1) // PROBLEME
	{
		ft_build(sta, st, st.l2, st.l1);
		ft_orga(stb);
		tmp = *sta;
		ft_pb(ft_lstnew(tmp->content), sta, stb);
		tmp = *stb;
		last = ft_lstlast(*stb);
		if (tmp && ft_lstsize(*stb) >= 2 && tmp->content > tmp->next->content && last->content > tmp->content)
			ft_sb(stb);
	}
}

void	ft_ctwo(v_list st, t_list **sta, t_list **stb)
{
	t_list	*tmp;

	tmp = *stb;
	while (ft_elvalidator(*sta, st.l3, st.l2, st) == 1)
	{
		ft_build(sta, st, st.l3, st.l2); // A refaire
		ft_orga2(stb, st.l3);
		tmp = *sta;
		ft_pb(ft_lstnew(tmp->content), sta, stb);
	}
}

void	ft_ctree(v_list st, t_list **sta, t_list **stb)
{
	t_list	*tmp;

	tmp = *stb;
	while (ft_elvalidator(*sta, st.l4, st.l3, st) == 1)
	{
		ft_build(sta, st, st.l4, st.l3); // A refaire
		ft_orga2(stb, st.l4);
		tmp = *sta;
		ft_pb(ft_lstnew(tmp->content), sta, stb);
	}
}
void	ft_cfour(v_list st, t_list **sta, t_list **stb)
{
	t_list	*tmp;

	tmp = *stb;
	while (ft_elvalidator(*sta, st.l5, st.l4, st) == 1)
	{
		ft_build(sta, st, st.l5, st.l4); // A refaire
		ft_orga2(stb, st.l5);
		tmp = *sta;
		ft_pb(ft_lstnew(tmp->content), sta, stb);
	}	
}
void	ft_cfive(v_list st, t_list **sta, t_list **stb)
{
	t_list	*tmp;

	tmp = *stb;
	while (ft_elvalidator(*sta, st.l6, st.l5, st) == 1)
	{
		ft_build(sta, st, st.l6, st.l5);
		ft_orga2(stb, st.l5);
		tmp = *sta;
		ft_pb(ft_lstnew(tmp->content), sta, stb);
	}
	tmp = *sta;
	if (ft_lstsize(*sta) == 1)
	{
		ft_pb(ft_lstnew(tmp->content), sta, stb);
	}
}