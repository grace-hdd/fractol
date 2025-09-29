/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	interpolate_color(int color1, int color2, double fraction)
{
	int	values[6];

	values[0] = (color1 >> 16) & 0xFF;
	values[1] = (color1 >> 8) & 0xFF;
	values[2] = color1 & 0xFF;
	values[3] = (color2 >> 16) & 0xFF;
	values[4] = (color2 >> 8) & 0xFF;
	values[5] = color2 & 0xFF;
	values[0] = values[0] + (int)((values[3] - values[0]) * fraction);
	values[1] = values[1] + (int)((values[4] - values[1]) * fraction);
	values[2] = values[2] + (int)((values[5] - values[2]) * fraction);
	return (create_trgb(0, values[0], values[1], values[2]));
}

int	get_psychedelic_color(int iteration, t_fractol *fractol)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == fractol->max_iter)
		return (BLACK);
	t = (double)iteration / fractol->max_iter;
	t += fractol->psychedelic;
	r = (int)(255 * (0.5 + 0.5 * sin(t * 6.28 + 0)));
	g = (int)(255 * (0.5 + 0.5 * sin(t * 6.28 + 2.09)));
	b = (int)(255 * (0.5 + 0.5 * sin(t * 6.28 + 4.18)));
	return (create_trgb(0, r, g, b));
}

static int	get_gradient_color(int iteration, int max_iter, int shift)
{
	double	t;
	int		colors[5];
	int		num_colors;
	int		color_index;
	double	local_t;

	colors[0] = 0x000428;
	colors[1] = 0x004e92;
	colors[2] = 0x009ffd;
	colors[3] = 0x00d2ff;
	colors[4] = 0xffffff;
	num_colors = 5;
	if (iteration == max_iter)
		return (BLACK);
	t = (double)iteration / max_iter;
	t = fmod(t + (shift * 0.1), 1.0);
	color_index = (int)(t * (num_colors - 1));
	local_t = (t * (num_colors - 1)) - color_index;
	if (color_index >= num_colors - 1)
		return (colors[num_colors - 1]);
	return (interpolate_color(colors[color_index],
			colors[color_index + 1], local_t));
}

int	get_color(int iteration, int max_iter, t_fractol *fractol)
{
	if (fractol->psychedelic > 0.0)
		return (get_psychedelic_color(iteration, fractol));
	else
		return (get_gradient_color(iteration, max_iter, fractol->color_shift));
}
