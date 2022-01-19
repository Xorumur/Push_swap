/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:33:09 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/19 17:54:18 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int ft_det_pos(int content, t_list **stb)
{
	t_list *tmp;
	int i;

	i = 1;
	printf("CONTENT : %i\n", content);
	tmp = *stb;
	while (tmp->next != NULL)
	{
		if (tmp->content == content)
		{
			return (i);
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void ft_apply_rules(int pos, t_list **stb, int len, int content)
{	
	t_list *tmp = NULL;

	if (pos >= len/2)
	{
		while (pos != 1)
		{
			ft_rrb(stb);
			tmp = *stb;
			pos = ft_det_pos(content, stb);
		}
	}
	else if (pos <= len/2)
	{
		tmp = *stb;
		while (pos != 1 && tmp)
		{
			ft_rb(ft_lstnew(tmp->content), stb);
			tmp = *stb;
			// printf("%i\n", tmp->content);
			pos--;
			// printf("POS : %i\n", pos);

		}
	}
}

void ft_push_back(v_list st, t_list **sta, t_list **stb)
{
	t_list	*tmp;
	int	len;
	int pos;

	len = st.lenlog;
	tmp = *stb;
	
	while (tmp && len > 0)
	{
		pos = ft_det_pos(st.log[len - 1], stb);
		ft_apply_rules(pos, stb, ft_lstsize(*stb), st.log[len - 1]);
		len--;
		tmp = *stb;
		ft_pa(ft_lstnew(tmp->content), sta, stb);
	}
}