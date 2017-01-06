/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:26:48 by gpoblon           #+#    #+#             */
/*   Updated: 2017/01/06 21:30:17 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_color_preset(int keycode, t_app *app)
{
	if (keycode == 12)
		*app->fractal->cs = (t_cscheme){0.34, 0.185, 0.15, 6, 6, 6, 197,
										210, 210, 55, 55, 55};
	else if (keycode == 13)
		*app->fractal->cs = (t_cscheme){0.31, 0.155, 0.21, 14, 7, 10, 197,
										180, 230, 55, 75, 80};
	else if (keycode == 14)
		*app->fractal->cs = (t_cscheme){0.25, 0.645, 0.14, 6, 6, 6, 207,
										210, 190, 50, 70, 90};
	else if (keycode == 15)
		*app->fractal->cs = (t_cscheme){0.03, 0.015, 0.01, 6, 6, 6, 97,
										200, 200, 50, 55, 60};
}

void		ft_color_event(int keycode, t_app *app)
{
	app->fractal->cs->lastkey = 0;
	if (keycode == KEY_1)
		app->fractal->cs->lastkey |= 1 << 0;
	else if (keycode == KEY_2)
		app->fractal->cs->lastkey |= 1 << 1;
	else if (keycode == KEY_3)
		app->fractal->cs->lastkey |= 1 << 2;
	else if (keycode == KEY_4)
		app->fractal->cs->lastkey |= 1 << 3;
	else if (keycode == KEY_5)
		app->fractal->cs->lastkey |= 1 << 4;
	else if (keycode == KEY_6)
		app->fractal->cs->lastkey |= 1 << 5;
	else if (keycode == KEY_7)
		app->fractal->cs->lastkey |= 1 << 6;
	else if (keycode == KEY_8)
		app->fractal->cs->lastkey |= 1 << 7;
	else if (keycode == KEY_9)
		app->fractal->cs->lastkey |= 1 << 8;
	else if (keycode == KEY_0)
		app->fractal->cs->lastkey |= 1 << 9;
	else if (keycode == 27)
		app->fractal->cs->lastkey |= 1 << 10;
	else if (keycode == 24)
		app->fractal->cs->lastkey |= 1 << 11;
}

static void	ft_plus_color(int keycode, t_app *app)
{
	if (app->fractal->cs->lastkey & 1 << 0)
		app->fractal->cs->freq[0] += 0.010;
	else if (app->fractal->cs->lastkey & 1 << 1)
		app->fractal->cs->freq[1] += 0.010;
	else if (app->fractal->cs->lastkey & 1 << 2)
		app->fractal->cs->freq[2] += 0.010;
	else if (app->fractal->cs->lastkey & 1 << 3)
		app->fractal->cs->phase[0] += 1;
	else if (app->fractal->cs->lastkey & 1 << 4)
		app->fractal->cs->phase[1] += 1;
	else if (app->fractal->cs->lastkey & 1 << 5)
		app->fractal->cs->phase[2] += 1;
	else if (app->fractal->cs->lastkey & 1 << 6)
		app->fractal->cs->amp[0] += 10;
	else if (app->fractal->cs->lastkey & 1 << 7)
		app->fractal->cs->amp[1] += 10;
	else if (app->fractal->cs->lastkey & 1 << 8)
		app->fractal->cs->amp[2] += 10;
	else if (app->fractal->cs->lastkey & 1 << 9)
		app->fractal->cs->center[0] += 5;
	else if (app->fractal->cs->lastkey & 1 << 10)
		app->fractal->cs->center[1] += 5;
	else if (app->fractal->cs->lastkey & 1 << 11)
		app->fractal->cs->center[2] += 5;
}

static void	ft_minus_color(int keycode, t_app *app)
{
	if (app->fractal->cs->lastkey & 1 << 0)
		app->fractal->cs->freq[0] -= 0.010;
	else if (app->fractal->cs->lastkey & 1 << 1)
		app->fractal->cs->freq[1] -= 0.010;
	else if (app->fractal->cs->lastkey & 1 << 2)
		app->fractal->cs->freq[2] -= 0.010;
	else if (app->fractal->cs->lastkey & 1 << 3)
		app->fractal->cs->phase[0] -= 1;
	else if (app->fractal->cs->lastkey & 1 << 4)
		app->fractal->cs->phase[1] -= 1;
	else if (app->fractal->cs->lastkey & 1 << 5)
		app->fractal->cs->phase[2] -= 1;
	else if (app->fractal->cs->lastkey & 1 << 6)
		app->fractal->cs->amp[0] -= 10;
	else if (app->fractal->cs->lastkey & 1 << 7)
		app->fractal->cs->amp[1] -= 10;
	else if (app->fractal->cs->lastkey & 1 << 8)
		app->fractal->cs->amp[2] -= 10;
	else if (app->fractal->cs->lastkey & 1 << 9)
		app->fractal->cs->center[0] -= 5;
	else if (app->fractal->cs->lastkey & 1 << 10)
		app->fractal->cs->center[1] -= 5;
	else if (app->fractal->cs->lastkey & 1 << 11)
		app->fractal->cs->center[2] -= 5;
}

void		ft_modify_color(int keycode, t_app *app)
{
	if (keycode == KEY_KP_PLUS && app->fractal->cs->lastkey)
		ft_plus_color(keycode, app);
	else if (keycode == KEY_KP_MINUS && app->fractal->cs->lastkey)
		ft_minus_color(keycode, app);
	app->fractal->cs->lastkey = 0;
}
