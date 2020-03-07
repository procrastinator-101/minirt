/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:58:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/06 17:54:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <string.h>

int ft_mlx_color(int rgb);

void            *mlx_ptr;
void            *win_ptr;
void			*img_ptr;
int				*img_addr;

int				endian;
int				size_line;
int				bits_per_pixel;

int width = 1000;
int	height = 1500;

int pixels[1000][1000];

int colors[] =
{
	0x1EBC34,   /*  green   */
	0xFF0000,   /*  red     */
	0xFF00FF,   /*  pink    */
	0xFFFF00,   /*  yellow  */
	0x00FFFF,   /*  cyan    */
	0x000000,   /*  black   */
	0xFFFFFF,   /*  white   */
	0xC0C0C0,   /*  silver  */
	0x800080,   /*  purple  */
	0x800000    /*  maroon  */
};

int print_key(int key, void *param)
{
	static int	c1;
	static int	c2;
	unsigned int color;

	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 126)
		c1++;
	else if (key == 125)
		c1--;
	else if (key == 91)
		c2++;
	else if (key == 84)
		c2--;
	printf("key = %d\n", key);

	if (c1 > 9)
		c1 = 0;
	else if (c1 < 0)
		c1 = 9;
	if (c2 > 9)
		c2 = 0;
	else if (c2 < 0)
		c2 = 9;
	if (!mlx_ptr || !win_ptr)
		return (0);
	color = colors[0];
	unsigned char *ptr;
	ptr = (unsigned char *)(&color);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i % 50 && j % 50)
				img_addr[i * width + j] = colors[c1];
			else
				img_addr[i * width + j] = colors[c2];
		}
	}
	//printf("camera%s
	printf("size_line = %d\n", size_line);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	return (1);
}

int main()
{
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, width, height, "my test window");
	
	img_ptr = mlx_new_image(mlx_ptr, width, height);
	img_addr = (int *)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	
	//printf("bits = %d\n", bits_per_pixel);
	//printf("size = %lu\n", strlen(img_addr));

	mlx_key_hook(win_ptr, print_key, 0);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_image(mlx_ptr, img_ptr);
	return (0);
}
