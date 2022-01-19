/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:14:39 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/19 17:19:41 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

// Faire un checker des nombres entre en parametre

int	main(int argc, char **argv)
{
	t_list	*sta = NULL;
	t_list	*stb = NULL;
	v_list 	st;
	int len;
	int i;

	i = 0;
	st.len = ft_attrib(&sta, argc, argv);
	ft_chunker(&st, sta, st.len);
	printf("A");
	ft_cone(st, &sta, &stb);
	ft_ctwo(st, &sta, &stb);
	ft_ctree(st, &sta, &stb);
	ft_cfour(st, &sta, &stb);
	ft_cfive(st, &sta, &stb);
	len = st.lenlog;
	// while (i < len)
	// {
	// 	printf("[%i]\n",st.log[i]);
	// 	i++;
	// }
	// ft_afflst(stb);
	ft_pushback(&sta, &stb, st);
	ft_afflst(sta);
}