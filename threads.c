/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:22:40 by icelebi           #+#    #+#             */
/*   Updated: 2023/08/29 20:22:41 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void start_threads(t_table *table)
{
    int i;

	pthread_mutex_init(&table->m_eat_time, NULL);
	pthread_mutex_init(&table->m_last_eat, NULL);
	pthread_mutex_init(&table->is_print, NULL);
	pthread_mutex_init(&table->is_die, NULL);
    i = -1;    
    while(++i < table->nop)
        philo_init(&table->philo[i], table, i);
    i = -1;
    while (++i < table->nop)
        fork_init(&table->philo[i], table, i);
    i = -1;
    while (++i < table->nop)
        pthread_create(&table->philo[i].thread, NULL,
            philo_routine, &table->philo[i]);
    // die_check(table);
}

void end_threads()
{
    
}