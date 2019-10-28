# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/26 16:28:41 by nmartins       #+#    #+#                 #
#    Updated: 2019/10/28 14:16:37 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#### Imports

include colors.mk

#### Variables

NAME=		RT
all: $(NAME)

CFLAGS=		\
			-Werror -Wall -Wextra \
			-O3 \

CC=			clang

#### Project Structure

# Dependencies
# deps/
DEP_DIR=		./deps

PRINTF_DIR=		$(DEP_DIR)/libftprintf
PRINTF=			$(PRINTF_DIR)/libftprintf.a
PRINTF_INC=		-I$(PRINTF_DIR)
$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)

DEPS=			$(PRINTF)

DEP_FLAGS=		-L$(PRINTF_DIR) -lftprintf

clean_deps:
	@echo "$(TIME) $(CMINUS) Cleaning dependencies"
	@for f in $(DEPS) ; do $(MAKE) fclean -C $$(dirname $$f) ; echo "$(TIME) $(CMINUS) Dependency $$f" ; done

# Source code (includes and header files mixed):
# src/
#   */*.{c,h}
SRC_DIR=		./src

STNAMES=		\
				core/main \
				algebra/vector/addition \
				algebra/vector/subtraction \
				algebra/vector/multiplication \
				algebra/vector/dot \
				algebra/vector/normalize \
				algebra/vector/length \
				algebra/vector/distance \
				algebra/vector/constructor \
				algebra/vector/debug \

# Garbage location
# .obj/
OBJ_DIR=		./.obj

INCLUDES=		$(wildcard $(SRC_DIR)/**/*.h $(SRC_DIR)/*.h)
INCLUDE_FLAG=	-I$(SRC_DIR) $(PRINTF_INC)

# Where we keep models, scenes, textures
# assets/

#### Rules
ONAMES=	$(patsubst %,$(OBJ_DIR)/%.o, $(STNAMES))

$(NAME): $(ONAMES)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -o $@ $(ONAMES) $(CFLAGS) $(DEP_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS) $(INCLUDES) 
	@echo "$(TIME) $(CPLUS) $@"
	@mkdir -p $(shell dirname $@)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE_FLAG)

clean: clean_deps
	@echo "$(TIME) $(CMINUS) $(OBJ_DIR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(NAME)"
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

#### Utility rules

dev:
	@$(MAKE) -j10 -s
	@echo "$(TIME) $(CNORM) $(CRED)Running $(CCYAN)$(NAME)$(CDEF)"
	@./$(NAME)
