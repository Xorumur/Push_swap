/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:42:12 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/21 16:15:42 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	ft_first_max(t_list **sta, int *log)
{
	t_list	*tmp;

	tmp = *sta;
	while (tmp->next != NULL)
	{
		if (tmp->content > log[1])
			return (tmp->content);
		tmp = tmp->next;
	}
	return (-1);
}

void	cutting(t_list **sta, t_list **stb)
{
	int		*log;
	t_list	*tmp;
	int check;
	int end;

	end = 0;
	check = 1;
	tmp = *sta;
	log = parting(sta);
	while (sta && check != -1)
	{
		if (tmp->content <= log[0])
			bottom_b(sta, stb);
		else if (tmp->content > log[0] && tmp->content <= log[1])
			top_b(sta, stb);
		else if (tmp->content > log[1])
		{	
			check = -1;
			end = tmp->content;
			bottom_a(sta);
		}
		tmp = *sta;	
	}
	assist_cutting(sta, stb, end, log);
}

void	bottom_b(t_list **sta, t_list **stb)
{
	t_list *tmp;

	tmp = *sta;
	ft_pb(ft_lstnew(tmp->content), sta, stb);
	tmp = *stb;
	if (stb)
		ft_rb(ft_lstnew(tmp->content), stb);
}

void	top_b(t_list **sta, t_list **stb)
{
	t_list *tmp;

	tmp = *sta;
	ft_pb(ft_lstnew(tmp->content), sta, stb);
}

void bottom_a(t_list **sta)
{
	t_list *tmp;

	tmp = *sta;
	ft_ra(ft_lstnew(tmp->content), sta);
	ft_afflst(*sta);
}