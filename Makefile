# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 10:38:52 by rbarbazz          #+#    #+#              #
#    Updated: 2018/06/14 14:17:31 by rbarbazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC_PATH = src

SRC_NAME = core/main.c core/read_split_exec.c core/get_env.c core/binaries.c\
		   core/clear.c core/prompt.c core/tools.c \
		   core/signal.c core/signal_set.c core/error.c\
		   parser/tilde.c parser/parser.c\
		   cli/cli.c cli/cursor_motion.c cli/backspace.c\
		   builtin/builtin.c builtin/echo.c builtin/cd/cd.c builtin/cd/cd_env.c\
		   builtin/env/env.c builtin/env/setenv.c builtin/env/unsetenv.c\
		   builtin/env/mkenv.c builtin/exit.c\
		   term/term_commands.c term/term_init.c term/term_settings.c

OBJ_PATH = obj

CPPFLAGS = -Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft

LIB = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = clang

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LIB) -ltermcap -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p obj/core obj/parser obj/cli obj/term obj/builtin/cd obj/builtin/env
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

norme:
	norminette $(SRC)
	norminette include/*.h
	norminette libft/src
	norminette libft/include

clean:
	make -C libft clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
