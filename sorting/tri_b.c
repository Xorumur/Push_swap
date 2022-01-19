/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:26:37 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/19 14:32:38 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int ft_pos_min(t_list *stb)
{
	t_list *tmp;
	int i;
	int temp;
	int loc;

	loc = 0;
	i = 0;
	tmp = stb;
	if (tmp)
	{
		temp = tmp->content;
		while (tmp->next != NULL)
		{
			if (tmp->content < temp)
			{
				temp = tmp->content;
				loc = i;
			}
			tmp = tmp->next;
			i++;
		}
	}
	return (loc);
}

void	ft_orga(t_list **stb)
{
	t_list	*tmp;
	t_list	*last;

	last = ft_lstlast(*stb);
	tmp = *stb;
	if(ft_lstsize(*stb) == 2)
	{
		if (tmp->content > tmp->next->content)
		{
			ft_rb(ft_lstnew(tmp->content), stb);
		}
	}
	if (ft_pos_min(*stb) > 0 && last->content <= tmp->content)
	{
		ft_rb(ft_lstnew(tmp->content), stb);
		tmp = *stb;
	}
}

void	ft_orga2(t_list **stb, int max)
{
	t_list	*tmp;

	tmp = *stb;
	if (tmp->content > tmp->next->content && tmp->next->content >= max)
		ft_sb(stb);
}

void	ft_sort(t_list **stb)
{
	t_list *tmp;
	int count;

	count = 0;
	tmp = *stb;
	if(stb && ft_lstsize(*stb) >= 2)
	{
		while(tmp->content > tmp->next->content && tmp->next != NULL)
		{
			ft_sb(stb);
			ft_rb(ft_lstnew(tmp->content), stb);
			tmp = *stb;
			count++;
		}
		while (count > 0)
		{
			ft_rrb(stb);
			tmp = *stb;
			ft_rrb(stb);
			tmp = *stb;
			ft_afflst(*stb);
			// ft_sb(*stb);
			count -= 2;
		}
	}
}	
