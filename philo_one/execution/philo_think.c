/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_think.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:08:31 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/09 16:02:36 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	philo_think(t_philo *philo)
{
	print_message(philo->data, THINKING, philo->id);
}
