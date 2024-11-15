/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:27:28 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/03 14:27:28 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check(int argc, char *input[])
{
	int		i;
	int		j;
	

	if (argc != 5 && argc != 6)
		p_error("Invalid number of arguments!");
	i = 1;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (ft_isdigit(input[i][j]) != 1)
				p_error("Just numbers are accepted!");
			j++;
		}
		if (ft_atoi(input[i]) != ft_atol(input[i]) || ft_atoi(input[i]) <= 0)
			p_error("Invalid number!");
		i++;
	}
}

void	p_error(char *str)
{
	printf("Error:\n%s\n", str);
	exit (1);
}
