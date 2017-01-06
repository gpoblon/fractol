/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:26:44 by gpoblon           #+#    #+#             */
/*   Updated: 2017/01/06 21:37:24 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_put_pixel_img(t_app *app, t_point *p, int color)
{
	int		i;

	i = ((int)p->x * 4) + ((int)p->y * app->size_line);
	app->data[i] = color;
	app->data[++i] = color >> 8;
	app->data[++i] = color >> 16;
}

static void		ft_draw_img(t_thread_data *thread)
{
	t_point		p;
	int			(*fun)(t_fractal*, t_point*);

	fun = thread->f->fun;
	p.y = WINDOW_SIZE_Y / NB_THREAD * (thread->i);
	while (p.y < WINDOW_SIZE_Y / NB_THREAD * (thread->i + 1))
	{
		p.x = 0;
		while (p.x < WINDOW_SIZE_X)
		{
			ft_put_pixel_img(thread->app, &p, (fun)(thread->f, &p));
			++p.x;
		}
		++p.y;
	}
	free(thread->f);
	free(thread);
}

static void		ft_multi_thread_draw(t_app *app)
{
	pthread_t		thread_draw[NB_THREAD];
	t_thread_data	*thread;
	int				i;

	i = 0;
	while (i < NB_THREAD)
	{
		thread = (t_thread_data *)malloc(sizeof(t_thread_data));
		thread->i = i;
		thread->app = app;
		thread->f = (t_fractal *)malloc(sizeof(t_fractal));
		ft_memcpy(thread->f, app->fractal, sizeof(t_fractal));
		pthread_create(&thread_draw[thread->i], NULL,
			(void *)ft_draw_img, thread);
		++i;
	}
	i = 0;
	while (i < NB_THREAD)
	{
		pthread_join(thread_draw[i], NULL);
		++i;
	}
}

void			ft_draw_fractal(t_app *app)
{
	app->img_ptr = mlx_new_image(app->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	app->data = mlx_get_data_addr(app->img_ptr, &(app->bpp), &(app->size_line),
		&(app->endian));
	ft_multi_thread_draw(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img_ptr, 0, 0);
	mlx_destroy_image(app->mlx, app->img_ptr);
}
