/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:17:41 by eerbek            #+#    #+#             */
/*   Updated: 2023/09/03 17:00:42 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_eating(t_philo *philo)
{
    if (philo->eat_count == philo->table->must_eat_count)
        return ;
    pthread_mutex_lock(philo->rfork);
    printf("%llu idli filo catali aldi\n",philo->id);
    pthread_mutex_lock(philo->lfork);
    printf("%llu idli filo catali aldi\n",philo->id);
    printf("%llu idli filo yiyor ac köpke\n",philo->id);
    pthread_mutex_lock(&philo->m_eat_count);
    philo->eat_count++;
    pthread_mutex_unlock(&philo->m_eat_count);
    time_usleep(philo->table->eat_time);
    pthread_mutex_lock(&philo->table->m_last_eat);
    philo->last_eat = current_time();
    pthread_mutex_unlock(&philo->table->m_last_eat);
    pthread_mutex_unlock(philo->rfork);
    pthread_mutex_unlock(philo->lfork);
}

void    philo_sleeping(t_philo *philo)
{
    time_usleep(philo->table->sleep_time);
    printf("%llu idli filo osurtarak uyuyor\n",philo->id);
}

void philo_thinking(t_philo *philo)
{
    printf("%llu idli filo hayatı sorgıluyo\n",philo->id);
}

void    *philo_routine(void *id_philo) //threadların ilk göz açtığı yer
{
    t_philo *philo;
    
    int stop;
    philo = (t_philo *)id_philo;
    if (philo->id % 2 == 0)
        time_usleep(10);
    while(1)
    {
        pthread_mutex_lock(&philo->table->m_stop);
		stop = philo->table->stop;
		pthread_mutex_unlock(&philo->table->m_stop);
        if(stop == 1)
            break ;
        philo_eating(philo);
        philo_sleeping(philo);
        philo_thinking(philo);
    }
    return NULL;
}
