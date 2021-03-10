/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unlink_semaphores.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 16:11:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/10 15:32:42 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	unlink_semaphores(t_data *data)
{
	sem_close(data->forks);
	sem_unlink("/forks");
	sem_close(data->print_semaphore);
	sem_unlink("/print");
}
