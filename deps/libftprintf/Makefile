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

SRC_FILES=		./src/fmt_color.c \
./src/fmt_ntoa.c \
./src/fmt_padding.c \
./src/fmt_printmemory.c \
./src/fmt_putflt.c \
./src/fmt_puthex.c \
./src/fmt_putnbr.c \
./src/fmt_putoct.c \
./src/fmt_putpercent.c \
./src/fmt_putptr.c \
./src/fmt_putstr.c \
./src/fmt_putuns.c \
./src/fmt_read.c \
./src/fmt_utils.c \
./src/ft_dprintf.c \
./src/ft_fprintf.c \
./src/ft_printf.c \
./src/ft_sprintf.c \
./src/parse_utils.c \
./src/parser.c \
./src/parser_checkers.c \
./src/parser_segments.c \
./src/runner.c \
./src/std_memory.c \
./src/std_misc.c \
./src/std_string.c \
./src/writer.c \
./src/writer_utils.c
INC_FILES=		./inc/color.h \
./inc/fmt.h \
./inc/number.h \
./inc/parser.h \
./inc/std.h \
./inc/token.h \
./inc/writer.h ft_printf.h
OBJ_FILES=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(NAME): $(OBJ_FILES)
	@printf " λ Creating archive $(OK_COLOR)$(UNDERLINE)$(NAME)$(RESET)\n"
	@ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@mkdir -p $(OBJ_DIR)
	@printf " λ Making object $(UNDERLINE)$(BLUE)$<$(RESET)\n"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.SECONDARY: $(OBJ_FILES)
.PHONY: \
	all \
	debug \
	clean \
	re \
