#include "miniRT.h"

void            *mlx_ptr;
void            *win_ptr;

int width = 1000;
int	height = 1000;

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

t_point		camera;
t_sphere	s;

int render(t_ray ray)
{
	
}

int print_key(int key, void *param)
{
	t_ray	ray;

	ray.origin = camera;
	if (key == 123)
		camera.x--;
	else if (key == 124)
		camera.x++;
	else if (key == 125)
		camera.y--;
	else if (key == 126)
		camera.y++;
	else if (key == 53)
		exit(EXIT_SUCCESS);

	if (!mlx_ptr || !win_ptr)
		return (0);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			ray.direction.x = i;
		   	ray.direction.y = j;
			render(ray);
			mlx_pixel_put(mlx_ptr, win_ptr, i, j,  pixels[i][j]);
		}
	}

	return (1);
}

int main()
{
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, width, height, "my test window");

	camera.x = 500;
	camera.y = 500;
	t_point center = {.x = 500, .y = 500};
	s.center = center;
	s.radius = 100.0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			pixels[i][j] = colors[4];
			mlx_pixel_put(mlx_ptr, win_ptr, i, j,  pixels[i][j]);
		}
	}
	mlx_key_hook(win_ptr, print_key, 0);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}
