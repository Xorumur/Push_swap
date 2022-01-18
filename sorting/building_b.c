/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:28:34 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 16:01:54 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int ft_pos_first_chunk(v_list st, t_list *sta)
{
	t_list *tmp;
	int i;

	i = 1;
	tmp = sta;
	while (tmp && i <= st.len/5)
	{
		if (tmp->content <= st.l2)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int ft_pos_last_chunk(v_list st, t_list *sta)
{
	t_list *tmp;
	int		i;

	i = 1;
	tmp = sta;
	while (tmp && i < (4 * st.len)/5)
	{
		tmp = tmp->next;
		i++;
	}
	while (tmp->next != NULL)
	{
		if (tmp->content <= st.l2)
		{
			return (i);
		}
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

void ft_build(t_list **sta, v_list st)
{
	t_list	*tmp;
	int		hold_first;
	int 	hold_second;
	int		i;

	i = 0;
	tmp = *sta;
	hold_first = ft_pos_first_chunk(st, *sta);
	hold_second = ((ft_pos_last_chunk(st, *sta) - st.len) * -1);
	if (hold_first > hold_second)
	{
		while (i <= hold_second)
		{
			ft_rra(sta);
			tmp = *sta;
			i++;
		}
	}
	else if (hold_first <= hold_second)
	{
		while (i < hold_first - 1)
		{
			ft_ra(ft_lstnew(tmp->content), sta);
			i++;
			tmp = *sta;
		}
	}
}

int ft_elvalidator(t_list *sta, int max)
{
	t_list *tmp;

	tmp = sta;
	while (tmp->next != NULL)
	{
		if (tmp->content <= max)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}
