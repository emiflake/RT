# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nloomans <nloomans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/06 15:11:37 by nloomans       #+#    #+#                 #
#    Updated: 2019/08/22 13:46:36 by nloomans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

all: $(NAME)

##########
# Colors #
##########

OK_COLOR=\033[32;01m
RESET=\033[0m
UNDERLINE=\033[4m
BLUE=\033[36m
RED=\033[31m

###########
# Project #
###########

CC=				gcc
SRC_DIR=		./src
INC_DIR=		./inc
OBJ_DIR=		./.obj
EXTRA=			# Custom CFLAGS added by the user
CFLAGS=			-Werror -Wall -Wextra -O2 $(EXTRA)
IFLAGS=			-I $(INC_DIR) -I .
LFLAGS=

SRC_FILES=		$(wildcard $(SRC_DIR)/*.c)
INC_FILES=		$(wildcard $(INC_DIR)/*.h) ft_printf.h
OBJ_FILES=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(NAME): $(OBJ_FILES)
	@printf " λ Creating archive $(OK_COLOR)$(UNDERLINE)$(NAME)$(RESET)\n"
	@ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@mkdir -p $(OBJ_DIR)
	@printf " λ Making object $(UNDERLINE)$(BLUE)$<$(RESET)\n"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

dev: main.c $(SRC_FILES) $(INC_FILES)
	@printf " λ Everything below will be compiled with debug info\n"
	@$(MAKE) "EXTRA=$(EXTRA) -g"
	@printf " λ Creating binary $(OK_COLOR)$(UNDERLINE)$@$(RESET)\n"
	@$(CC) -Wall -Wextra $(EXTRA) -g -o .obj/main.o -c main.c -I inc
	@$(CC) -Wall -Wextra $(EXTRA) -g -o $@ .obj/main.o -L . -lftprintf

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./dev
	@rm -rf ./dev.dSYM

re:
	@$(MAKE) fclean
	@$(MAKE)

.SECONDARY: $(OBJ_FILES)
.PHONY: \
	all \
	debug \
	clean \
	re \
