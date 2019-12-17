/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:48:08 by croxane           #+#    #+#             */
/*   Updated: 2019/11/15 20:41:58 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 1000
# define HEIGHT 1024

enum			e_types
{
	MANDELBROT = 1,
	JULIA,
	BURNINGSHIP
};

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct	s_struct
{
	void		*mlx;
	void		*win;
	void		*image;
	int			*art;
	int			endian;
	int			type;
	int			line_s;
	int			bbp;
	double		minr;
	double		mini;
	double		maxr;
	int			colour;
	int			iter;
	double		zoom;
	t_complex	complex;
	int			iters;
	double		c_r;
	double		c_i;

}				t_struct;

void			ft_mandel(t_struct *data, int i);
void			init_mand(t_struct *data);
void			zoom (int x, int y, t_struct *data);
void			mooz(int x, int y, t_struct *data);
void			ft_clear(t_struct *data);
int				key_hook(int key, void *param);
int				mouse_hook(int button, int x, int y, void *param);
void			ft_colour(t_struct *data);
void			ft_initial(t_struct *data);
int				ft_check_fractol(char *str, t_struct *data);
void			ft_julia(t_struct *data);
void			init_julia(t_struct *data);
void			ft_what_is_frac(t_struct *data);
int				mouse_move_hook(int x, int y, t_struct *data);
void			init_mandelbrot_2(t_struct *data);
void			ft_mandelbrot_2(t_struct *data, int i);
int				ft_check_fractol(char *str, t_struct *data);
void			ft_menu(t_struct *data);

#endif
