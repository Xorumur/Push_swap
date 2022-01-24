/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:56:46 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 17:44:09 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

void	push_a(t_list **sta, t_list **stb)
{
	int		*log;
	t_list	*tmp;
	int		len;
	int		checker;

	log = NULL;
	checker = 0;
	tmp = *stb;
	log = log_stb(stb, log);
	len = ft_lstsize(*stb) - 1;
	while (checker != 3 && tmp)
	{
		if (tmp->content <= log[len] && tmp->content >= log[len - 2])
		{
			ft_pa(ft_lstnew(tmp->content), sta, stb);
			checker++;
		}
		else
			go_top(stb, log, len);
		tmp = *stb;
	}
}

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
