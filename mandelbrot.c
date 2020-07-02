/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:34:42 by rjohanna          #+#    #+#             */
/*   Updated: 2020/03/10 15:54:29 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			image_pixel(t_fractol *fractol, int x, int y, int color)
{
	if (fractol->x < WIDTH && fractol->y < HEIGHT)
	{
		color = mlx_get_color_value(fractol->mlx, color);
		ft_memcpy(fractol->img_addr + 4 * WIDTH * y + x * 4, \
			&color, sizeof(int));
	}
}

void			set_def_mandelbrot(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->zoom = 300;
	fractol->x1 = -2.0;
	fractol->y1 = -2.0;
	fractol->color = 265;
}

void			mandelbrot(t_fractol *fractol)
{
	fractol->c_re = fractol->x / fractol->zoom + fractol->x1;
	fractol->c_im = fractol->y / fractol->zoom + fractol->y1;
	fractol->z_re = 0;
	fractol->z_im = 0;
	fractol->iteration = 0;
	while (fractol->z_re * fractol->z_re + fractol->z_im
			* fractol->z_im < 4 && fractol->iteration < fractol->max_iteration)
	{
		fractol->tmp = fractol->z_re;
		fractol->z_re = fractol->z_re * fractol->z_re -
			fractol->z_im * fractol->z_im + fractol->c_re;
		fractol->z_im = 2 * fractol->tmp * fractol->z_im + fractol->c_im;
		fractol->iteration++;
	}
	if (fractol->iteration == fractol->max_iteration)
		image_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
		image_pixel(fractol, fractol->x, fractol->y, \
			(fractol->color * fractol->iteration));
}

void			*draw_mandelbrot(void *arr)
{
	int			tmp;
	t_fractol	*fractol;

	fractol = (t_fractol *)arr;
	fractol->x = 0;
	tmp = fractol->y;
	while (fractol->x < WIDTH)
	{
		fractol->y = tmp;
		while (fractol->y < fractol->y_max)
		{
			mandelbrot(fractol);
			fractol->y++;
		}
		fractol->x++;
	}
	return (arr);
}

void			mandelbrot_pthread(t_fractol *fractol)
{
	t_fractol	tab[THREAD];
	pthread_t	t[THREAD];
	int			i;

	i = 0;
	while (i < THREAD)
	{
		tab[i] = *fractol;
		tab[i].y = (HEIGHT / THREAD) * i;
		tab[i].y_max = (HEIGHT / THREAD) * (i + 1);
		pthread_create(&t[i], NULL, draw_mandelbrot, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fractol->mlx, \
	fractol->window, fractol->image, 0, 0);
}
