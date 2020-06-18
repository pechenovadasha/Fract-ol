/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:49:05 by croxane           #+#    #+#             */
/*   Updated: 2019/11/15 20:43:54 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_menu(t_struct *data)
{
	mlx_string_put(data->mlx, data->win, 0, HEIGHT, 0xC9FFE5, "Push"
			"<esc> to exit");
	mlx_string_put(data->mlx, data->win, 0, HEIGHT + 50, 0xB284BE, "Push <1,"
			"2, 3, 4, 5> to change color of fractol");
	mlx_string_put(data->mlx, data->win, 0, HEIGHT + 100, 0x80FFBF,
			"Push <c> to change color of fractol to 1 %");
	mlx_string_put(data->mlx, data->win, 0, HEIGHT + 150, 0xFFFF00, "You can"
			"also increase and reduce the image to see infinity of fractol");
}

int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str;
	unsigned char	*src;

	str = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (*str == *src && *str != '\0' && *src != '\0')
	{
		str++;
		src++;
	}
	return (*str - *src);
}

int					ft_check_fractol(char *str, t_struct *data)
{
	!ft_strcmp(str, "Mandelbrot") ? data->type = MANDELBROT : 0;
	!ft_strcmp(str, "Julia") ? data->type = JULIA : 0;
	!ft_strcmp(str, "Burningship") ? data->type = BURNINGSHIP : 0;
	!data->type ? write(1, "What are you giving me!!!\n", 26) : 0;
	return (0);
}

void				ft_initial(t_struct *data)
{
	data->iter = 50;
	data->mlx = mlx_init();
	data->type = 0;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT + 200, "Fractol");
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->art = (int*)mlx_get_data_addr(data->image, &data->endian,
										&data->line_s, &data->bbp);
}

void				ft_what_is_frac(t_struct *data)
{
	int				i;

	i = 0;
	if (data->type == MANDELBROT)
		ft_mandel(data, i);
	else if (data->type == JULIA)
		ft_julia(data);
	else if (data->type == BURNINGSHIP)
		ft_mandelbrot_2(data, i);
}
