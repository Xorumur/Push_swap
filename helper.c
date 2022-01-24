/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:30:31 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 17:36:16 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

void	eco_space(t_list *stb, t_list *sta, int *log)
{
	if (ft_lstsize(sta) == 3)
		sizetree(&sta);
	while (ft_lstsize(sta) > 4)
		cutting(&sta, &stb);
	log = parting(&sta);
	if (ft_lstsize(sta) == 2)
		sizetwo(&sta);
	while (stb && ft_lstsize(stb) >= 4)
	{
		push_a(&sta, &stb);
		ft_quick(&sta);
	}
	if (ft_lstsize(stb) == 2)
		last_two(&stb, &sta);
	if (ft_lstsize(stb) == 1)
		ft_pa(ft_lstnew(stb->content), &sta, &stb);
}
