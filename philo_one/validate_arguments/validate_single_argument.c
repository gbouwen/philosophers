/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_single_argument.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 12:16:44 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/26 12:49:31 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static void	correct_error_message(int index)
{
	if (index == 1)
		printf("[number_of_philosophers] ");
	else if (index == 2)
		printf("[time_to_die] ");
	else if (index == 3)
		printf("[time_to_eat] ");
	else if (index == 4)
		printf("[time_to_sleep] ");
	else if (index == 5)
		printf("[number_of_times_each_philosopher_must_eat] ");
	printf("is not a numeric value\n");
}

int	validate_single_argument(char *arg, int index)
{
	int	value;

	value = ft_atoi(arg);
	if (value == 0)
	{
		correct_error_message(index);
		return (0);
	}
	return (1);
}
