/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:49:15 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/03 13:49:15 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

typedef pthread_mutex_t t_mtx;
typedef struct s_info	t_table;
typedef struct s_philo	t_philo;

enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
};

enum e_act
{
	EAT,
	SLEEP,
	THINK,
};

typedef struct  s_philo
{
	long		id;
	long		meals;
	long		last_meal;
	t_mtx		*r_fork;
	t_mtx		*l_fork;
	t_table		*table;
	pthread_t	p_philos;
	enum e_act	last_act;
	
}	t_philo;

typedef struct s_info
{
	long		total_philo;
	long		total_meals;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		time_to_think;

	t_mtx		*forks;
	t_philo		*philos;
	
}	t_table;


/* ************************************************************************** */
/*                                 philo                                      */
/* ************************************************************************** */

void		p_error(char *str);
void		check(int argc, char *input[]);

int			ft_isdigit(int c);
int			ft_atoi(char *str);
long		ft_atol(char *str);

void		mutex_handle(t_mtx *mutex, enum e_opcode opcode);
void		thread_handle(pthread_t *thread, void *(*f)(void *), void *data, enum e_opcode opcode);

/* ************************************************************************** */
/*                                 init                                      */
/* ************************************************************************** */

void		init_table(char *input[], t_table *data);
t_philo		*init_philos(t_table *table);
t_mtx		*init_forks(int total_philos);
void		init_threads(t_table *table);
void		join_threads(t_table *table);

/* ************************************************************************** */
/*                                routine                                     */
/* ************************************************************************** */

void		*routine(void *data);

# endif