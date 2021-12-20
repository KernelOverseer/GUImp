/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_draw_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer.pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:26:49 by abiri             #+#    #+#             */
/*   Updated: 2021/12/20 17:00:16 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

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

static int  copy_surface_to_image(SDL_Surface *surface, t_sdl_image *image, t_rect off)
{
    Uint32  color;

    SDL_LockSurface(surface);
    for (int y = 0; y < image->height && y < surface->h; y++)
    {
        for (int x = 0; x < image->width && x < surface->w; x++)
        {
            // if (RGB_A(get_pixel(surface, x, y)))
            color = get_pixel(surface, x, y);
            color = RGB(RGB_R(color), RGB_G(color), RGB_B(color), RGB_A(color));
            ft_sdl_image_pixel(image, off.x + x, off.y + y, color);
            // ft_sdl_blend_image_pixel(image, off.x + x, off.y + y, color);
        }
    }
    SDL_UnlockSurface(surface);
    SDL_FreeSurface(surface);
    return (0);
}

int     libui_builtin_draw_text(char *text, t_font *font,
    t_sdl_image *image, t_libui_style *style)
{
    SDL_Surface *surface;
    SDL_Color   color;
    t_rect      off;

    color = (SDL_Color){RGB_R(style->color), RGB_G(style->color), RGB_B(style->color), 255};
    off = (t_rect){0, 0, 0, 0};
    surface = TTF_RenderText_Blended(font->font, text, color);
    if (!surface)
        return (0);
    copy_surface_to_image(surface, image, off);
    return (1);
}