/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:25:56 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/26 12:22:41 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>


// validate_arguments

int		validate_all_arguments(int ac, char **av);
void	incorrect_amount_of_arguments(char *arg);
int		validate_single_argument(char *arg, int index);

// helper

int		ft_atoi(const char *str);

#endif
