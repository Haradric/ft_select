#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 12:07:16 by mbraslav          #+#    #+#              #
#    Updated: 2016/11/26 12:07:21 by mbraslav         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCE =	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_strnequ.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_nbrlen.c\
		ft_strtolower.c\
		ft_strtoupper.c\
		ft_lstlen.c\
		ft_lstswap.c\
		ft_lstinsertelem.c\
		ft_lstremoveelem.c\
		ft_lstsort.c\
		ft_lstrsort.c\
		ft_lstfreelist.c\
		ft_lstfreeelem.c\
		ft_lstpushback.c\
		ft_lstpushfront.c\
		ft_lstgetelem.c\
		ft_lstgetlast.c\
		ft_lstisinlist.c\
		ft_lstdup.c\
		ft_lstdupelem.c\
		ft_lstfind.c\
		ft_isspace.c\
		ft_realloc.c\
		ft_wchartochar.c\
		ft_wcharlen.c\
		ft_power.c\
		./ft_printf/ft_printf.c\
		./ft_printf/read_modifiers.c\
		./ft_printf/read_modifiers2.c\
		./ft_printf/read_arguments.c\
		./ft_printf/read_arguments2.c\
		./ft_printf/clean_description.c\
		./ft_printf/processing.c\
		./ft_printf/processing_percent.c\
		./ft_printf/processing_x.c\
		./ft_printf/processing_s.c\
		./ft_printf/processing_ls.c\
		./ft_printf/processing_c.c\
		./ft_printf/processing_o.c\
		./ft_printf/processing_di.c\
		./ft_printf/processing_u.c\
		./ft_printf/processing_p.c\
		./ft_printf/wchar.c\
		./ft_printf/useful_things.c 
OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all
