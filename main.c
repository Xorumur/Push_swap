/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:17:22 by mlecherb          #+#    #+#             */
/*   Updated: 2022/02/09 14:44:52 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"
#include "includes/ps.h"

void	helper(t_list **sta, t_list **stb)
{
	t_list	*tmp;
	int		*log;

	log = NULL;
	tmp = NULL;
	if (ft_lstsize(*sta) == 3)
		sizetree(sta);
	if (ft_lstsize(*sta) == 2)
		sizetwo(sta);
	while (*stb && ft_lstsize(*stb) >= 4)
	{
		alpha(sta, stb, log);
		ft_quick(sta);
	}
	free(log);
	if (ft_lstsize(*stb) == 2)
		last_two(stb, sta);
	if (ft_lstsize(*stb) == 1)
	{
		tmp = *stb;
		ft_pa(ft_lstnew(tmp->content), sta, stb);
	}
}

int	check_letter(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 'a' && argv[i][j] <= 'z')
					|| (argv[i][j] >= 'A' && argv[i][j] <= 'Z'))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*sta;
	t_list	*stb;

	sta = NULL;
	stb = NULL;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_attrib(&sta, argc, argv);
	if (ft_checker(&sta) == -1 || check_letter(&argv[1]) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_lstsize(sta) == 3)
		sizetree(&sta);
	while (ft_lstsize(sta) > 3)
		cutting(&sta, &stb);
	helper(&sta, &stb);
	delete_linked_list(&sta);
	delete_linked_list(&stb);
}
	// while (stb && ft_lstsize(stb) >= 4)
	// {
	// 	push_a(&sta, &stb);
	// 	ft_quick(&sta);
	// }
	// if (ft_lstsize(stb) == 2)
	// 	last_two(&stb, &sta);
	// if (ft_lstsize(stb) == 1)
	// 	ft_pa(ft_lstnew(stb->content), &sta, &stb);