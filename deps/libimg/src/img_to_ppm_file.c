/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_to_ppm_file.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 16:13:05 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:09:02 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static void	image_to_buffer(uint8_t *buffer, t_img *img)
{
	size_t pixel_count;
	size_t i;

	pixel_count = img->width * img->height;
	i = 0;
	while (i < pixel_count)
	{
		buffer[0] = img->pixels[i].r;
		buffer[1] = img->pixels[i].g;
		buffer[2] = img->pixels[i].b;
		buffer += 3;
		i++;
	}
}

static bool	write_image(int fd, t_img *img)
{
	uint8_t	*buffer;
	size_t	byte_count;

	byte_count = 3 * img->width * img->height;
	buffer = malloc(byte_count);
	if (buffer == NULL)
		return (false);
	image_to_buffer(buffer, img);
	if (write(fd, buffer, byte_count) != byte_count)
	{
		free(buffer);
		return (false);
	}
	free(buffer);
	return (true);
}

static bool	write_header(int fd, t_img *img)
{
	return (write_byte(fd, 'P') && write_byte(fd, '6') &&
	write_byte(fd, '\n') && write_number(fd, img->width) &&
	write_byte(fd, ' ') && write_number(fd, img->height) &&
	write_byte(fd, '\n') && write_number(fd, 255) && write_byte(fd, '\n'));
}

bool		img_to_ppm_file(t_img *img, char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
		return (false);
	if (!write_header(fd, img) || !write_image(fd, img))
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
