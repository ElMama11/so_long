# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 14:07:00 by mverger           #+#    #+#              #
#    Updated: 2022/02/20 19:09:24 by mverger          ###   ########.fr        #
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
DEP = Makefile src/$(INCLUDE_PATH)/so_long.h ./libft/libft.a
SRC =	main.c \
		parsing.c \
		display.c \
		display_utils.c \
		action.c \
		pathfinding.c
LIBFT = libft/libft.a
HEAD = -I ./src/$(INCLUDE_PATH)/ -I libft/
OBJ = $(patsubst %.c,$(PATHOBJ)/%.o,$(SRC))
ECHO = echo

all: | libft $(NAME)

libft:
	@make -C libft/

$(PATHOBJ):
	@mkdir -p $(PATHOBJ)

$(NAME): $(PATHOBJ) $(addprefix $(PATHSRC)/,$(SRC)) $(OBJ)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.$(DEFAULT)"
	@$(GCCF) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

$(PATHOBJ)/%.o: $(PATHSRC)/%.c $(DEP)
	@$(ECHO) "\r$(GREEN) Compiling $<                 \c\033[K"
	@$(GCCF) $(HEAD) -Imlx -c $< -o $@

clean:
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@make clean -C ./libft/
	@rm -rf $(PATHOBJ)

fclean: clean
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) is now deleted."
	@make fclean -C ./libft/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft