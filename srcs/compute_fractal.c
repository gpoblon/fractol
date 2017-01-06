/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:26:17 by gpoblon           #+#    #+#             */
/*   Updated: 2017/01/06 17:12:50 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_compute_julia(t_fractal *f, t_point *p)
{
	int		i;

	f->new.r = 1.5 * (p->x - f->w / 2) / (0.5 * f->zoom * f->w) - f->move.x;
	f->new.i = (p->y - f->h / 2) / (0.5 * f->zoom * f->h) + f->move.y;
	i = -1;
	while (++i < f->i_max)
	{
		f->old.r = f->new.r;
		f->old.i = f->new.i;
		f->new.r = f->old.r * f->old.r - f->old.i * f->old.i + f->c.r;
		f->new.i = 2 * f->old.r * f->old.i + f->c.i;
		if ((f->new.r * f->new.r + f->new.i * f->new.i) > 4)
			break ;
	}
	if (i < f->i_max)
	{
		return (ft_get_color(i + 1 - (log(2) /
			sqrt(f->new.r * f->new.r + f->new.i * f->new.i)) / log(2), f->cs));
	}
	return (0x000000);
}

static int		ft_compute_mandelbrot(t_fractal *f, t_point *p)
{
	int		i;

	f->z.r = 1.5 * (p->x - f->w / 2) / (0.5 * f->zoom * f->w) - f->move.x;
	f->z.i = (p->y - f->h / 2) / (0.5 * f->zoom * f->h) + f->move.y;
	f->new.r = 0;
	f->new.i = 0;
	f->old.r = 0;
	f->old.i = 0;
	i = -1;
	while (++i < f->i_max)
	{
		f->old.r = f->new.r;
		f->old.i = f->new.i;
		f->new.r = f->old.r * f->old.r - f->old.i * f->old.i + f->z.r;
		f->new.i = 2 * f->old.r * f->old.i + f->z.i;
		if ((f->new.r * f->new.r + f->new.i * f->new.i) > 4)
			break ;
	}
	if (i < f->i_max)
	{
		return (ft_get_color(i + 1 - (log(2) /
			sqrt(f->new.r * f->new.r + f->new.i * f->new.i)) / log(2), f->cs));
	}
	return (FALSE);
}

static int		ft_compute_bship(t_fractal *f, t_point *p)
{
	int		i;

	f->c.r = 1.5 * (p->x - f->w / 2) / (0.5 * f->zoom * f->w) - f->move.x;
	f->c.i = (p->y - f->h / 2) / (0.5 * f->zoom * f->h) + f->move.y;
	f->new.r = 0;
	f->new.i = 0;
	f->old.r = 0;
	f->old.i = 0;
	i = -1;
	while (++i < f->i_max)
	{
		f->old.r = f->new.r;
		f->old.i = f->new.i;
		f->new.r = f->old.r * f->old.r - f->old.i * f->old.i + f->c.r;
		f->new.i = 2 * fabs(f->old.r * f->old.i) + f->c.i;
		if ((f->new.r * f->new.r + f->new.i * f->new.i) > 4)
			break ;
	}
	if (i < f->i_max)
	{
		return (ft_get_color(i + 1 - (log(2) /
			sqrt(f->new.r * f->new.r + f->new.i * f->new.i)) / log(2), f->cs));
	}
	return (FALSE);
}

void			*ft_compute_fractal(char *name_fractal)
{
	void	*fun;

	if (!(ft_strcmp(name_fractal, "julia")))
		fun = &ft_compute_julia;
	if (!(ft_strcmp(name_fractal, "mandelbrot")))
		fun = &ft_compute_mandelbrot;
	if (!(ft_strcmp(name_fractal, "bship")))
		fun = &ft_compute_bship;
	return (fun);
}
