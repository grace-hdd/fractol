/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	pixel_to_complex(int x, int y, t_fractol *fractol)
{
	t_complex	c;
	double		real_range;
	double		imag_range;

	real_range = 4.0 / fractol->zoom;
	imag_range = 4.0 / fractol->zoom;
	c.real = ((double)x / WIDTH) * real_range
		- (real_range / 2.0) + fractol->move_x;
	c.imag = ((double)y / HEIGHT) * imag_range
		- (imag_range / 2.0) + fractol->move_y;
	return (c);
}

int	calculate_fractal(int x, int y, t_fractol *fractol)
{
	t_complex	c;
	int			iterations;

	c = pixel_to_complex(x, y, fractol);
	if (fractol->fractal_type == MANDELBROT)
		iterations = mandelbrot(c, fractol->max_iter);
	else if (fractol->fractal_type == JULIA)
		iterations = julia(c, fractol->julia_c, fractol->max_iter);
	else if (fractol->fractal_type == BURNING_SHIP)
		iterations = burning_ship(c, fractol->max_iter);
	else
		iterations = 0;
	return (iterations);
}
