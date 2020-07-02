/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:28:28 by rjohanna          #+#    #+#             */
/*   Updated: 2020/03/08 16:46:53 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_def_burn(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->zoom = 220;
	fractol->x1 = -2.2;
	fractol->y1 = -2.5;
	fractol->color = 265;
}

void			burningship(t_fractol *fractol)
{
	fractol->c_re = fractol->x / fractol->zoom + fractol->x1;
	fractol->c_im = fractol->y / fractol->zoom + fractol->y1;
	fractol->z_re = 0;
	fractol->z_im = 0;
	fractol->iteration = 0;
	while (fabs(fractol->z_re * fractol->z_re + fractol->z_im * \
			fractol->z_im) < 4 && fractol->iteration < fractol->max_iteration)
	{
		fractol->tmp = fractol->z_re * fractol->z_re \
			- fractol->z_im * fractol->z_im + fractol->c_re;
		fractol->z_im = fabs(2 * fractol->z_re * fractol->z_im) + fractol->c_im;
		fractol->z_re = fractol->tmp;
		fractol->iteration++;
	}
	if (fractol->iteration == fractol->max_iteration)
		image_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
		image_pixel(fractol, fractol->x, fractol->y, \
			(fractol->color * fractol->iteration));
}

void			*draw_burn(void *arr)
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
			burningship(fractol);
			fractol->y++;
		}
		fractol->x++;
	}
	return (arr);
}

void			burn_pthread(t_fractol *fractol)
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
		pthread_create(&t[i], NULL, draw_burn, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fractol->mlx, fractol->window,\
		fractol->image, 0, 0);
}
