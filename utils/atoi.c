/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:19:53 by mlecherb          #+#    #+#             */
/*   Updated: 2022/01/18 11:20:55 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_iswspace(char c)
{
	while (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t				index;
	int					negative;
	unsigned long int	result;

	index = 0;
	negative = 1;
	result = 0;
	while (ft_iswspace(str[index]) == 1)
		index++;
	if (str[index] == '+' || str[index] == '-')
		if (str[index++] == '-')
			negative *= -1;
	while (ft_isdigit(str[index]))
	{
		result *= 10;
		result += str[index] - '0';
		index++;
	}
	return (result * negative);
}
