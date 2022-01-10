# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 15:19:14 by tkirihar          #+#    #+#              #
#    Updated: 2022/01/11 01:45:30 by tkirihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo

SRCS = 		srcs/main.c \
			srcs/check_arg.c \
			srcs/set_mdata.c \
			srcs/run_simulation.c \
			srcs/finish_died.c \
			srcs/get_ms.c \
			srcs/finish_error.c

OBJS = 		$(SRCS:.c=.o)

FT_DIR = 	libft

FT_LIB = 	libft/libft.a

CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

.PHONY: all re clean fclean

all:		$(NAME)

$(NAME):	$(OBJS) $(FT_LIB)
			$(CC) $^ $(OPT) -o $@

$(FT_LIB):
			make -C $(@D)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

re:
			make fclean
			make

clean:
			$(RM) $(OBJS)
			make -C $(FT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(FT_DIR) fclean