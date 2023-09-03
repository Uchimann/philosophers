/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:18:15 by eerbek            #+#    #+#             */
/*   Updated: 2023/08/31 12:17:09 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void arg_check()
{
    printf("eksik veya fazla arguman girildi,incorrect");
}

int num_cont(int ac, char **av)
{
   int i = 1;
   int j;
    while(i < ac)
    {
        j = 0;
        while(av[i][j])
        {
            if(av[i][j] <= 57 && av[i][j] >= 48)
                j++;
            else
                return 0;
        }
        i++;
    }
    return 1;
}

int ft_p_atoi(char *s)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    if (s[i] <= 32)
        i++;
    if (s[i] == '-')
    {
        i++;
        sign *= -1;
    }
    else if (s[i] == '+')
        i++;
    while (s[i])
        res = (res * 10) + s[i++] - 48;
    return (res * sign);
}

