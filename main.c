/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:17:22 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/28 09:24:31 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"
#include "includes/ps.h"

int	main(int argc, char **argv)
{
	t_list	*sta;
	t_list	*stb;

	sta = NULL;
	stb = NULL;
	ft_attrib(&sta, argc, argv);
	// eco_space(stb, sta, log);
	// delete_linked_list(&sta);
	// delete_linked_list(&stb);
	if (ft_checker(&sta) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_lstsize(sta) == 3)
		sizetree(&sta);
	while (ft_lstsize(sta) > 3)
		cutting(&sta, &stb);
	// ft_afflst(sta);
	if (ft_lstsize(sta) == 3)
		sizetree(&sta);
	if (ft_lstsize(sta) == 2)
		sizetwo(&sta);
	while (stb && ft_lstsize(stb) >= 4)
	{
		push_a(&sta, &stb);
		ft_quick(&sta);
	}
	// ft_afflst(stb);
	if (ft_lstsize(stb) == 2)
		last_two(&stb, &sta);
	if (ft_lstsize(stb) == 1)
		ft_pa(ft_lstnew(stb->content), &sta, &stb);
	// ft_afflst(sta);
}
