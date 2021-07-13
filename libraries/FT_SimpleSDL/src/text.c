/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 02:51:27 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 18:33:15 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simplesdl.h"

static Uint32	get_pixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	Uint8	*p;
	Uint32	*target_pixel;
	
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	target_pixel = (Uint32*)p;	
	return (*target_pixel);
}

t_rect	ft_sdl_put_text(char *text, t_text info, TTF_Font *font,
	t_sdl_image *image)
{
	t_rect		off;
	SDL_Surface	*surface;

	surface = TTF_RenderText_Blended(font, text, (SDL_Color){RGB_R(info.color), RGB_G(info.color), RGB_B(info.color), RGB_A(info.color)});
	if (!surface)
		return ((t_rect){0, 0, 0, 0});
	off = (t_rect){info.x, info.y, surface->w, surface->h};
	if (info.align == ALIGN_CENTER_CENTER)
		off = (t_rect){info.x - (surface->w / 2),
			info.y - (surface->h / 2), surface->w, surface->h};
	SDL_LockSurface(surface);
	for (int y = 0; y < image->height && y < surface->h; y++)
	{
		for (int x = 0; x < image->width && x < surface->w; x++)
		{
			if (RGB_A(get_pixel(surface, x, y)))
				ft_sdl_blend_image_pixel(image, off.x + x, off.y + y, get_pixel(surface, x, y));
		}
	}	
	SDL_UnlockSurface(surface);
	SDL_FreeSurface(surface);
	return (off);
}