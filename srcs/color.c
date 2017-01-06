/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:26:10 by gpoblon           #+#    #+#             */
/*   Updated: 2017/01/05 18:36:48 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_color(t_cscheme *cs)
{
	cs->freq[0] = 0.030;
	cs->freq[1] = 0.005;
	cs->freq[2] = 0.000;
	cs->amp[0] = 127;
	cs->amp[1] = 200;
	cs->amp[2] = 200;
	cs->phase[0] = 6;
	cs->phase[1] = 6;
	cs->phase[2] = 6;
	cs->center[0] = 55;
	cs->center[1] = 55;
	cs->center[2] = 55;
}

int			ft_get_color(double c_index, t_cscheme *cs)
{
	t_color		c;

	c.channels[0] = (unsigned char)(sin(cs->freq[0] * c_index + cs->phase[0]) *
													cs->amp[0] + cs->center[0]);
	c.channels[1] = (unsigned char)(sin(cs->freq[1] * c_index + cs->phase[1]) *
													cs->amp[1] + cs->center[1]);
	c.channels[2] = (unsigned char)(sin(cs->freq[2] * c_index + cs->phase[2]) *
													cs->amp[2] + cs->center[2]);
	return (c.number);
}
