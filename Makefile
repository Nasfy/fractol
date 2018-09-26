# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 18:00:41 by abiriuk           #+#    #+#              #
#    Updated: 2018/09/12 18:05:04 by abiriuk          ###   ########.fr        #
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
SRCS=
OBJ=$(SRCS:.c=.o)

MLX=-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: createdir $(NAME)

createdir:
	@mkdir -p obj

$(NAME): $(addprefix $(OBJPATH)/, $(OBJ)) $(LFT)
	$(CC) $(CFLAG) -L$(LFTPATH) -lft $^ -o $@ $(MLX)

$(addprefix $(OBJPATH)/, %.o): $(addprefix $(SRCPATH)/, %.c)
	$(CC) $(CFLAG) -c $< -o $@

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
