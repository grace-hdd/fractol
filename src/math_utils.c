/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:00:00 by grhaddad          #+#    #+#             */
/*   Updated: 2024/12/29 10:00:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static void	parse_integer_part(char *str, double *result, int *i)
{
	while (ft_isdigit(str[*i]))
	{
		*result = *result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
}

static void	parse_decimal_part(char *str, double *result, int *i)
{
	double	fraction;

	fraction = 1.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			fraction /= 10.0;
			*result += (str[*i] - '0') * fraction;
			(*i)++;
		}
	}
}

double	ft_atof(char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	parse_integer_part(str, &result, &i);
	parse_decimal_part(str, &result, &i);
	return (result * sign);
}
