/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:59:49 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/21 15:47:28 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

/*	Avec trois chiffres il existe plusieurs combinaison possible
	on cherche a trouver quelles est la combinaison des chiffres
	pour pouvoir la trier avec le moins de mouvement possibles		*/


void	det_case(int *pack, t_list **sta)
{
	if (case_pack(pack) == 123)	// 1 2 3 
		return ;
	else if (case_pack(pack) == 132)	// 1 3 2 OK
		ft_utd(sta);
	else if (case_pack(pack) == 213)	// 2 1 3 OK
		ft_dut(sta);
	else if (case_pack(pack) == 231)	// 2 3 1 OK
		ft_dtu(sta);
	else if (case_pack(pack) == 312)	// 3 1 2 OK
		ft_tud(sta);
	else if (case_pack(pack) == 321)	// 3 2 1 OK
		ft_tdu(sta);
}



int	*det_first_pack(t_list **sta, int *pack) 
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *sta;
	pack = malloc(sizeof(int) * 3);
	while (i < 3)
	{
		pack[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	return (pack);
}

int	case_pack(int *log)
{
	if (log[0] < log[1] && log[0] < log[2] && log[2] > log[1])
		return (123);
	else if (log[0] < log[1] && log[0] < log[2] && log[2] < log[1])
		return (132);
	else if (log[0] > log[1] && log[0] < log[2] && log[2] > log[1])
		return (213);
	else if (log[0] < log[1] && log[0] > log[2])
		return (231);
	else if (log[0] > log[1] && log[0] > log[2] && log[1] < log[2])
		return (312);
	else if (log[0] > log[1] && log[0] > log[2])
		return (321);
	return (-1);
}
