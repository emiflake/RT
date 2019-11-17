/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libimg.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 14:59:42 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:11:26 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIMG_H
# define LIBIMG_H
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/types.h>
# define IMG_BYTES_PER_PIXEL 4
# define TGA_HEADER_LEN 18

/*
** t_pixel has and alpha channle to be compatible with sdl2's window surface
** bgra instead of rgba because the mac's use little endian byte ordering
*/

# pragma pack(push, 1)

typedef struct	s_pixel
{
	uint8_t b;
	uint8_t g;
	uint8_t r;
	uint8_t a;
}				t_pixel;

# pragma pack(pop)

typedef struct	s_img
{
	int				width;
	int				height;
	t_pixel			*pixels;
}				t_img;

void			img_clear(t_img *img);
void			img_destroy(t_img **img);
void			img_flip_horizontal(t_img *img);
void			img_flip_vertical(t_img *img);
t_pixel			img_get_pixel(t_img *img, int x, int y);
t_img			*img_new(int width, int height);
void			img_set_pixel(t_img *img, t_pixel pixel, int x, int y);
bool			img_to_ppm_file(t_img *img, char *filename);
bool			img_to_tga_file(t_img *img, char *filename);
bool			ppm_fd_atoi(int fd, int *result);
t_img			*ppm_file_to_img(char *filename);
bool			read_till(int fd, char c);
bool			write_byte_n_times(int fd, uint8_t byte, int n);
bool			write_byte(int fd, uint8_t byte);
bool			write_number(int fd, int n);

#endif
