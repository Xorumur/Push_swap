/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:50:16 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 17:21:09 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

/*reverse rotate a - décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.*/
void	ft_rra(t_list **sta)
{
	t_list	*new;

	new = ft_lstnew(ft_lstlast(*sta)->content);
	ft_lstdeletelast(*sta);
	ft_lstadd_front(sta, new);
	write(1, "rra\n", 4);
}

/*reverse rotate b - décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.*/
void	ft_rrb(t_list **stb)
{
	t_list	*new;

	new = ft_lstnew(ft_lstlast(*stb)->content);
	ft_lstdeletelast(*stb);
	ft_lstadd_front(stb, new);
	write(1, "rrb\n", 4);
}
