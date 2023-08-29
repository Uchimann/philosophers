/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:22:25 by icelebi           #+#    #+#             */
/*   Updated: 2023/08/29 20:22:27 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    
    if(control(ac,av) == 1)
    {   
        t_table *table;   
        table = set_arg( av,ac);  
        printf("obaaaaaaa");
        if (table != NULL && table->nop > 0)
        {
            start_threads(table);
        }
    }
    else
        arg_check(ac);
    
}