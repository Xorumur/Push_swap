/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:30:41 by mlecherb          #+#    #+#             */
/*   Updated: 2022/02/09 14:50:16 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

int	bot_or_top(t_list **stb, int pos)
{
	if (pos < ft_lstsize(*stb) / 2)
		return (0);
	else
		return (1);
}

int	nb_mv(t_list **stb, int pos)
{
	int	len;

	len = ft_lstsize(*stb);
	if (bot_or_top(stb, pos) == 0)
		return (pos);
	else if (bot_or_top(stb, pos) == 1)
		return (len - pos + 1);
	return (0);
}

int	found_node(t_list **stb, int min, int max)
{
	t_list	*tmp;
	int		temp;

	temp = -1;
	tmp = *stb;
	while (tmp->next != NULL)
	{
		if (tmp->content <= max && tmp->content >= min)
		{
			if (temp == -1)
				temp = tmp->pos;
			else if (nb_mv(stb, tmp->pos) < nb_mv(stb, temp))
				temp = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (temp);
}

int	does_exist(t_list **stb, int content)
{
	t_list	*tmp;

	tmp = *stb;
	while (tmp->next != NULL)
	{
		if (tmp->content == content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
