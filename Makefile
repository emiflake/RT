# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: emiflake <marvin@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/26 13:08:36 by emiflake       #+#    #+#                 #
#    Updated: 2019/10/26 14:01:47 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#### Imports

include colors.mk

#### Variables

NAME=		RT

CFLAGS=		\
			-Werror -Wall -Wextra \
			-O3 \

CC=			clang

#### Project Structure

# Source code (includes and header files mixed):
# src/
#   */*.{c,h}
SRC_DIR=		./src

STNAMES=		\
				core/main \

# Garbage location
# .obj/
OBJ_DIR=		./.obj

INCLUDES=		$(wildcard $(SRC_DIR)/**/*.h $(SRC_DIR)/*.h)
INCLUDE_FLAG=	-I$(SRC_DIR)

# Where we keep models, scenes, textures
# assets/

#### Rules
ONAMES=	$(patsubst %,$(OBJ_DIR)/%.o, $(STNAMES))

all: $(NAME)

$(NAME): $(INCLUDES) $(ONAMES)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -o $@ $(ONAMES) $(CFLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(TIME) $(CPLUS) $@"
	@mkdir -p $(shell dirname $@)
	@$(CC) -o $@ -c $<

clean:
	@echo "$(TIME) $(CMINUS) $(OBJ_DIR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(NAME)"
	@rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) re

#### Utility rules

dev:
	@$(MAKE) -j10 -s
	@echo "$(CRED) ==> Output:$(CDEF)"
	@./$(NAME)
