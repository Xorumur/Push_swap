/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:37:19 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 14:28:42 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

/*rotate a - décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.*/
void ft_ra(t_list *new, t_list **sta)
{
	ft_lstdeletefirst(sta);
	ft_lstadd_back(sta, new);
	write(1, "ra\n", 3);
}


/*rotate b - décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.*/
void ft_rb(t_list *new, t_list **stb)
{
	ft_lstdeletefirst(stb);
	ft_lstadd_back(stb, new);
	write(1, "rb\n", 3);
}