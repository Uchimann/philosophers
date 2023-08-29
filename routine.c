/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:22:36 by icelebi           #+#    #+#             */
/*   Updated: 2023/08/29 20:22:37 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_eating(t_philo *philo, uint64_t id, int nop)
{
    pthread_mutex_lock(philo->lfork);
    printf("%llu idli filo catali aldi\n",id);
    pthread_mutex_lock(philo->rfork);
    printf("%llu idli filo catali aldi\n",id);
    printf("%llu idli filo yiyor ac köpke\n",id);
    pthread_mutex_unlock(philo->lfork);
    pthread_mutex_unlock(philo->rfork);
}

void    *philo_routine(void *id_philo) //threadların ilk göz açtığı yer
{
    t_philo *philo;
    
    philo = (t_philo *)id_philo;
    if (philo->id % 2 == 0)
        usleep(100);
    while(1)
    {
        philo_eating(philo, philo->id, philo->table->nop);
    }
    return 0;
}