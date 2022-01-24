/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:34:06 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 17:14:11 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	ft_utd(t_list **sta)
{
	t_list	*tmp;

	tmp = *sta;
	ft_ra(ft_lstnew(tmp->content), sta);
	tmp = *sta;
	ft_sa(*sta);
	ft_rra(sta);
}

void	ft_dut(t_list **sta)
{
	ft_sa(*sta);
}

void	ft_dtu(t_list **sta)
{
	t_list	*tmp;

	tmp = *sta;
	ft_ra(ft_lstnew(tmp->content), sta);
	tmp = *sta;
	ft_sa(*sta);
	ft_rra(sta);
	tmp = *sta;
	ft_sa(*sta);
}

void	ft_tud(t_list **sta)
{
	t_list	*tmp;

	tmp = *sta;
	ft_sa(*sta);
	ft_ra(ft_lstnew(tmp->content), sta);
	tmp = *sta;
	ft_sa(*sta);
	ft_rra(sta);
}

void	ft_tdu(t_list **sta)
{
	t_list	*tmp;

	tmp = *sta;
	ft_sa(*sta);
	ft_ra(ft_lstnew(tmp->content), sta);
	tmp = *sta;
	ft_sa(*sta);
	ft_rra(sta);
	ft_sa(*sta);
}
