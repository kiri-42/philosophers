# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 15:19:14 by tkirihar          #+#    #+#              #
#    Updated: 2022/01/19 18:24:43 by tkirihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			philo

SRCS = 			srcs/main.c \
				srcs/check_arg.c \
				srcs/check_int.c \
				srcs/set_mdata.c \
				srcs/ft_atoi.c \
				srcs/set_log_message.c \
				srcs/run_simulation.c \
				srcs/main_monitor.c \
				srcs/philo_action.c \
				srcs/death_monitor.c \
				srcs/put_log.c \
				srcs/get_ms.c \
				srcs/finish_error.c \
				srcs/free.c \
				srcs/ft_isspace.c

OBJS = 			$(SRCS:.c=.o)

CC =			gcc

RM =			rm -f

CFLAGS =		-Wall -Wextra -Werror

.PHONY: all re clean fclean

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $^ -o $@

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

re:
				make fclean
				make

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)