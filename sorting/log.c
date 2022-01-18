/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:44:14 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 14:14:23 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	*ft_register(t_list *sta, v_list *st, int len)
{
	t_list	*tmp;
	int	i;
	
	i = 0;
	tmp = sta;
	st->log = malloc(sizeof(int) * len);
	while (tmp != NULL)
	{
		st->log[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	st->log = ft_bubblesortright(st->log, len);
	return (st->log);
}

int	*ft_bubblesortright(int *log, int len)
{
	int	i;
	int j;
	int	tmp;
	
	tmp = 0;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len && tmp != log[i])
		{
			if (log[i] > log[j])
			{
				tmp = log[i];
				log[i] = log[j];
				log[j] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (log);
}