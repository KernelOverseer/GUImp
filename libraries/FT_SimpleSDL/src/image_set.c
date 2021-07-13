/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:29:41 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 18:33:18 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

/*
**	This function places a pixel on the image, in the given posision
**		and with the given color
*/

void		ft_sdl_set_image_pixel(t_sdl_image *image, int x, int y, Uint32 color)
{
	ft_sdl_image_pixel(image, x, y, (0xFF000000 | color));
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