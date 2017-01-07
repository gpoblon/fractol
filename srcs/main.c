/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:27:14 by gpoblon           #+#    #+#             */
/*   Updated: 2017/01/07 15:06:36 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char		*ft_get_arg(char *argv)
{
	if (ft_strcmp(argv, "julia") == 0 || ft_strcmp(argv, "mandelbrot") == 0 ||
		ft_strcmp(argv, "bship") == 0)
		return (argv);
	return (NULL);
}

static t_app	*ft_new_window(int width, int height, char *title)
{
	t_app	*app;

	app = (t_app *)malloc(sizeof(t_app));
	if (!app)
	{
		ft_putendl_fd("Error mallocing app structure.", 2);
		return (NULL);
	}
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		ft_free_ptr(app);
		ft_putendl_fd("Error initializing funct: mlx_init in app struct.", 2);
		return (NULL);
	}
	app->win = mlx_new_window(app->mlx, width, height, title);
	if (!app->win)
	{
		ft_free_ptr(app);
		ft_putendl_fd("Error initializing funct: mlx_new_window.", 2);
		return (NULL);
	}
	return (app);
}

static int		ft_expose_hook(t_app *app)
{
	ft_draw_fractal(app);
	return (FALSE);
}

int				main(int argc, char *argv[])
{
	t_app	*app;
	char	*name_fractal;

	name_fractal = ft_get_arg(argv[1]);
	if (argc != 2 && !name_fractal)
		ft_exit("Error. Valid input: ./fractol julia || mandelbrot || bship");
	app = ft_new_window(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Fractol");
	if (!app)
		ft_exit("Error while creating the window");
	ft_init_fractal(app, name_fractal);
	mlx_hook(app->win, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion_hook, app);
	mlx_key_hook(app->win, ft_key_hook, app);
	mlx_mouse_hook(app->win, ft_mouse_hook, app);
	mlx_expose_hook(app->win, ft_expose_hook, app);
	mlx_loop(app->mlx);
	return (FALSE);
}
