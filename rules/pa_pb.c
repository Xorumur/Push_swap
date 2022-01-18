/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:36:59 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 14:28:45 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"


/*push a - prend le premier élément au sommet de b et le met sur a. Ne fait
rien si b est vide.*/
void ft_pa(t_list *new, t_list **sta, t_list **stb)
{
	ft_lstadd_front(sta, new);
	ft_lstdeletefirst(stb);
	write(1, "pa\n", 3);
}


/*push b - prend le premier élément au sommet de a et le met sur b. Ne fait
rien si a est vide.*/
void ft_pb(t_list *new, t_list **sta, t_list **stb)
{
	ft_lstadd_front(stb, new);
	ft_lstdeletefirst(sta);
	write(1, "pb\n", 3);
}