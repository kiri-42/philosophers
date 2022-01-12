/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:37:38 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/12 00:18:57 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include "color.h"
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR 1

/* log_message_list */
# define TAKEAFORK_M	"has taken a fork"
# define EATING_M		"is eating"
# define SLEEPING_M		"is sleeping"
# define THINKING_M		"is thinking"
# define DIED_M			"died"

typedef enum e_log_list
{
	TAKEAFORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_log_list;

typedef struct s_options
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_must_eat;
}	t_options;

typedef struct s_log_message
{
	char	*color;
	char	*message;
}	t_log_message;

typedef struct s_management_data
{
	t_options		opts;
	pthread_t		*philo_treads;
	pthread_mutex_t	philo_id_mutex;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	put_log_mutex;
	int				philo_id;
	t_log_message	log_message[5];
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
void		sleep_action(t_management_data *mdata, int philo_id, \
						struct timeval *time);
void		think_action(t_management_data *mdata, int philo_id, \
						struct timeval *time);

/* put_log.c */

void		put_log(pthread_mutex_t *put_log_mutex, struct timeval *time, \
					int philo_id, t_log_message *log_message);

/* finish_died.c */

void		finish_died(int philo_id);

/* get_ms.c */

long long	get_ms(struct timeval *time);

/* finish_error */

void		finish_error(char *error_message);

#endif