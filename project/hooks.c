/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:02:35 by croxane           #+#    #+#             */
/*   Updated: 2019/11/15 19:15:27 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_move_hook(int x, int y, t_struct *data)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		data->c_r = x / data->zoom + data->minr;
		data->c_i = y / data->zoom + data->mini;
		ft_julia(data);
	}
	return (0);
}

int				mouse_hook(int button, int x, int y, void *param)
{
	t_struct	*data;

	data = param;
	if (button == 4)
		zoom(x, y, param);
	else if (button == 5)
		mooz(x, y, param);
	if ((data->type == JULIA) && (x || y))
		mouse_move_hook(x, y, param);
	return (0);
}

void			ft_colour(t_struct *data)
{
	data->colour += 1;
	ft_clear(data);
	ft_what_is_frac(data);
}

void			ft_change_color(int key, void *param, t_struct *data)
{
	if (key == 18)
	{
		data->colour = 0xc4ff00;
		ft_colour(param);
	}
	if (key == 23)
	{
		data->colour = 0x10005d;
		ft_colour(param);
	}
	if (key == 21)
	{
		data->colour = 0xccf0e7;
		ft_colour(param);
	}
	if (key == 20)
	{
		data->colour = 0x1fffff;
		ft_colour(param);
	}
	if (key == 19)
	{
		data->colour = 0x000011;
		ft_colour(param);
	}
}

int				key_hook(int key, void *param)
{
	t_struct	*data;

	data = param;
	if (key == 53)
		exit(0);
	if (key == 8)
		ft_colour(param);
	ft_change_color(key, param, data);
	return (0);
}
