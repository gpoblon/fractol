/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:26:53 by gpoblon           #+#    #+#             */
/*   Updated: 2017/01/06 21:11:33 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_scale(int keycode, t_app *app)
{
	if (keycode == KEY_KP_PLUS)
	{
		if (app->fractal->i_max <= 500)
			app->fractal->i_max += 5;
		app->fractal->zoom *= 1.1;
		app->fractal->move.x += ((app->fractal->h / 2) /
			app->fractal->w / 2) / app->fractal->zoom * 10;
		app->fractal->move.y += ((app->fractal->w / 2) /
			app->fractal->h / 2) / app->fractal->zoom * 10;
	}
	else if (keycode == KEY_KP_MINUS)
	{
		if (app->fractal->i_max >= 50)
			app->fractal->i_max -= 5;
		app->fractal->zoom /= 1.1;
		app->fractal->move.x += ((app->fractal->h / 2) /
			app->fractal->w / 2) / app->fractal->zoom * 10;
		app->fractal->move.y += ((app->fractal->w / 2) /
			app->fractal->h / 2) / app->fractal->zoom * 10;
	}
}

static	void	ft_translate(int keycode, t_app *app)
{
	if (keycode == KEY_UP)
		app->fractal->move.y += 10 / (app->fractal->zoom * 20);
	else if (keycode == KEY_DOWN)
		app->fractal->move.y -= 10 / (app->fractal->zoom * 20);
	else if (keycode == KEY_LEFT)
		app->fractal->move.x += 10 / (app->fractal->zoom * 20);
	else if (keycode == KEY_RIGHT)
		app->fractal->move.x -= 10 / (app->fractal->zoom * 20);
}

static void		ft_reset(int keycode, t_app *app)
{
	if (keycode == KEY_KP_DOT)
	{
		if (!ft_strcmp(app->fractal->name, "julia") ||
			!ft_strcmp(app->fractal->name, "mandelbrot") ||
			!ft_strcmp(app->fractal->name, "bship"))
			ft_init_fractal(app, app->fractal->name);
	}
}

static void		ft_mod_iter(int keycode, t_app *app)
{
	if (keycode == KEY_PAGE_UP)
	{
		app->fractal->i_max += 10;
	}
	else if (keycode == KEY_PAGE_DOWN)
	{
		app->fractal->i_max =
			(app->fractal->i_max <= 50) ? 50 : app->fractal->i_max - 10;
	}
}

int				ft_key_hook(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(app->mlx, app->win);
		free(app->fractal);
		free(app);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 49)
		app->fractal->stop_motion = app->fractal->stop_motion ? 0 : 1;
	ft_translate(keycode, app);
	if (app->fractal->cs->lastkey == 0)
		ft_scale(keycode, app);
	else if (app->fractal->cs->lastkey != 0)
		ft_modify_color(keycode, app);
	ft_color_preset(keycode, app);
	ft_color_event(keycode, app);
	ft_reset(keycode, app);
	ft_mod_iter(keycode, app);
	ft_draw_fractal(app);
	return (FALSE);
}
