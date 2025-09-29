/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_complex c, int max_iter)
{
	t_complex	z;
	t_complex	z_temp;
	int			iteration;

	z = complex_new(0.0, 0.0);
	iteration = 0;
	while (iteration < max_iter && (z.real * z.real + z.imag * z.imag) <= 4.0)
	{
		z_temp.real = z.real * z.real - z.imag * z.imag + c.real;
		z_temp.imag = 2 * fabs(z.real * z.imag) + c.imag;
		z = z_temp;
		iteration++;
	}
	return (iteration);
}
