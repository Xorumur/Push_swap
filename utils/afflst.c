/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afflst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:43:04 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 17:06:44 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	ft_aff(t_list sta)
{
	int	tmp;

	tmp = sta.content;
	return (tmp);
}

void	ft_afflst(t_list *sta)
{
	t_list	*tmp;

	tmp = sta;
	while (tmp != NULL)
	{
		printf("[%i]\n", ft_aff(*tmp));
		tmp = tmp->next;
	}
	printf("---\n");
}

void	ft_afflog(int *log, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("LOG[%i]\n", log[i]);
		i++;
	}
}
