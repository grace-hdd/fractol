/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	validate_arguments(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 2)
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		validate_mandelbrot(argc, argv, fractol);
	else if (ft_strcmp(argv[1], "julia") == 0)
		validate_julia(argc, argv, fractol);
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		validate_burning_ship(argc, argv, fractol);
	else
	{
		ft_putstr_fd("Error: Unknown fractal type\n", 2);
		print_usage();
		exit(EXIT_FAILURE);
	}
}

void	fractol_init(t_fractol *fractol, char **argv)
{
	fractol->zoom = 1.0;
	fractol->move_x = 0.0;
	fractol->move_y = 0.0;
	fractol->max_iter = MAX_ITERATIONS;
	fractol->color_shift = 0;
	fractol->psychedelic = 0.0;
	if (fractol->fractal_type == JULIA)
	{
		fractol->julia_c.real = ft_atof(argv[2]);
		fractol->julia_c.imag = ft_atof(argv[3]);
	}
	init_mlx(fractol);
	init_img(fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	validate_arguments(argc, argv, &fractol);
	fractol_init(&fractol, argv);
	render_fractal(&fractol);
	mlx_key_hook(fractol.win, key_press, &fractol);
	mlx_mouse_hook(fractol.win, mouse_press, &fractol);
	mlx_hook(fractol.win, 17, 0, close_window, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
