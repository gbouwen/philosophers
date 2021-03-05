/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy_mutexes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 16:11:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/05 11:51:52 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	destroy_mutexes(t_data *data)
{
	unsigned int	index;

	index = 0;
	while (index < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[index]);
		index++;
	}
}
