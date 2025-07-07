# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 14:42:39 by saibelab          #+#    #+#              #
#    Updated: 2025/07/02 14:50:51 by saibelab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =

INC = push_swap.h

MAKE = make -s -c
LIBFT = libftfinal/
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -g
AR = ar rcs
RM = rm -f
LIBS = $(LIBFT) libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -c -L$(LIBFT) -lft $(NAME)

%.o: %.c push_swap.h
		@$(CC) $(CFLAGS) -c -I$(LIBFT) $< -o $@

$(LIBFT)libft.a
	$(MAKE) $(LIBFT)

bonus : $(OBJS)
	@$(AR) $(NAME)

clean :
	@$(RM) $(OBJS)
	$(MAKE) $(LIBFT) clean

fclean :
	@$(RM) $(NAME) $(OBJS)
	$(MAKE) $(LIBFT) fclean

re : fclean all

.PHONY : all clean fclean re bonus

