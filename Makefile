# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshells <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 18:13:52 by cshells           #+#    #+#              #
#    Updated: 2021/06/07 20:23:53 by cshells          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c \
	ft_parse.c \
	ft_make_struct.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	ft_array_to_list.c \
	ft_cd.c \
	ft_check_redir0.c \
	ft_cut_for_cut.c \
	ft_dollar_question.c \
	ft_down_key.c \
	ft_env.c \
	ft_env_key_length.c \
	ft_echo.c \
	ft_edit_env.c \
	ft_error.c \
	ft_execute.c \
	ft_exit.c \
	ft_exit_signal_key.c \
	ft_export.c \
	ft_export_identifier_validation.c \
	ft_export_output.c \
	ft_find_env_key.c \
	ft_free_double_array.c \
	ft_free_structs.c \
	ft_get_env.c \
	ft_increase_shlvl.c \
	ft_is_special.c \
	ft_list_to_array.c \
	ft_make_logname.c \
	ft_minibender_preparations.c \
	ft_oldpwd_update.c \
	ft_pipe.c \
	ft_pipe_mem_cleaner.c \
	ft_print_cycle.c \
	ft_pwd.c \
	ft_pwd_update.c \
	ft_quotes.c \
	ft_quotes_utils.c \
	ft_redirect.c \
	ft_redirections.c \
	ft_run_binary.c \
	ft_run_command.c \
	ft_run_special.c \
	ft_separators.c \
	ft_signal_handler.c \
	ft_signal_init.c \
	ft_sort_array.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strlen_to_char.c \
	ft_unset.c \
	ft_doll_que.c \
	ft_dollar_utils.c \

SRC_LIB = libft/*.c

OBJ = $(SRC:.c=.o)

TAGS = -Wall -Wextra -Werror

TERM = -ltermcap

CC = gcc -g

RM = rm -rf

LIBFT_PATH  = libft

LIBFT       = libft.a

LIBS = libft/libft.a

all:	$(NAME)

$(NAME): $(SRC) $(LIBS) $(OBJ) shell.h
	$(CC) $(TAGS) $(LIBS) $(TERM) $(OBJ) -o $(NAME)

$(LIBS): $(SRC_LIB)
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
