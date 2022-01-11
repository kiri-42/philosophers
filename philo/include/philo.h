/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:37:38 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/11 15:55:22 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR 1

# define TAKEAFORK	"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define DIED		"died"

typedef struct s_options
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_must_eat;
}	t_options;

typedef struct s_management_data
{
	t_options		opts;
	pthread_t		*philo_treads;
	pthread_mutex_t	philo_id_mutex;
	pthread_mutex_t	*fork_mutex;
	int				philo_id;
}	t_management_data;

/* check_arg.c */

void		check_arg(int ac, char **av);

/* set_mdata.c */

void		set_mdata(int ac, char **av, t_management_data *mdata);

/* run_simulation.c */
void		run_simulation(t_management_data *mdata);

/* action_list.c */

void		eat_action(t_management_data *mdata, int philo_id, \
						struct timeval *time);
// void	sleep_action();
// void	think_action();

/* finish_died.c */

void		finish_died(int philo_id);

/* get_ms.c */

long long	get_ms(struct timeval time);

/* finish_error */

void		finish_error(char *error_message);

#endif