/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:27:33 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 17:25:48 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	ft_lstdeletefirst(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
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

void	ft_lstdeletelast(t_list *lst)
{
	t_list	*del;
	t_list	*temp;

	temp = lst;
	if (temp && temp->next && !temp->next->next)
	{
		del = temp->next;
		free(del);
	}
	else
		while (temp->next->next != NULL)
			temp = temp->next;
	del = temp->next;
	free(del);
	temp->next = NULL;
}

void	delete_linked_list(t_list **sta)
{
	t_list	*current;
	t_list	*next;

	current = *sta;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*sta = NULL;
}
