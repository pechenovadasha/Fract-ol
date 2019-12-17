/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:10:03 by croxane           #+#    #+#             */
/*   Updated: 2019/11/15 19:23:55 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_mand(t_struct *data)
{
	data->maxr = 2.0;
	data->minr = -3.75;
	data->mini = -3.25;
	data->zoom = 150;
	data->iters = 50;
}

void			ft_mandel(t_struct *data, int i)
{
	t_complex	z;
	t_complex	c;
	t_complex	t;
	int			y;
	int			x;

	y = -1;
	while (++y < HEIGHT && (x = -1))
		while (++x < WIDTH)
		{
			c.r = x / data->zoom + data->minr;
			c.i = y / data->zoom + data->mini;
			z = c;
			i = -1;
			while (z.r * z.r + z.i * z.i <= 800 && ++i < data->iters)
			{
				t.r = z.r * z.r - z.i * z.i + c.r;
				t.i = z.r * z.i * 2 + c.i;
				z = t;
			}
			data->art[x + y * WIDTH] = (i == data->iters) ? 0
				: data->colour * i;
		}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
