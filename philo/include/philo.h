/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:37:38 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 17:46:31 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libft/libft.h"
# include "color.h"

# define LIFE 0
# define DEATH 1
# define ERROR 1

/* Error message list */
# define ARG_ERROR				"The format of the argument is incorrect"
# define MALLOC_ERROR			"Failed to allocate memory"
# define THREAD_CREATE_ERROR	"Failed to create thread"

/* Log message list */
# define TAKEAFORK_M	"has taken a fork"
# define EATING_M		"is eating"
# define SLEEPING_M		"is sleeping"
# define THINKING_M		"is thinking"
# define DIED_M			"died"

typedef enum e_log_num
{
	TAKEAFORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_log_num;

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

typedef struct s_philo_data
{
	int				philo_id;
	struct timeval	time;
	long long		time_ate;
	bool			is_death;
}	t_philo_data;

typedef struct s_tread_data
{
	pthread_t	*philo_treads;
	pthread_t	*monitor_treads;
	pthread_t	main_monitor_tread;
}	t_tread_data;

typedef struct s_mutex_data
{
	pthread_mutex_t	philo_id_mutex;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	put_log_mutex;
	pthread_mutex_t	death_info_mutex;
}	t_mutex_data;

typedef struct s_philos_data
{
	int				philo_id;
	int				death_flag;
	int				death_time;
	int				*eat_cnt;
}	t_philos_data;

/* Global variables */

t_philos_data	g_philos_data;
t_mutex_data	g_mutex_data;
t_tread_data	g_tread_data;
t_options		g_opts;
t_log_message	g_log_message[5];

/* check_arg.c */

void		check_arg(int ac, char **av);

/* set_mdata.c */

void		set_global_data(int ac, char **av);

/* set_log_message.c */

void		set_log_message(void);

/* run_simulation.c */

void		run_simulation(void);

/* main_monitor_tread.c */

void		*main_monitor(void *arg);

/* philo_tread.c */

void		*philo_action(void *arg);

/* monitor_tread.c */

void		*death_monitor(void *arg);

/* put_log.c */

void		put_log(t_philo_data *philo, int log_num);

/* get_ms.c */

long long	get_ms(struct timeval *time);

/* finish_error.c */

void		finish_error(char *error_message);

#endif