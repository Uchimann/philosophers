/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:54:30 by eerbek            #+#    #+#             */
/*   Updated: 2023/09/03 16:56:12 by icelebi          ###   ########.fr       */
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
    pthread_mutex_init(&table->m_stop,NULL);

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
    die_check(table);
}

int	check_die(t_table *table, int i)
{
	while (table->nop > 0)
	{
		i = -1;
		while (++i < table->nop)
		{
			pthread_mutex_lock(&table->m_last_eat);
			pthread_mutex_lock(&table->is_die);
			if ((current_time() - table->philo[i].last_eat) >= table->death_time)
			{
				//print(&table->philos[i], DIE);
                printf("%llu idli filö öldü",table->philo[i].id);
				pthread_mutex_lock(&table->m_stop);
				table->stop = 1;
				pthread_mutex_unlock(&table->m_stop);
				pthread_mutex_unlock(&table->m_last_eat);
				return (0);
			}
			else
				pthread_mutex_unlock(&table->m_last_eat);
			pthread_mutex_unlock(&table->is_die);
		}
		// if (must_eating_check(table))
        //     break ;
	}
	return (1);
}

void die_check(t_table *table)
{
	int	i;

	i = -1;
	if (!(check_die(table, i)))
		return ;
    pthread_mutex_lock(&table->m_stop);
	table->stop = 1;
	pthread_mutex_unlock(&table->m_stop);
}

void end_threads(t_table *table)
{
    int	i;

	i = -1;
	while (++i < table->nop)
	{
		if (table->nop == 1)
			pthread_detach(table->philo[i].thread);
		pthread_join(table->philo[i].thread, NULL);
	}
	pthread_mutex_destroy(&table->m_stop);
	pthread_mutex_destroy(&table->philo[i].m_eat_count);
	pthread_mutex_destroy(&table->m_last_eat);
	pthread_mutex_destroy(&table->is_die);
	pthread_mutex_destroy(&table->is_print);
	i = 0;
    while (i < table->nop)
		pthread_mutex_destroy(&table->forks[i++]);
	free (table->forks);
	free (table->philo);
	free (table);
	
}