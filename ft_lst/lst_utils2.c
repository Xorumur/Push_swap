/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:27:33 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/20 17:11:09 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	ft_lstdeletefirst(t_list **lst)
{
	t_list *tmp = NULL;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
	tmp = NULL;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}