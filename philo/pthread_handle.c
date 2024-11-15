/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:18:20 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/14 19:18:20 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_handle(t_mtx *mutex, enum e_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
}

void	thread_handle(pthread_t *thread, void *(*f)(void *), void *data,
			enum e_opcode opcode)
{
	if (opcode == CREATE)
		pthread_create(thread, NULL, f, data);
	else if (opcode == JOIN)
		pthread_join(*thread, NULL);
	else if (opcode == DETACH)
		pthread_detach(*thread);
}
