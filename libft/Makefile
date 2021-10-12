# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshells <cshells@student.21-school>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 22:46:39 by cshells           #+#    #+#              #
#    Updated: 2020/11/04 22:46:43 by cshells          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strnstr.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_strdup.c \
	  ft_calloc.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c

BONUS_SRC =	ft_lstnew.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstiter.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstmap.c

NAME	= libft.a

INCLUDE	= libft.h

CC		= gcc

TAGS	= -Werror -Wextra -Wall

OBJ	= 	$(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJ) $(BONUS_OBJ) libft.h
			ar rc libft.a $(OBJ) $(BONUS_OBJ)

#bonus:		$(BONUS_SRC) $(BONUS_OBJ) libft.h
#			ar rc libft.a $(BONUS_OBJ)

%.o:		%.c Makefile libft.h
			$(CC) $(TAGS) -I $(INCLUDE) -c $<

clean:
			rm -f $(OBJ) $(BONUS_OBJ)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all
