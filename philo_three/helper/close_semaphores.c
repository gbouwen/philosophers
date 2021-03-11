/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_semaphores.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 16:11:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/11 14:01:44 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	close_semaphores(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print_semaphore);
}
