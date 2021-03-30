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
		philo[index].process_id = pid;
		index++;
	}
	return (0);
}

static void	wait_for_children(void)
{
	pid_t	status;

	status = 1;
	while (status > 0)
		status = waitpid(0, NULL, 0);
}

static void	kill_all_children(t_philo *philo)
{
	size_t	index;

	index = 0;
	while (index < philo->data->number_of_philosophers)
	{
		kill(philo[index].process_id, SIGKILL);
		index++;
	}
}

static void	*check_if_dead(void *arg)
{
	t_philo *philo;

	philo = arg;
	sem_wait(philo->data->done_semaphore);
	kill_all_children(philo);
	return (NULL);
}

static void	wait_for_processes(t_data *data, t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, check_if_dead, philo) != 0)
	{
		free(philo);
		return ;
	}
	wait_for_children();
	close_semaphores(data);
	free(philo);
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
	}
}
