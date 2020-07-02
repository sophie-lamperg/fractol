/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:50:55 by rjohanna          #+#    #+#             */
/*   Updated: 2020/03/08 17:04:16 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H
# define HEIGHT  1000
# define WIDTH   1000
# define THREAD  100
# define PTHREAD 5
# define MAIN_PAD_ESC 53
# define NUM_PAD_PLUS 69
# define NUM_PAD_MINUS 78
# define MAIN_PAD_ARROW_LEFT 123
# define MAIN_PAD_ARROW_RIGHT 124
# define MAIN_PAD_ARROW_UP 126
# define MAIN_PAD_ARROW_DOWN 125
# define SPACE      49
# define PSYCHO      18
# define TWO_PAD     19
# define THREE_PAD   20
# define LEFT_MOUSE  1
# define RIGHT_MOUSE 3
# define MOUSE_UP    4
# define MOUSE_DOWN  5
# define P_PAD       35
# define I_PAD       34

# define ERROR_THREAD "ERROR THREAD"
# define ERR_MEMORY  "ERROR MEMORY"
# define ERR_WIN  "ERROR WIN"
# define ERR_IMAGE   "ERROR IMAGE"

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include "math.h"
# include "pthread.h"
# include <stdio.h>

typedef	struct	s_fractol
{
	int			max_iteration;
	void		*mlx;
	void		*window;
	void		*image;
	double		c_re;
	double		c_im;
	double		zoom;
	double		x1;
	double		y1;
	int			color;
	int			x;
	int			y;
	int			y_max;
	double		z_re;
	double		z_im;
	int			size_line;
	int			endian;
	int			fractol;
	int			iteration;
	double		tmp;
	int			txt;
	void		*img_addr;
	int			bits_per_pixel;
	int			ju_mouse;
}				t_fractol;

void			mandelbrot(t_fractol *fractol);
int				close_win(void *param);
void			set_def_mandelbrot(t_fractol *fractol);
void			ft_error(char *s);
int				ft_abs(int a);
int				key_hook(int key, t_fractol *fractol);
void			zoom(int x, int y, t_fractol *fractol);
void			dezoom(int x, int y, t_fractol *fractol);
int				mouse_hook(int mouse, int x, int y, t_fractol *fractol);
void			*draw_mandelbrot(void *arr);
void			mandelbrot_pthread(t_fractol *fractol);
void			initial(t_fractol *fractol);
void			window_init(t_fractol *fractol);
void			set_def_julia(t_fractol *fractol);
void			julia(t_fractol *fractol);
void			*draw_julia(void *arr);
void			julia_pthread(t_fractol *fractol);
void			set_def_burn(t_fractol *fractol);
void			burningship(t_fractol *fractol);
void			burn_pthread(t_fractol *fractol);
void			initial_calc(t_fractol *fractol);
void			*draw_burn(void *arr);
int				cmp_fract(char **av, t_fractol *fractol);
void			hook_hook(t_fractol *fractol);
void			image_pixel(t_fractol *fractol, int x, int y, int color);
void			txt_put(t_fractol *fractol);
int				mouse_julia(int x, int y, t_fractol *fractol);

#endif
