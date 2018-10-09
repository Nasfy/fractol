# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 18:00:41 by abiriuk           #+#    #+#              #
#    Updated: 2018/10/09 20:11:24 by abiriuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re $(NAME) $(LFT)

NAME=fractol
CC=gcc
CFLAG=-Wall -Wextra -Werror -I$(LFTPATH) -I/usr/local/include -I./
LFTPATH=libft/
SRCPATH=src
OBJPATH=obj
LFTFILE=libft.a
LFT=$(addprefix $(LFTPATH), $(LFTFILE))
SRCS= exit.c main.c mandelbrot.c window.c color.c move.c mouse_zoom.c julia.c \
	  celtic.c heart.c precision.c
OBJ=$(SRCS:.c=.o)

MLX=-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: createdir $(NAME)

createdir:
	@mkdir -p obj

$(NAME): $(addprefix $(OBJPATH)/, $(OBJ)) $(LFT)
	$(CC) $(CFLAG) -L$(LFTPATH) -lft $^ -o $@ $(MLX)

$(addprefix $(OBJPATH)/, %.o): $(addprefix $(SRCPATH)/, %.c)
	$(CC) $(CFLAG) -c $< -o $@

debug:
	$(CC) $(CFLAG) -L$(LFTPATH) -lft -o $(NAME) src/*.c -g $(MLX)

$(LFT):
	$(MAKE) -C $(LFTPATH)

clean:
	@rm -rf $(OBJPATH)
	$(MAKE) -C $(LFTPATH) clean

fclean:
	@rm -rf $(OBJPATH)
	@rm -f $(NAME)
	$(MAKE) -C $(LFTPATH) fclean

 re: fclean all
