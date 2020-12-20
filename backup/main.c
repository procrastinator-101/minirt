#include "../minirt.h"

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

int print_key(int key, void *param)
{
	static int	c1;
	static int	c2;

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
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (i % 16 && j % 16)
				mlx_pixel_put(mlx_ptr, win_ptr, i, j,  colors[c1]);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, i, j,  colors[c2]);
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

	mlx_key_hook(win_ptr, print_key, 0);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}
