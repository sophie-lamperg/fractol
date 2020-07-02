/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:29:22 by rjohanna          #+#    #+#             */
/*   Updated: 2020/03/10 15:34:33 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				close_win(void *param)
{
	(void)param;
	exit(0);
}

int				mouse_julia(int x, int y, t_fractol *fractol)
{
	if (fractol->fractol == 1 && fractol->ju_mouse == 1)
	{
		fractol->c_re = x * 2;
		fractol->c_im = y * 2 - 800;
		initial_calc(fractol);
	}
	return (0);
}

void			window_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "FRACTOL");
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img_addr = mlx_get_data_addr(fractol->image, \
	&fractol->bits_per_pixel, &fractol->size_line, &fractol->endian);
}

int				main(int ac, char **av)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	if (ac == 2)
	{
		window_init(fractol);
		if ((cmp_fract(av, fractol)) == 0)
			return (0);
		initial(fractol);
		mlx_hook(fractol->window, 6, 1L < 6, mouse_julia, fractol);
		mlx_hook(fractol->window, 17, 0, close_win, fractol);
		mlx_key_hook(fractol->window, key_hook, fractol);
		mlx_mouse_hook(fractol->window, mouse_hook, fractol);
		mlx_loop(fractol->mlx);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
	return (0);
}
