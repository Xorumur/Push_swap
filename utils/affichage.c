/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:23:32 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 11:33:53 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int		ft_aff(t_list sta)
{
	int tmp;
	
	tmp = sta.content;
	return (tmp);
}

void	ft_afflst(t_list *sta)
{
	t_list *tmp;

	tmp = sta;
	while (tmp != NULL)
	{
		printf("[%i]\n", ft_aff(*tmp));
		tmp = tmp->next;
	}
	printf("---\n");
}