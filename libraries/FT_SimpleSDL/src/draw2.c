/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:13:00 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 14:29:59 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

void		ft_sdl_image_arc_left_top(t_sdl_image *img, t_point co, int radius, Uint32 col)
{
	int		d;
	int		x;
	int		y;

	(void)col;
	y = radius;
	d = 3 - (radius << 1);
	x = -1;
	while (y >= ++x)
	{
        ft_sdl_image_pixel(img, co.x - x, co.y - y, col);
        ft_sdl_image_pixel(img, co.x - y, co.y - x, col);
		if (d < 0)
			d = d + (x << 2) + 6;
		else
		{
			d = d + ((x - y) << 2) + 10;
			--y;
		}
	}
}

void		ft_sdl_image_arc_left_bottom(t_sdl_image *img, t_point co, int radius, Uint32 col)
{
	int		d;
	int		x;
	int		y;

	(void)col;
	y = radius;
	d = 3 - (radius << 1);
	x = -1;
	while (y >= ++x)
	{
        ft_sdl_image_pixel(img, co.x - x, co.y + y, col);
        ft_sdl_image_pixel(img, co.x - y, co.y + x, col);
		if (d < 0)
			d = d + (x << 2) + 6;
		else
		{
			d = d + ((x - y) << 2) + 10;
			--y;
		}
	}
}

void		ft_sdl_image_arc_right_top(t_sdl_image *img, t_point co, int radius, Uint32 col)
{
	int		d;
	int		x;
	int		y;

	(void)col;
	y = radius;
	d = 3 - (radius << 1);
	x = -1;
	while (y >= ++x)
	{
        ft_sdl_image_pixel(img, co.x + 1 + x, co.y - y, col);
                ft_sdl_image_pixel(img, co.x + 1 + y, co.y - x, col);
		if (d < 0)
			d = d + (x << 2) + 6;
		else
		{
			d = d + ((x - y) << 2) + 10;
			--y;
		}
	}
}

void		ft_sdl_image_arc_right_bottom(t_sdl_image *img, t_point co, int radius, Uint32 col)
{
	int		d;
	int		x;
	int		y;

	(void)col;
	y = radius;
	d = 3 - (radius << 1);
	x = -1;
	while (y >= ++x)
	{
        ft_sdl_image_pixel(img, co.x + 1 + x, co.y + y, col);
		ft_sdl_image_pixel(img, co.x + 1 + y, co.y + x, col);
		if (d < 0)
			d = d + (x << 2) + 6;
		else
		{
			d = d + ((x - y) << 2) + 10;
			--y;
		}
	}
}