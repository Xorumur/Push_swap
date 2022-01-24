/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:24:23 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/24 18:23:34 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	ft_attrib(t_list **sta, int argc, char **argv)
{
	int		i;
	char	**split;

	i = 0;
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
		split = &argv[1];
	*sta = ft_lstnew(ft_atoi(split[i++]));
	while (split[i])
	{
		ft_lstadd_back(sta, ft_lstnew(ft_atoi(split[i])));
		i++;
	}
	return (ft_lstsize(*sta));
}

int	ft_checker(t_list **sta)
{
	int i;
	int j;
	int *log;

	log = stack_log(sta);
	log = ft_bubblesortright(log, ft_lstsize(*sta));
	i = 0;
	j = 0;
	while (i < ft_lstsize(*sta))
	{
		j = i + 1;
		while (j < ft_lstsize(*sta))
		{
			if (log[i] == log[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
