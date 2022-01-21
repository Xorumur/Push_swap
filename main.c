/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:17:22 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/21 17:04:22 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"
#include "includes/ps.h"

int	main(int argc, char **argv)
{
	t_list	*sta = NULL;
	t_list	*stb = NULL;
	int i;
	int *log;

	i = 0;
	ft_attrib(&sta, argc, argv);
	// det_case(pack);
	// while (i < 3)
	// {
	// 	printf("[%i]\n", pack[i]);
	// 	i++;
	// }
	// printf("%i\n", find_mmm(pack));
	if (ft_lstsize(sta) == 3)
		sizetree(&sta);
	ft_afflst(sta);
	while (ft_lstsize(sta) > 3)
	{
		cutting(&sta, &stb);
		ft_afflst(sta);
		ft_afflst(stb);
		printf("AHAH");
	}
	log = parting(&sta);
	printf("part[%i]\n", log[0]);
	printf("part[%i]\n", log[1]);
	if (ft_lstsize(sta) == 2)
		sizetwo(&sta);
	while (stb && ft_lstsize(stb) > 4)	
	{
		push_a(&sta, &stb);
		ft_quick(&sta);
	}
	ft_afflst(stb);
	if (ft_lstsize(stb) == 4)
	{
		last_four(&stb);
		ft_afflst(stb);
		push_elem(&sta, &stb);
		
	}
	if (ft_lstsize(stb) == 2)
	 	last_two(&stb, &sta);
	if (ft_lstsize(stb) == 1)
		ft_pa(ft_lstnew(stb->content), &sta, &stb);
	
	ft_afflst(stb);
	ft_afflst(sta);

}