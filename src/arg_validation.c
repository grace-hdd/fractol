/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal_type> [parameters]\n", 1);
	ft_putstr_fd("Available fractals:\n", 1);
	ft_putstr_fd("  mandelbrot\n", 1);
	ft_putstr_fd("  julia <real> <imaginary>\n", 1);
	ft_putstr_fd("  burning_ship\n", 1);
	ft_putstr_fd("\nExample:\n", 1);
	ft_putstr_fd("  ./fractol mandelbrot\n", 1);
	ft_putstr_fd("  ./fractol julia -0.7 0.27\n", 1);
	ft_putstr_fd("  ./fractol burning_ship\n", 1);
	ft_putstr_fd("\nControls:\n", 1);
	ft_putstr_fd("  Mouse wheel: Zoom in/out\n", 1);
	ft_putstr_fd("  Arrow keys: Move around\n", 1);
	ft_putstr_fd("  +/-: Increase/decrease iterations\n", 1);
	ft_putstr_fd("  Space: Change color scheme\n", 1);
	ft_putstr_fd("  C: Toggle psychedelic colors\n", 1);
	ft_putstr_fd("  ESC: Exit\n", 1);
}

void	validate_mandelbrot(int argc, char **argv, t_fractol *fractol)
{
	(void)argv;
	fractol->fractal_type = MANDELBROT;
	if (argc != 2)
	{
		ft_putstr_fd("Error: Mandelbrot takes no additional ", 2);
		ft_putstr_fd("parameters\n", 2);
		print_usage();
		exit(EXIT_FAILURE);
	}
}

void	validate_julia(int argc, char **argv, t_fractol *fractol)
{
	fractol->fractal_type = JULIA;
	if (argc != 4)
	{
		ft_putstr_fd("Error: Julia requires real and ", 2);
		ft_putstr_fd("imaginary parameters\n", 2);
		print_usage();
		exit(EXIT_FAILURE);
	}
	fractol->julia_c.real = ft_atof(argv[2]);
	fractol->julia_c.imag = ft_atof(argv[3]);
}

void	validate_burning_ship(int argc, char **argv, t_fractol *fractol)
{
	(void)argv;
	fractol->fractal_type = BURNING_SHIP;
	if (argc != 2)
	{
		ft_putstr_fd("Error: Burning Ship takes no additional ", 2);
		ft_putstr_fd("parameters\n", 2);
		print_usage();
		exit(EXIT_FAILURE);
	}
}
