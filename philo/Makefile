# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 15:19:14 by tkirihar          #+#    #+#              #
#    Updated: 2022/01/13 21:16:45 by tkirihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			philo

SRCS = 			srcs/main.c \
				srcs/check_arg.c \
				srcs/set_global_data.c \
				srcs/set_log_message.c \
				srcs/run_simulation.c \
				srcs/main_death_monitor.c \
				srcs/philo_action.c \
				srcs/death_monitor.c \
				srcs/put_log.c \
				srcs/get_ms.c \
				srcs/finish_error.c

OBJS = 			$(SRCS:.c=.o)

LIBPHILO_DIR = 	libphilo

LIBPHILO_LIB = 	libphilo/libphilo.a

CC =			gcc

RM =			rm -f

CFLAGS =		-Wall -Wextra -Werror

.PHONY: all re clean fclean

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBPHILO_LIB)
				$(CC) $^ -o $@

$(LIBPHILO_LIB):
				make -C $(@D)

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

re:
				make fclean
				make

clean:
				$(RM) $(OBJS)
				make -C $(LIBPHILO_DIR) clean

fclean:			clean
				$(RM) $(NAME)
				make -C $(LIBPHILO_DIR) fclean