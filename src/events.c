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
	double	old_zoom;
	double	new_zoom;
	double	mouse_real;
	double	mouse_imag;

	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
	{
		old_zoom = fractol->zoom;
		if (button == MOUSE_WHEEL_UP)
			fractol->zoom *= 1.3;
		else if (button == MOUSE_WHEEL_DOWN)
			fractol->zoom /= 1.3;
		new_zoom = fractol->zoom;
		mouse_real = ((double)x / WIDTH) * (4.0 / old_zoom)
			- (2.0 / old_zoom) + fractol->move_x;
		mouse_imag = ((double)y / HEIGHT) * (4.0 / old_zoom)
			- (2.0 / old_zoom) + fractol->move_y;
		fractol->move_x = mouse_real - ((double)x / WIDTH)
			* (4.0 / new_zoom) + (2.0 / new_zoom);
		fractol->move_y = mouse_imag - ((double)y / HEIGHT)
			* (4.0 / new_zoom) + (2.0 / new_zoom);
		render_fractal(fractol);
	}
	return (0);
}
