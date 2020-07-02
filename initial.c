/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:16:22 by rjohanna          #+#    #+#             */
/*   Updated: 2020/03/08 17:30:10 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		txt_put(t_fractol *fractol)
{
	char	*txt;
	char	*nb;

	nb = ft_itoa(fractol->max_iteration);
	txt = ft_strjoin("iteration :", nb);
	mlx_string_put(fractol->mlx, fractol->window, 10, 10, 0xFFFFFF, txt);
	ft_strdel(&txt);
	ft_strdel(&nb);
}

void		initial_calc(t_fractol *fractol)
{
	if (fractol->max_iteration < 0)
		fractol->max_iteration = 0;
	if (fractol->fractol == 0)
		mandelbrot_pthread(fractol);
	else if (fractol->fractol == 1)
		julia_pthread(fractol);
	else if (fractol->fractol == 2)
		burn_pthread(fractol);
	if (fractol->txt)
		txt_put(fractol);
}

void		initial(t_fractol *fractol)
{
	if (fractol->fractol == 0)
		set_def_mandelbrot(fractol);
	else if (fractol->fractol == 1)
		set_def_julia(fractol);
	else if (fractol->fractol == 2)
		set_def_burn(fractol);
	initial_calc(fractol);
}

int			cmp_fract(char **av, t_fractol *fractol)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		fractol->fractol = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		fractol->fractol = 1;
	else if (ft_strcmp(av[1], "burningship") == 0)
		fractol->fractol = 2;
	else
	{
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
		return (0);
	}
	return (1);
}
