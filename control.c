/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:47:10 by eerbek            #+#    #+#             */
/*   Updated: 2023/08/31 12:17:05 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

t_table *set_arg(char **arg, int ac)
{
    t_table *table;
    
    table = malloc(sizeof(t_table));
    if(!table)
        return NULL;
    table->nop = ft_p_atoi(arg[1]);
    table->death_time = ft_p_atoi(arg[2]);
    table->eat_time = ft_p_atoi(arg[3]);
    table->sleep_time = ft_p_atoi(arg[4]);
    if(ac == 6)
        table->must_eat_count = ft_p_atoi(arg[5]);
    table->must_eat_count = -1;
    table->philo = malloc(sizeof(t_philo) * table->nop);
    table->forks = malloc(sizeof(int)* table->nop);
    table->time = current_time();
    table->stop = 0;
    return table;
}

int control(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {
        if(num_cont(ac,av) == 1)
            return 1;
        else
            return 0;
    }
    else
        return 0;

}

