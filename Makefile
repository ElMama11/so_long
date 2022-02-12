# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 14:04:53 by mverger           #+#    #+#              #
#    Updated: 2022/02/12 16:56:57 by mverger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
GCCF = gcc -g #-Wall -Werror -Wextra
GREEN       = \033[32m
RED         = \033[31m
DEFAULT     = \033[37m
PATHOBJ = obj/
PATHSRC = src/
INCLUDE_PATH=include
DEP = Makefile src/$(INCLUDE_PATH)/so_long.h
SRC =   main.c \
		parsing.c
		
HEAD = -I ./src/$(INCLUDE_PATH)/ -I libft/
LIBFT = ./libft/libft.a
OBJ = $(patsubst %.c,$(PATHOBJ)/%.o,$(SRC))

ifeq ($(shell uname),Darwin)
    ECHO    = echo
else
	ECHO    = echo
endif

all: $(NAME)

libft: $(LIBFT)

$(PATHOBJ):
	@mkdir -p obj

$(LIBFT):
	@make -C ./libft/

$(NAME): $(DEP) $(LIBFT) $(addprefix $(PATHSRC)/,$(SRC)) $(PATHOBJ) $(OBJ)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.$(DEFAULT)"
	@$(GCCF) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

$(PATHOBJ)/%.o: $(PATHSRC)/%.c
	@$(ECHO) "\r$(GREEN) Compiling $@                      \c\033[K"
	@$(GCCF) -Imlx -c $< -o $@ $(HEAD)

clean:
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@make clean -C ./libft/
	@rm -rf $(PATHOBJ)

fclean: clean
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) is now deleted."
	@make fclean -C ./libft/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re