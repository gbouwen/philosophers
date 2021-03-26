/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:36:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/12 16:19:24 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

static int	create_processes(t_data *data, t_philo *philo)
{
	size_t	index;
	pid_t	pid;

	index = 0;
	pid = 0;
	while (index < data->number_of_philosophers)
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			philosopher(&philo[index]);
			exit(0);
		}
		data->process_id[index] = pid;
		index++;
	}
	return (0);
}

static void	*wait_for_children(void *arg)
{
	pid_t	status;

	(void)arg;
	status = 1;
	while (status > 0)
		status = waitpid(0, NULL, 0);
	return (NULL);
}

static void	kill_all_children(t_data *data)
{
	size_t	index;

	index = 0;
	while (index < data->number_of_philosophers)
	{
		kill(data->process_id[index], SIGKILL);
		index++;
	}
}

static void	wait_for_processes(t_data *data, t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, wait_for_children, NULL) != 0)
	{
		free(philo);
		free(data->process_id);
		return ;
	}
	sem_wait(data->done_semaphore);
	close_semaphores(data);
	free(philo);
	kill_all_children(data);
	free(data->process_id);
	pthread_join(thread, NULL);
}

void	execution(t_data *data, t_philo *philo)
{
	if (create_processes(data, philo) == 0)
		wait_for_processes(data, philo);
	else
	{
		close_semaphores(data);
		free(philo);
		free(data->process_id);
	}
}
