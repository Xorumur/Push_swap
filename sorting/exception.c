/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:33:38 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/21 15:52:42 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void sizetwo(t_list **sta)
{
	t_list *tmp;

	tmp = *sta;
	if (tmp->content > tmp->next->content)
		ft_sa(*sta);
	else 
		return ;
}

void sizetree(t_list **sta)
{
	int *pack;

	pack = stack_log(sta);
	if (case_pack(pack) == 123)	// 1 2 3 
		return ;
	else if (case_pack(pack) == 132)	// 1 3 2 OK
		ft_utd3(sta);
	else if (case_pack(pack) == 213)	// 2 1 3 OK
		ft_dut3(sta);
	else if (case_pack(pack) == 231)	// 2 3 1 OK
		ft_dtu3(sta);
	else if (case_pack(pack) == 312)	// 3 1 2 OK
		ft_tud3(sta);
	else if (case_pack(pack) == 321)	// 3 2 1 OK
		ft_tdu3(sta);
}