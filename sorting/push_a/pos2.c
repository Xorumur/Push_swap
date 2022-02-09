/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:07:00 by mlecherb          #+#    #+#             */
/*   Updated: 2022/02/09 14:50:54 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

int	get_content(t_list **stb, int pos)
{
	t_list	*tmp;

	tmp = *stb;
	fill_node(stb);
	while (tmp->pos != pos && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->content);
}

int	ft_det_pos(t_list **stb, int content)
{
	t_list	*tmp;

	tmp = *stb;
	if (does_exist(stb, content) == 1)
	{
		while (tmp->content != content)
			tmp = tmp->next;
		return (tmp->pos);
	}
	else
		return (0);
}
