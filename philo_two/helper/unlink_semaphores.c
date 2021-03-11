/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unlink_semaphores.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 16:11:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/11 11:32:51 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	unlink_semaphores(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print_semaphore);
}
