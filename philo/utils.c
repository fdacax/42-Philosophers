/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:52:22 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/03 14:52:22 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	neg;
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	neg = 1;
	if (str[i] == 43 || str[i] == 45)
	{
		if	(str[i] == 45)
			neg *= -1;
		i++;
	}
	nbr = 0;
	while (ft_isdigit(str[i]) == 1)
		nbr = nbr * 10 + (str[i++] - 48);
	return (nbr * neg);

}

long	ft_atol(char *str)
{
	long	nbr;
	int		neg;
	int		i;

	i = 0;
	while ((str[i] >= 9 && str[i] <=13) || str[i] == 32)
		i++;
	neg = 1;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg *= -1;
		i++;
	}
	nbr = 0;
	while (ft_isdigit(str[i]) == 1)
		nbr = nbr * 10 + (str[i++] - 48);
	return (nbr * neg);
}
