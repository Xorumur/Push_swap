/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:04:46 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 17:20:33 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

/*swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
rien s’il n’y en a qu’un ou aucun.*/
void	ft_sa(t_list *sta)
{
	int	temp;

	if (!sta || !sta->next)
		return ;
	temp = sta->content;
	sta->content = sta->next->content;
	sta->next->content = temp;
	write(1, "sa\n", 3);
}

/*swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait
rien s’il n’y en a qu’un ou aucun.*/
void	ft_sb(t_list **stb)
{
	int	temp;

	temp = (*stb)->content;
	(*stb)->content = (*stb)->next->content;
	(*stb)->next->content = temp;
	write(1, "sb\n", 3);
}
