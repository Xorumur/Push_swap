/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:13:22 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 17:16:10 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

/* Permet de creer les limites pour push */
/* Limites peuvent etre mis a jour en reexcecutant parting */

int	*stack_log(t_list **sta)
{
	t_list	*tmp;
	int		*log;
	int		i;

	i = 0;
	log = malloc(sizeof(int) * ft_lstsize(*sta));
	tmp = *sta;
	while (i < ft_lstsize(*sta))
	{
		log[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	return (log);
}

int	*ft_bubblesortright(int *log, int len)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
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

int	*parting(t_list **sta)
{
	int	size;
	int	*part;
	int	*log;
	int	i;

	i = 0;
	part = malloc(sizeof(int) * 2);
	log = stack_log(sta);
	while (i < ft_lstsize(*sta))
	{
		i++;
	}
	size = ft_lstsize(*sta);
	log = ft_bubblesortright(log, size);
	part[0] = log[size / 3];
	part[1] = log[2 * size / 3];
	return (part);
}
