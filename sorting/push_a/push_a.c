/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:56:46 by mlecherb          #+#    #+#             */
/*   Updated: 2022/02/09 14:45:28 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

int	*log_stb(t_list **stb, int *log)
{
	int		i;
	t_list	*tmp;

	tmp = *stb;
	i = 0;
	log = malloc(sizeof(int) * ft_lstsize(*stb));
	while (i < ft_lstsize(*stb))
	{
		log[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	log = ft_bubblesortright(log, i);
	return (log);
}

void	ft_quick(t_list **sta)
{
	int	*pack;

	pack = NULL;
	pack = det_first_pack(sta, pack);
	det_case(pack, sta);
	free(pack);
}

void	last_two(t_list **stb, t_list **sta)
{
	t_list	*tmp;

	tmp = *stb;
	if (tmp->content < tmp->next->content)
	{
		ft_sb(stb);
		ft_pa(ft_lstnew(tmp->content), sta, stb);
		tmp = *stb;
		ft_pa(ft_lstnew(tmp->content), sta, stb);
		tmp = *stb;
	}
	else
	{
		ft_pa(ft_lstnew(tmp->content), sta, stb);
		tmp = *stb;
		ft_pa(ft_lstnew(tmp->content), sta, stb);
		tmp = *stb;
	}
}
