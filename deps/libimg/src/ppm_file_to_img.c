/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ppm_file_to_img.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 18:06:27 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:09:25 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static bool	is_compatable(int fd)
{
	char in;

	if (read(fd, &in, 1) != 1 || in != 'P')
		return (false);
	if (read(fd, &in, 1) != 1 || in != '6')
		return (false);
	return (true);
}

static bool	read_header(t_img *img, int fd)
{
	return (ppm_fd_atoi(fd, &img->width) &&
		ppm_fd_atoi(fd, &img->height) &&
		read_till(fd, '\n'));
}

static bool	buffer_to_img(uint8_t *buffer, t_img *img)
{
	size_t pixel_count;
	size_t i;

	pixel_count = img->width * img->height;
	i = 0;
	img->pixels = malloc(sizeof(t_pixel) * pixel_count);
	if (img->pixels == NULL)
		return (false);
	while (i < pixel_count)
	{
		img->pixels[i].r = buffer[0];
		img->pixels[i].g = buffer[1];
		img->pixels[i].b = buffer[2];
		buffer += 3;
		i++;
	}
	return (true);
}

static bool	read_image(t_img *img, int fd)
{
	size_t	byte_count;
	uint8_t *buffer;

	byte_count = 3 * img->width * img->height;
	buffer = malloc(byte_count);
	if (buffer == NULL)
		return (false);
	if (read(fd, buffer, byte_count) != byte_count ||
	!buffer_to_img(buffer, img))
	{
		free(buffer);
		return (false);
	}
	free(buffer);
	return (true);
}

t_img		*ppm_file_to_img(char *filename)
{
	t_img	*result;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	result = malloc(sizeof(t_img));
	if (result == NULL)
	{
		close(fd);
		return (NULL);
	}
	if (!is_compatable(fd) || !read_header(result, fd) ||
	!read_image(result, fd))
	{
		free(result);
		close(fd);
		return (NULL);
	}
	return (result);
}
