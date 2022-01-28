/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:07:00 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/28 09:23:30 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

void	go_top(t_list **stb, int *log, int len)
{
	t_list	*tmp;
	int		top;
	int		bot;
	int		security;

	top = det_top(stb, log, len);
	bot = (det_bot(stb, log, len) - ft_lstsize(*stb)) * -1;
	security = det_bot(stb, log, len);
	// printf("DET BOT : %i\n", det_bot(stb, log, len));
	// printf("LEN : %i\n", ft_lstsize(*stb));
	tmp = *stb;
	// printf("BOT %i\n", bot);
	// printf("TOP %i\n", top);
	// printf("SEC %i\n", security);
	// printf(" CONTENT TOP : %i\n", get_content(stb, top));
	// ft_afflst(*stb);
	// pr÷intf("%i\n", get_content(stb, security));
	// ft_afflst(*stb);
	if (top <= bot && top != 2147483646)
		send_top_by_rb(stb, get_content(stb, top));
	else if (bot <= top && ft_lstsize(*stb) != 2)
		send_top_by_rrb(stb, get_content(stb, security));
	else if (tmp->content < tmp->next->content)
		ft_rb(ft_lstnew(tmp->content), stb);
}

int	get_content(t_list **stb, int pos)
{
	t_list	*tmp;

	tmp = *stb;
	fill_node(stb);
	while (tmp->pos != pos)
		tmp = tmp->next;
	return (tmp->content);
}

int	ft_det_pos(t_list **stb, int content)
{
	t_list	*tmp;

	tmp = *stb;
	while (tmp->content != content)
		tmp = tmp->next;
	return (tmp->pos);
}
