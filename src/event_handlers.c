/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_movement(int keycode, t_fractol *fractol)
{
	double	move_step;

	move_step = 0.1 / fractol->zoom;
	if (keycode == KEY_LEFT)
		fractol->move_x -= move_step;
	else if (keycode == KEY_RIGHT)
		fractol->move_x += move_step;
	else if (keycode == KEY_UP)
		fractol->move_y -= move_step;
	else if (keycode == KEY_DOWN)
		fractol->move_y += move_step;
}

void	handle_iterations(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_PLUS && fractol->max_iter < 1000)
		fractol->max_iter += 10;
	else if (keycode == KEY_MINUS && fractol->max_iter > 10)
		fractol->max_iter -= 10;
}

void	handle_colors(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_SPACE)
		fractol->color_shift = (fractol->color_shift + 1) % 10;
	else if (keycode == KEY_C)
	{
		if (fractol->psychedelic == 0.0)
			fractol->psychedelic = 1.0;
		else
			fractol->psychedelic = 0.0;
	}
}
