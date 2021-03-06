/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:24:23 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/28 12:19:32 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static void	free_tab(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	ft_attrib(t_list **sta, int argc, char **argv)
{
	int				i;
	char			**split;
	long long int	nb;

	i = 0;
	if (argc == 1)
		return (-1);
	else if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
		split = &argv[1];
	nb = ft_atoi(split[i++]);
	if (nb > INT_MAX || nb < INT_MIN)
		return (-1);
	*sta = ft_lstnew(nb);
	while (split[i])
	{
		nb = ft_atoi(split[i++]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (-1);
		ft_lstadd_back(sta, ft_lstnew(nb));
	}
	if (argc == 2)
		free_tab(split);
	return (0);
}

int	ft_checker(t_list **sta)
{
	int	i;
	int	j;
	int	*log;

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
			{
				free(log);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free(log);
	return (0);
}
