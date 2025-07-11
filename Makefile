# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 14:42:39 by saibelab          #+#    #+#              #
#    Updated: 2025/07/11 13:20:43 by saibelab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c arg_check.c node_utils.c utils1.c utils2.c basic_sort.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re




# NAME = push_swap

# SRCS = main.c \
# 	arg_check.c \
# 	node_utils.c \
# 	utils1.c \
# 	utils2.c

# INC = push_swap.h

# MAKE = make -s -c
# LIBFT = libft/
# OBJS = $(SRCS:.c=.o)
# CC = cc
# CFLAGS = -Wall -Werror -Wextra -I. -g
# AR = ar rcs
# RM = rm -f
# LIBS = $(LIBFT) libft.a

# all : $(NAME)

# $(NAME) : $(OBJS) $(LIBS)
# 	$(CC) $(CFLAGS) -c -L$(LIBFT) -lft $(NAME)

# %.o: %.c push_swap.h
# 		@$(CC) $(CFLAGS) -c -I$(LIBFT) $< -o $@

# $(LIBFT) : libft.a
# 	$(MAKE) $(LIBFT)

# bonus : $(OBJS)
# 	@$(AR) $(NAME)

# clean :
# 	@$(RM) $(OBJS)
# 	$(MAKE) $(LIBFT) clean

# fclean :
# 	@$(RM) $(NAME) $(OBJS)
# 	$(MAKE) $(LIBFT) fclean

# re : fclean all

# .PHONY : all clean fclean re bonus

