/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:48:38 by croxane           #+#    #+#             */
/*   Updated: 2019/11/15 20:41:46 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_clear(t_struct *data)
{
	int				x;
	int				y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			data->art[x + y * WIDTH] = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}

void				zoom(int x, int y, t_struct *data)
{
	double			x_n;
	double			y_n;

	if (y > 0 && x > 0)
	{
		x_n = (x / data->zoom) + data->minr;
		y_n = (y / data->zoom) + data->mini;
		data->zoom *= 1.35;
		data->minr = x_n - (x / data->zoom);
		data->mini = y_n - (y / data->zoom);
	}
	data->iters += 5;
	ft_clear(data);
	ft_what_is_frac(data);
}

void				mooz(int x, int y, t_struct *data)
{
	double			x_n;
	double			y_n;

	if (y > 0 && x > 0)
	{
		x_n = (x / data->zoom) + data->minr;
		y_n = (y / data->zoom) + data->mini;
		data->zoom /= 1.35;
		data->minr = x_n - (x / data->zoom);
		data->mini = y_n - (y / data->zoom);
	}
	data->iters -= 5;
	ft_clear(data);
	ft_what_is_frac(data);
}

int					check_main(t_struct *data)
{
	int				i;

	i = 0;
	if (!data->type)
		return (0);
	if (data->type == MANDELBROT)
	{
		init_mand(data);
		ft_mandel(data, i);
	}
	else if (data->type == JULIA)
	{
		init_julia(data);
		ft_julia(data);
	}
	else if (data->type == BURNINGSHIP)
	{
		init_mandelbrot_2(data);
		ft_mandelbrot_2(data, i);
	}
	return (1);
}

int					main(int argc, char **argv)
{
	t_struct		data;

	data.colour = 0x10005d;
	data.zoom = 1;
	if (argc != 2)
		exit(!write(1, "Write name of fract'ol. It is [Mandelbrot]"
		" or [Julia] or [Burningship]\n", 71));
	ft_initial(&data);
	ft_menu(&data);
	ft_check_fractol(argv[1], &data);
	if (!check_main(&data))
		return (0);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	if (data.type == JULIA)
		mlx_hook(data.win, 6, 0, mouse_move_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
