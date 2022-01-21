/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:27:13 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/20 17:11:05 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	else
	{
		temp = *alst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void ft_lstdeletelast(t_list *lst) // SUPPRIMER LE PREMIER ET LE DERNIER ?
{
	t_list *del;
	t_list *temp;

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
	t_list *current;
	t_list *next;

	current = *sta;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*sta = NULL;
}