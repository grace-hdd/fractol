/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
		close_window(fractol);
	handle_movement(keycode, fractol);
	handle_iterations(keycode, fractol);
	handle_colors(keycode, fractol);
	render_fractal(fractol);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractol *fractol)
{
	double	zoom_factor;
	double	mouse_real;
	double	mouse_imag;

	zoom_factor = 1.05;
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
	{
		mouse_real = ((double)x / WIDTH) * (4.0 / fractol->zoom)
			- (2.0 / fractol->zoom) + fractol->move_x;
		mouse_imag = ((double)y / HEIGHT) * (4.0 / fractol->zoom)
			- (2.0 / fractol->zoom) + fractol->move_y;
		if (button == MOUSE_WHEEL_UP)
			fractol->zoom *= zoom_factor;
		else if (button == MOUSE_WHEEL_DOWN)
			fractol->zoom /= zoom_factor;
		fractol->move_x = mouse_real - ((double)x / WIDTH)
			* (4.0 / fractol->zoom) + (2.0 / fractol->zoom);
		fractol->move_y = mouse_imag - ((double)y / HEIGHT)
			* (4.0 / fractol->zoom) + (2.0 / fractol->zoom);
		render_fractal(fractol);
	}
	return (0);
}
