# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 18:42:08 by rafilipe          #+#    #+#              #
#    Updated: 2023/07/27 16:48:16 by rafilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		= 	srcs/aux.c \
				srcs/checkers.c \
				srcs/debug_fts.c \
				srcs/error.c \
				srcs/images.c \
				srcs/main.c \
				srcs/map_setup.c \
				srcs/moves.c \
				srcs/window.c \

OBJS		= $(SRCS:%.c=%.o)

LIBFTA		= ./libft/libft.a

MLX		= ./mlx/libmlx.a

RM		= rm -f

CC		= cc -Wall -Wextra -Werror #-g -fsanitize=address

MLX_FLAGS	= -lXext -lX11 -lm -lz

.c.o:
			$(CC) -c $< -o $@

all:		$(NAME)

$(NAME): 	 $(MLX) $(LIBFTA) $(OBJS)
			$(CC) $(OBJS) $(MLX) $(LIBFTA) $(MLX_FLAGS) -o $(NAME)
			@echo "$(GREEN)Successfully built --> $(YELLOW)$(NAME)$(DEFAULT)"

$(MLX):
			@make -C mlx

$(LIBFTA):
			@make -C libft

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make -C libft fclean
			make -C mlx clean
			@echo "$(RED)Files Removed!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean re fclean