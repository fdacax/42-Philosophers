/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:49:02 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/11/06 11:52:35 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table table;	

	check(argc, argv);
	init_table(argv, &table);
	init_threads(&table);
	join_threads(&table);
	
	if(argc)
		return 1;
	return (0);
}

//argv[1] = numeros de philo / garfos
//argv[2] = tempo para morrer
//argv[3] = tempo para comer
//argv[4] = tempo para dormir
//argv[5] = quantas refeiçoes no total (opcional)
