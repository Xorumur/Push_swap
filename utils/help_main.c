/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:24:23 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 11:39:39 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int ft_attrib(t_list **sta, int argc, char **argv)
{
	int i;
	char **split;
	
	i = 0;
	if (argc == 2) // S'il s'agit d'une string : "5 1 2 3"
		split = ft_split(argv[1], ' '); 
	else
		split = &argv[1]; // SAUTE LE PREMIER ARGUMENT (./a.out)
	*sta = ft_lstnew(ft_atoi(split[i++]));
	while (split[i])
	{
		ft_lstadd_back(sta, ft_lstnew(ft_atoi(split[i])));
		i++;
	}
	return (ft_lstsize(*sta));
}