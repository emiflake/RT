/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_to_tga_file.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 12:51:46 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:07:53 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static bool	write_image_24_bit(int fd, t_img *img)
{
	int pixel_count;
	int i;

	pixel_count = img->height * img->width;
	i = 0;
	while (i < pixel_count)
	{
		write_byte(fd, img->pixels[i].b);
		write_byte(fd, img->pixels[i].g);
		write_byte(fd, img->pixels[i].r);
		i++;
	}
	return (true);
}

static bool	write_header(int fd, t_img *img)
{
	return (write_byte_n_times(fd, 0, 2) &&
		write_byte(fd, 2) &&
		write_byte_n_times(fd, 0, 9) &&
		write_byte(fd, (img->width & 0x00FF)) &&
		write_byte(fd, (img->width & 0xFF00) >> 8) &&
		write_byte(fd, (img->height & 0x00FF)) &&
		write_byte(fd, (img->height & 0xFF00) >> 8) &&
		write_byte(fd, 24) &&
		write_byte(fd, 0));
}

bool		img_to_tga_file(t_img *img, char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
		return (false);
	if (!write_header(fd, img) || !write_image_24_bit(fd, img))
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
