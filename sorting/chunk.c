/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:57:43 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 14:12:00 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void ft_chunker(v_list *st, t_list *sta, int len)
{
	st->log = ft_register(sta, st, len);
	st->l1 = st->log[0];
	st->l2 = st->log[st->len/5];
	st->l3 = st->log[(2 * st->len)/5];
	st->l4 = st->log[(3 * st->len)/5];
	st->l5 = st->log[(4 * st->len)/5];
	st->l6 = st->log[st->len - 1];
}

void ft_affst(v_list st)
{
	int	i;

	i = 0;
	printf("Len :[%i]\n", st.len);
	printf("l1 :[%i]\n", st.l1);
	printf("l2 :[%i]\n", st.l2);
	printf("l3 :[%i]\n", st.l3);
	printf("l4 :[%i]\n", st.l4);
	printf("l5 :[%i]\n", st.l5);
	printf("l6 :[%i]\n", st.l6);
	while (i < st.len)
		printf("{LOG[i]} :[%i]\n", st.log[i++]);
}