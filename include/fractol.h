/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../lib/mlx/mlx.h"

/* Window dimensions */
# define WIDTH 800
# define HEIGHT 800

/* Colors */
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define MAGENTA 0xFF00FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF

/* Fractal types */
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

/* Maximum iterations */
# define MAX_ITERATIONS 100

/* Key codes for Linux */
# define ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define KEY_R 114
# define KEY_I 105
# define KEY_C 99

/* Mouse codes */
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_LEFT_CLICK 1

/* Complex number structure */
typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

/* Image structure for pixel manipulation */
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/* Main fractol structure */
typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			fractal_type;
	double		zoom;
	double		move_x;
	double		move_y;
	t_complex	julia_c;
	int			max_iter;
	int			color_shift;
	double		psychedelic;
}	t_fractol;

/* Function prototypes */

/* Main functions */
int			main(int argc, char **argv);
void		fractol_init(t_fractol *fractol, char **argv);
void		fractol_render(t_fractol *fractol);
void		print_usage(void);
void		validate_mandelbrot(int argc, char **argv, t_fractol *fractol);
void		validate_julia(int argc, char **argv, t_fractol *fractol);
void		validate_burning_ship(int argc, char **argv, t_fractol *fractol);

/* Fractal calculations */
int			mandelbrot(t_complex c, int max_iter);
int			julia(t_complex z, t_complex c, int max_iter);
int			burning_ship(t_complex c, int max_iter);
int			calculate_fractal(int x, int y, t_fractol *fractol);

/* Utility functions */
double		ft_atof(char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
void		error_exit(char *message);
t_complex	complex_new(double real, double imag);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_multiply(t_complex a, t_complex b);
double		complex_abs(t_complex c);

/* Rendering functions */
void		pixel_put(t_img *img, int x, int y, int color);
int			get_color(int iteration, int max_iter, t_fractol *fractol);
void		render_fractal(t_fractol *fractol);

/* Event handling */
int			key_press(int keycode, t_fractol *fractol);
int			mouse_press(int button, int x, int y, t_fractol *fractol);
int			close_window(t_fractol *fractol);
void		handle_movement(int keycode, t_fractol *fractol);
void		handle_iterations(int keycode, t_fractol *fractol);
void		handle_colors(int keycode, t_fractol *fractol);

/* Color functions */
int			interpolate_color(int color1, int color2, double fraction);
int			get_psychedelic_color(int iteration, t_fractol *fractol);
int			create_trgb(int t, int r, int g, int b);

/* Initialization */
void		init_fractol(t_fractol *fractol);
void		init_mlx(t_fractol *fractol);
void		init_img(t_fractol *fractol);

#endif