#include "minirt.h"

int main()
{
	int nb_rows = 3;
	int nb_cols = 4;
	t_display display;
	display.bpp = 7;
	display.local_endian = ft_local_endian();
	display.line_size = (nb_cols * display.bpp + 7) / 8;
	display.img_addr = calloc(nb_rows, display.line_size);

	display.mlx_ptr = mlx_init();

	printf("local endian = %d\n", ft_local_endian());
	for (int i = 0; i < nb_rows; i++)
    {
        for (int j = 0; j < display.line_size; j++)
            printf("%d ", ((unsigned char *)(display.img_addr))[i * display.line_size + j]);
        printf("\n");
    }

	for (int i = 0; i < nb_rows; i++)
		for (int j = 0; j < nb_cols; j++)
			update_pixel_data(&display, j, i, 0x01020304);
	for (int i = 0; i < nb_rows; i++)
	{
        for (int j = 0; j < display.line_size; j++)
			printf("%d ", ((unsigned char *)(display.img_addr))[i * display.line_size + j]);
		printf("\n");
	}

	for (int i = 0; i < nb_rows; i++)
        for (int j = 0; j < nb_cols; j++)
			ft_btl_endian(
					(unsigned char *)(display.img_addr) + i * display.line_size + j * (display.bpp / 8),
					(j * display.bpp) % 8,
					display.bpp);

	for (int i = 0; i < nb_rows; i++)
	{
        for (int j = 0; j < display.line_size; j++)
			printf("%d ", ((unsigned char *)(display.img_addr))[i * display.line_size + j]);
		printf("\n");
	}
	return 0;
}
