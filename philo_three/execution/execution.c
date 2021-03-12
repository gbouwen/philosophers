/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:36:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/12 12:12:24 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

static void	create_processes(t_data *data, t_philo *philo)
{
	size_t	index;
	pid_t	pid;

	index = 0;
	pid = 0;
	while (index < data->number_of_philosophers)
	{
		pid = fork();
		if (pid == 0)
			philosopher(&philo[index]);
		index++;
	}
}

static void	wait_for_processes(void)
{
	pid_t	status;

	status = 1;
	while (status > 0)
		status = waitpid(0, NULL, 0);
}

int	execution(t_data *data, t_philo *philo)
{
	create_processes(data, philo);
	wait_for_processes();
	close_semaphores(data);
	free(philo);
	return (1);
}
