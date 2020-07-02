/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:07:02 by rjohanna          #+#    #+#             */
/*   Updated: 2020/03/08 17:15:44 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_hook(int key, t_fractol *fractol)
{
	if (key == TWO_PAD)
		fractol->color = 2050;
	else if (key == THREE_PAD)
		fractol->color = 265;
	else if (key == P_PAD)
		fractol->ju_mouse = !fractol->ju_mouse;
	else if (key == I_PAD)
		fractol->txt = !fractol->txt;
	return (0);
}

int		key_hook(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == NUM_PAD_PLUS)
		fractol->max_iteration += 50;
	else if (key == NUM_PAD_MINUS)
		fractol->max_iteration -= 50;
	else if (key == MAIN_PAD_ARROW_LEFT)
		fractol->x1 += 30 / fractol->zoom;
	else if (key == MAIN_PAD_ARROW_RIGHT)
		fractol->x1 -= 30 / fractol->zoom;
	else if (key == MAIN_PAD_ARROW_DOWN)
		fractol->y1 -= 30 / fractol->zoom;
	else if (key == MAIN_PAD_ARROW_UP)
		fractol->y1 += 30 / fractol->zoom;
	else if (key == SPACE)
		initial(fractol);
	else if (key == PSYCHO)
		fractol->color = 167272;
	color_hook(key, fractol);
	initial_calc(fractol);
	return (0);
}

void	zoom(int x, int y, t_fractol *fractol)
{
	fractol->x1 = (x / fractol->zoom + fractol->x1) - \
	(x / (fractol->zoom * 1.3));
	fractol->y1 = (y / fractol->zoom + fractol->y1) - \
	(y / (fractol->zoom * 1.3));
	fractol->zoom *= 1.3;
	fractol->max_iteration++;
}

void	dezoom(int x, int y, t_fractol *fractol)
{
	fractol->x1 = (x / fractol->zoom + fractol->x1) - \
	(x / (fractol->zoom / 1.3));
	fractol->y1 = (y / fractol->zoom + fractol->y1) - \
	(y / (fractol->zoom / 1.3));
	fractol->zoom /= 1.3;
	fractol->max_iteration--;
}

int		mouse_hook(int mouse, int x, int y, t_fractol *fractol)
{
	if (mouse == LEFT_MOUSE || mouse == MOUSE_UP)
		zoom(x, y, fractol);
	else if (mouse == RIGHT_MOUSE || mouse == MOUSE_DOWN)
		dezoom(x, y, fractol);
	initial_calc(fractol);
	return (0);
}
