if ((i - 300) * (i - 300) + (j - 300) * (j - 300) <= 10000)
	color = ft_color(orange);
else if ((i - 500) * (i - 500) + (j - 200) * (j - 200) <= 10000)
	color = ft_color(red);
else if ((i - 700) * (i - 700) + (j - 300) * (j - 300) <= 10000)
	color = ft_color(purple);
else if ((i - 500) * (i - 500) + (j - 500) * (j - 500) <= 10000)
	color = ft_color(blue);
else if ((i - 200) * (i - 200) + (j - 500) * (j - 500) <= 10000)
	color = ft_color(pink);
else if ((i - 800) * (i - 800) + (j - 500) * (j - 500) <= 10000)
	color = ft_color(green);
else if ((i - 700) * (i - 700) + (j - 700) * (j - 700) <= 10000)
	color = ft_color(white);
else if ((i - 500) * (i - 500) + (j - 800) * (j - 800) <= 10000)
	color = ft_color(black);
else if ((i - 300) * (i - 300) + (j - 700) * (j - 700) <= 10000)
	color = ft_color(d_pink);
else if ((i - 500) * (i - 500) + (j - 500) * (j - 500) <= 160000)
	color = ft_color(yellow);
else if (i > 100 && j > 100 && i < 901 && j < 901)
	color = ft_color(grey);
else
	color = ft_color(yellow);
	mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
