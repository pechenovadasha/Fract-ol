/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:55:25 by croxane           #+#    #+#             */
/*   Updated: 2019/11/13 18:55:28 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_julia(t_struct *data)
{
	data->maxr = 2.0;
	data->minr = -2.50;
	data->mini = -2.75;
	data->zoom = 200;
	data->c_r = -0.63;
	data->c_i = -0.54;
	data->iters = 100;
}

void			ft_julia(t_struct *data)
{
	t_complex	z;
	t_complex	t;
	int			y;
	int			x;
	int			i;

	i = -1;
	y = -1;
	while (++y < HEIGHT && (x = -1))
		while (++x < WIDTH)
		{
			z.r = x / data->zoom + data->minr;
			z.i = y / data->zoom + data->mini;
			while (z.r * z.r + z.i * z.i <= 800 && ++i < data->iters)
			{
				t.r = z.r * z.r - z.i * z.i + data->c_r;
				t.i = z.r * z.i * 2 + data->c_i;
				z = t;
			}
			data->art[x + y * WIDTH] = (i == data->iters) ? 0
					: data->colour * i;
			i = 50;
		}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
