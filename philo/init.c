/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:09:29 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/09/23 15:09:29 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_table(char *input[], t_table *table)
{
	table->total_philo = ft_atol(input[1]);
	table->time_to_die = ft_atol(input[2]);
	table->time_to_eat = ft_atol(input[3]);
	table->time_to_sleep = ft_atol(input[4]);
	if (input[5])
		table->total_meals = ft_atol(input[5]);
	else
		table->total_meals = -1;
	table->forks = init_forks(table->total_philo);
	table->philos = init_philos(table);
	thread_handle(table->philos->p_philos, &routine, NULL, CREATE);

}
t_mtx	*init_forks(int total_philos)
{
	t_mtx	*forks;
	int		i;

	forks = calloc(sizeof(t_mtx), total_philos);
	i = -1;
	while (++i < total_philos)
		mutex_handle(&forks[i], INIT);
	return (forks);
}

t_philo	*init_philos(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = calloc(sizeof(t_philo), table->total_philo);
	i = -1;
	while (++i < table->total_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		//philo[i].last_meal = get_time();
		philo[i].last_act = THINK;
		philo[i].table = table;

		philo[i].l_fork = &table->forks[i];
		philo[i].r_fork = &table->forks[(i + i) % table->total_philo];
		if(philo[i].id % 2 == 0)
		{
			philo[i].r_fork = &table->forks[i];
			philo[i].l_fork = &table->forks[(i + i) % table->total_philo];
		}
	}
	return (philo);
}

void	init_threads(t_table *table)
{
	int	i;

	i  = -1;
	while(++i < table->total_philo)
		thread_handle(&table->philos[i].p_philos, routine, &table->philos[i], CREATE);
}

void	join_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->total_philo)
		thread_handle(table->philos[i].p_philos, NULL, NULL, JOIN);
}