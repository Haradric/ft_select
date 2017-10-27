#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 16:59:45 by mbraslav          #+#    #+#              #
#    Updated: 2017/04/10 16:59:46 by mbraslav         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE =	main.c\
			ft_select.c\
			redraw.c\
			color.c\
			key.c\
			signal.c\
			error.c
OBJECT =	$(SOURCE:.c=.o)
NAME =		ft_select
LIBFT =		./libft/libft.a

all: $(NAME)

$(NAME): $(OBJECT) $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) -ltermcap -o $@ $(OBJECT)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT):
	make -C libft

clean:
	make clean -C ./libft
	rm -f $(OBJECT)

fclean:
	make fclean -C ./libft
	rm -f $(OBJECT)
	rm -f $(NAME)

re: fclean all
