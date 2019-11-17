# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pacovali <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/05 19:50:44 by pacovali       #+#    #+#                 #
#    Updated: 2019/11/17 17:29:04 by jandre-d      ########   odam.nl          #
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
			-pedantic \

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

IMG_DIR=		$(DEP_DIR)/libimg
IMG=			$(IMG_DIR)/libimg.a
IMG_INC=		-I$(IMG_DIR)
$(IMG):
	@$(MAKE) -s -C $(IMG_DIR)

DEPS=			$(PRINTF) \
				$(IMG)

DEP_FLAGS=		\
				-L$(PRINTF_DIR) -lftprintf \
				-L$(IMG_DIR) -limg \
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
				core/container/push_obj \
				core/container/intersect \
				core/container/construct \
				core/renderer/renderer \
				core/renderer/tracer \
				core/renderer/fps \
				core/scene/init \
				ui/window_init \
				ui/app_init \
				ui/app_run \
				ui/keystate \
				ui/text \
				ui/gfx_init \
				ui/prim \
				ui/putpixel \
				algebra/ray/duplicate \
				algebra/ray/make \
				algebra/shapes/quad_equation \
				algebra/shapes/intersect \
				algebra/shapes/cone_intersect \
				algebra/shapes/cube_intersect \
				algebra/shapes/cylinder_intersect \
				algebra/shapes/disk_intersect \
				algebra/shapes/plane_intersect \
				algebra/shapes/pyramid_intersect \
				algebra/shapes/sphere_intersect \
				algebra/shapes/square_intersect \
				algebra/shapes/tetrahedron_intersect \
				algebra/shapes/triangle_intersect \
				algebra/shapes/init \
				algebra/shapes/cone_init \
				algebra/shapes/cube_init \
				algebra/shapes/cylinder_init \
				algebra/shapes/disk_init \
				algebra/shapes/plane_init \
				algebra/shapes/pyramid_init \
				algebra/shapes/sphere_init \
				algebra/shapes/square_init \
				algebra/shapes/tetrahedron_init \
				algebra/shapes/triangle_init \
				algebra/shapes/move \
				algebra/shapes/cone_move \
				algebra/shapes/cube_move \
				algebra/shapes/cylinder_move \
				algebra/shapes/disk_move \
				algebra/shapes/plane_move \
				algebra/shapes/pyramid_move \
				algebra/shapes/sphere_move \
				algebra/shapes/square_move \
				algebra/shapes/tetrahedron_move \
				algebra/shapes/triangle_move \
				algebra/shapes/bbox_construct \
				algebra/shapes/cone_bbox \
				algebra/shapes/cube_bbox \
				algebra/shapes/cylinder_bbox \
				algebra/shapes/disk_bbox \
				algebra/shapes/plane_bbox \
				algebra/shapes/pyramid_bbox \
				algebra/shapes/sphere_bbox \
				algebra/shapes/square_bbox \
				algebra/shapes/tetrahedron_bbox \
				algebra/shapes/triangle_bbox \
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
				algebra/vector/vec_rotate \
				algebra/vector/minmax \
				algebra/vector/to_int \
				algebra/vector/clamp \
				algebra/mmath/min \
				algebra/mmath/max \
				algebra/mmath/clamp \
				algebra/mmath/rand \
				algebra/mmath/vector_randomizer \
				algebra/bbox/center \
				algebra/bbox/merge \
				algebra/bbox/extend \
				algebra/bbox/bounds \
				algebra/bbox/intersect \
				algebra/bbox/debug \
				algebra/bbox/compare_centers \
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
				json/comb \
				json/vec_def \
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
				common/strcmp \
				threadpool/threadpool \
				threadpool/push_work \
				threadpool/worker \
				threadpool/manager \
				threadpool/wait \
				threadpool/free \
				texture/get_texture \
				texture/load_texture_file \
				texture/texture_init \
				texture/uv_texel

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
	@./$(NAME) $(SCENE)
