# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 15:19:14 by tkirihar          #+#    #+#              #
#    Updated: 2022/01/10 17:34:54 by tkirihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo

SRCS = 		srcs/main.c \
			srcs/check_arg.c \
			srcs/set_opts.c \
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