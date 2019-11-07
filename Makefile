# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pacovali <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/05 19:50:44 by pacovali       #+#    #+#                 #
#    Updated: 2019/11/07 16:17:04 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


include colors.mk

#### Variables

NAME=		RT
all: $(NAME)

CFLAGS=		\
			-Werror -Wall -Wextra \
			-O3 \

CC=			clang

EXTRA=	

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

DEP_FLAGS=		\
				-L$(PRINTF_DIR) -lftprintf \
				$(shell sdl2-config --libs) \
				-lSDL2_ttf \

clean_deps:
	@echo "$(TIME) $(CMINUS) Cleaning dependencies"
	@for f in $(DEPS) ; do $(MAKE) fclean -C $$(dirname $$f) ; echo "$(TIME) $(CMINUS) Dependency $$f" ; done

# Source code (includes and header files mixed):
# src/
#   */*.{c,h}
SRC_DIR=		./src

STNAMES=		\
				core/main \
				core/camera/camera \
				ui/window_init \
				ui/app_init \
				ui/app_run \
				ui/keystate \
				ui/text \
				ui/gfx_init \
				ui/fps \
				ui/prim \
				algebra/ray/duplicate \
				algebra/ray/make \
				algebra/shapes/disk_intersect \
				algebra/shapes/intersect \
				algebra/shapes/plane_intersect \
				algebra/shapes/quad_equation \
				algebra/shapes/sphere_intersect \
				algebra/shapes/square_intersect \
				algebra/vector/addition \
				algebra/vector/subtraction \
				algebra/vector/multiplication \
				algebra/vector/dot \
				algebra/vector/normalize \
				algebra/vector/length \
				algebra/vector/distance \
				algebra/vector/constructor \
				algebra/vector/debug \
				algebra/vector/angle \
				algebra/vector/compare \
				algebra/vector/conversion \
				algebra/vector/cross \
				algebra/vector/negate \
				algebra/vector/reflect \
				algebra/vector/reflectance \
				algebra/vector/refract \
				algebra/vector/minmax \
				algebra/mmath/min \
				algebra/mmath/max \
				algebra/mmath/clamp \
				algebra/bbox/center \
				algebra/bbox/merge \
				algebra/bbox/extend \
				json/json \
				json/string \
				json/number \
				json/debug \
				json/list \
				json/dict \
				json/dict_debug \
				json/util \
				json/free \
				json/io \
				json/read_json \
				hashmap/bucket \
				hashmap/clean \
				hashmap/common \
				hashmap/hasher \
				hashmap/hashmap \
				hashmap/iter \
				hashmap/length \
				common/memcpy \
				common/memset \
				common/realloc \

# Garbage location
# .obj/
OBJ_DIR=		./.obj

INCLUDES=		$(wildcard $(SRC_DIR)/**/*.h $(SRC_DIR)/*.h)
INCLUDE_FLAG=	-I$(SRC_DIR) \
				$(PRINTF_INC) \
				-I$(shell brew --prefix)/include \

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
	@$(CC) -o $@ -c $< $(EXTRA) $(CFLAGS) $(INCLUDE_FLAG)

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
