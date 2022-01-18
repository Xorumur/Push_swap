/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:14:39 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 16:01:56 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

int	main(int argc, char **argv)
{
	t_list	*sta = NULL;
	t_list	*stb = NULL;
	v_list 	st;
	t_list *tmp;

	tmp = sta;
	st.len = ft_attrib(&sta, argc, argv);
	ft_chunker(&st, sta, st.len);
	while (ft_elvalidator(sta, st.l2) == 1) // PROBLEME
	{
		ft_build(&sta, st);
		ft_afflst(stb);
		ft_orga(&stb); //Des fois ne place pas le plus petit en haut
		ft_pb(ft_lstnew(sta->content), &sta, &stb);
		ft_afflst(stb);
	}
	ft_orga(&stb);
	ft_afflst(stb);
}