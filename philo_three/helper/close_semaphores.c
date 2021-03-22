/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_semaphores.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 16:11:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 18:02:41 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	close_semaphores(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print_semaphore);
	sem_close(data->alive_semaphore);
	sem_close(data->dead_semaphore);
}
