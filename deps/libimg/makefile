# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/19 14:57:29 by jandre-d       #+#    #+#                 #
#    Updated: 2019/11/17 17:02:40 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DIR_SRC = src/
DIR_INCLUDES = includes/

NAME = libimg.a

FILES = \
img_clear \
img_destroy \
img_flip_horizontal \
img_flip_vertical \
img_get_pixel \
img_new \
img_set_pixel \
img_to_ppm_file \
img_to_tga_file \
ppm_fd_atoi \
ppm_file_to_img \
read_till \
write_byte_n_times \
write_byte \
write_number

C_FILES = $(addprefix $(DIR_SRC), $(FILES:=.c))
O_FILES = $(FILES:=.o)

$(NAME):
	gcc -c $(C_FILES) -I $(DIR_INCLUDES) -g
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

all: $(NAME)
