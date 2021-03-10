/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_arguments.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:56:16 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/10 14:43:33 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

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
