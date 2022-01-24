/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizetree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:43:24 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 17:13:34 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	ft_utd3(t_list **sta)
{
	t_list	*tmp;

	tmp = *sta;
	ft_sa(*sta);
	ft_ra(ft_lstnew(tmp->content), sta);
}

void	ft_dut3(t_list **sta)
{
	ft_sa(*sta);
}

void	ft_dtu3(t_list **sta)
{
	t_list	*tmp;

	tmp = *sta;
	ft_rra(sta);
}

void	ft_tud3(t_list **sta)
{
	t_list	*tmp;

	tmp = *sta;
	ft_ra(ft_lstnew(tmp->content), sta);
}

void	ft_tdu3(t_list **sta)
{
	t_list	*tmp;

	tmp = *sta;
	ft_sa(*sta);
	ft_rra(sta);
}
