/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:53:32 by eerbek            #+#    #+#             */
/*   Updated: 2023/09/03 17:12:41 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    
    if(control(ac,av) == 1)
    {   
        t_table *table;   
        table = set_arg( av,ac);  
        if (table != NULL && table->nop > 0)
        {
            start_threads(table);
            end_threads(table);
        }
    }
    else
        arg_check(ac);
    printf("oyun bitti");
    
}