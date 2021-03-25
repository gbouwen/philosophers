/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_arguments.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:56:16 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/26 14:24:54 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static void	incorrect_amount_of_arguments(char *arg)
{
	printf("Incorrect amount of arguments. Give arguments like this:\n");
	printf("%s [number_of_philosophers] [time_to_die] [time_to_eat] ", arg);
	printf("[time_to_sleep] [number_of_times_each_philosopher_must_eat ");
	printf("(optional)]\n");
}

int	validate_all_arguments(t_data *data, int ac, char **av)
{
	int	index;

	index = 1;
	if (ac != 5 && ac != 6)
	{
		incorrect_amount_of_arguments(av[0]);
		return (0);
	}
	while (av[index] != NULL)
	{
		if (validate_single_argument(data, av[index], index) == 0)
			return (0);
		index++;
	}
	return (1);
}
