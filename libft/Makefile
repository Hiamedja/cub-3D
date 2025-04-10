# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 04:31:19 by nerrakeb          #+#    #+#              #
#    Updated: 2023/11/28 04:31:29 by nerrakeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBFT.SRC = ft_atoi.c ft_bzero.c ft_putchar.c ft_putstr.c ft_isalnum.c ft_isalpha.c \
            ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c  \
			ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_split.c ft_strchr.c\
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_error.c \
			ft_strlen.c ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c  \
			ft_strtrim.c ft_strcat.c ft_strcpy.c ft_substr.c ft_tolower.c ft_toupper.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(LIBFT.SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

$(OBJ) : $(LIBFT.SRC)
	$(CC) $(CFLAGS) -c $(LIBFT.SRC)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re