/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:33:38 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/15 15:41:56 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	sizetwo(t_list **sta)
{
	t_list	*tmp;

	tmp = *sta;
	if (tmp->content > tmp->next->content)
		ft_sa(*sta);
	else
		return ;
}

void	sizetree(t_list **sta)
{
	int	*pack;

	pack = stack_log(sta);
	if (case_pack(pack) == 123)
		return ;
	else if (case_pack(pack) == 132)
		ft_utd3(sta);
	else if (case_pack(pack) == 213)
		ft_dut3(sta);
	else if (case_pack(pack) == 231)
		ft_dtu3(sta);
	else if (case_pack(pack) == 312)
		ft_tud3(sta);
	else if (case_pack(pack) == 321)
		ft_tdu3(sta);
	free(pack);
}
