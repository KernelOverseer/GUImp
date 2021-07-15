/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:29:41 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 14:29:03 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

/*
**	This function places a pixel on the image, in the given posision
**		and with the given color
*/

void		ft_sdl_set_image_pixel(t_sdl_image *image, int x, int y, Uint32 color)
{
	Uint32			background;
	float			opacity;
	float			background_opacity;
	unsigned char	rgb[3];

	background = ft_sdl_get_image_pixel(image, x, y);
	opacity = (float)(RGB_A(color)) / 255.0;
	background_opacity = (float)(RGB_A(background)) / 255.0;
	rgb[0] = RGB_R(color) * opacity + RGB_R(background)
		* (1.0 - opacity) * background_opacity;
	rgb[1] = RGB_G(color) * opacity + RGB_G(background)
		* (1.0 - opacity) * background_opacity;
	rgb[2] = RGB_B(color) * opacity + RGB_B(background)
		* (1.0 - opacity) * background_opacity;
	color = RGB(rgb[0], rgb[1], rgb[2],
		(int)((opacity + (background_opacity * (1.0-opacity))) * 255));
	ft_sdl_image_pixel(image, x, y, color);
}

void	ft_sdl_blend_image_pixel(t_sdl_image *image, int x, int y, Uint32 color)
{
	Uint32			original_color;
	float			opacity;
	unsigned char	rgb[3];
	
	original_color = ft_sdl_get_image_pixel(image, x, y);	
	opacity = (float)RGB_A(color) / 255.0;
	rgb[0] = RGB_R(color) * opacity + RGB_R(original_color) * (1-opacity);
	rgb[1] = RGB_G(color) * opacity + RGB_G(original_color) * (1-opacity);
	rgb[2] = RGB_B(color) * opacity + RGB_B(original_color) * (1-opacity);
	ft_sdl_image_pixel(image, x, y, rgb[0] | rgb[1] << 8 | rgb[2] << 16);
}