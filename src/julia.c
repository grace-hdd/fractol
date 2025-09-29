/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z, t_complex c, int max_iter)
{
	t_complex	z_squared;
	int			iteration;

	iteration = 0;
	while (iteration < max_iter && (z.real * z.real + z.imag * z.imag) <= 4.0)
	{
		z_squared = complex_multiply(z, z);
		z = complex_add(z_squared, c);
		iteration++;
	}
	return (iteration);
}
