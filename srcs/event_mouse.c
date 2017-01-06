/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:26:58 by gpoblon           #+#    #+#             */
/*   Updated: 2017/01/06 21:13:07 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_scale_mouse(int button, int x, int y, t_app *app)
{
	if (button == 1 || button == 4)
	{
		if (y > 0 && y > 0)
		{
			app->fractal->move.x += 0.002 *
				(WINDOW_SIZE_X / 2 - x) / app->fractal->zoom;
			app->fractal->move.y -= 0.002 *
				(WINDOW_SIZE_Y / 2 - y) / app->fractal->zoom;
		}
		if (button == 4)
		{
			if (app->fractal->i_max <= 500)
				app->fractal->i_max += 5;
			app->fractal->zoom *= 2;
		}
	}
	if (button == 5)
	{
		if (app->fractal->i_max >= 50)
			app->fractal->i_max -= 5;
		app->fractal->zoom =
			(app->fractal->zoom <= 1) ? 1 : app->fractal->zoom / 2;
	}
}

int				ft_motion_hook(int x, int y, t_app *app)
{
	if (app->fractal->stop_motion)
		return (FALSE);
	if (x >= 0 && y >= 0 && x <= app->fractal->w && y <= app->fractal->h)
	{
		app->fractal->c.r = -0.7 + (double)x / WINDOW_SIZE_X;
		app->fractal->c.i = 0.27015 + (double)y / WINDOW_SIZE_Y;
		ft_draw_fractal(app);
	}
	return (FALSE);
}

int				ft_mouse_hook(int button, int x, int y, t_app *app)
{
	ft_scale_mouse(button, x, y, app);
	ft_draw_fractal(app);
	return (FALSE);
}
