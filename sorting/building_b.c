/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:28:34 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/19 14:45:42 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int ft_pos_first_chunk(t_list *sta, int max, int min)
{
	t_list *tmp;
	int i;
	int len;

	len = ft_lstsize(sta);
	i = 1;
	tmp = sta;
	while (tmp && i <= len/2)
	{
		if (tmp->content <= max && tmp-> content >= min)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int ft_pos_last_chunk(t_list *sta, int max, int min)
{
	t_list *tmp;
	int		i;
	int loc;
	int	len;

	len = ft_lstsize(sta);
	loc = -1;
	i = 1;
	tmp = sta;
	while (tmp && i <= len/2)
	{
		tmp = tmp->next;
		i++;
	}
	while (tmp->next != NULL)
	{
		if (tmp->content <= max && tmp->content >= min)
		{
			loc = i;
		}
		i++;
		tmp = tmp->next;
	}
	return(loc);
}

void ft_build(t_list **sta, v_list st, int max, int min)
{
	t_list	*tmp;
	int		hold_first;
	int 	hold_second;
	int		i;
	int		cond;
	i = 0;
	tmp = *sta;
	hold_first = ft_pos_first_chunk(*sta, max, min);
	hold_second = ((ft_pos_last_chunk(*sta, max, min) - st.len) * -1);
	cond = ft_pos_last_chunk(*sta, max, min);
	if (hold_first > hold_second && cond != -1)
	{
		while (i <= hold_second)
		{
			ft_rra(sta);
			tmp = *sta;
			i++;
		}
	}
	else if (hold_first <= hold_second && hold_first != -1)
	{
		while (i < hold_first - 1)
		{
			ft_ra(ft_lstnew(tmp->content), sta);
			i++;
			tmp = *sta;
		}
	}
}

int ft_elvalidator(t_list *sta, int max, int min, v_list st)
{
	t_list *tmp;

	tmp = sta;
	while (tmp->next != NULL)
	{
		if (tmp->content > min && tmp->content <= max)
			return (1);
		if (tmp->content == st.l1)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}
