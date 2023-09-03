/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:18:08 by eerbek            #+#    #+#             */
/*   Updated: 2023/08/30 15:33:30 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

uint64_t	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		//error();
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

uint64_t	time_from_start(t_table *table)
{
	return (current_time() - table->time);
}

void	time_usleep(uint16_t micsec)
{
	uint64_t	current;

	current = current_time();
	while (1)
	{
		if (current_time() - current >= micsec)
			break ;
		usleep(100);
	}
}