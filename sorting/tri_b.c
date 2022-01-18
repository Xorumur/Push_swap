/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:26:37 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 15:53:52 by mlecherb         ###   ########.fr       */
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
	t_list *tmp;

	tmp = *stb;
	while (ft_pos_min(*stb) > 0)
	{
		ft_rb(ft_lstnew(tmp->content), stb);
		tmp = *stb;
	}
}
