/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:27:19 by gpoblon           #+#    #+#             */
/*   Updated: 2017/01/06 16:49:14 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_user_input(char *argv)
{
	if (ft_strcmp(argv, "julia") == FALSE ||
		ft_strcmp(argv, "mandelbrot") == FALSE ||
		ft_strcmp(argv, "bship") == FALSE)
		return (TRUE);
	return (FALSE);
}

char		*ft_get_user_input(char *argv)
{
	if (ft_check_user_input(argv))
		return (argv);
	return (NULL);
}
