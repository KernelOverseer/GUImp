/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:36:55 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 13:52:58 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "components/text/text.h"

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

int libui_component_text_render(char *text, TTF_Font *font,
	t_sdl_image *image, Uint32 color)
{
	SDL_Surface	*surface;
    t_sdl_image *new_image;

    if (!font)
        return (0);
	surface = TTF_RenderText_Solid(font, text, (SDL_Color){255, 255, 255, 0});
	if (!surface)
		return (0);
    free(image->pixels);
    new_image = newimage(surface->w, surface->h);
    *image = *new_image;
    free(new_image);
	SDL_LockSurface(surface);
	for (int y = 0; y < image->height && y < surface->h; y++)
	{
		for (int x = 0; x < image->width && x < surface->w; x++)
		{
			if (RGB_A(get_pixel(surface, x, y)))
				ft_sdl_set_image_pixel(image, x, y, color);
		}
	}	
	SDL_UnlockSurface(surface);
	SDL_FreeSurface(surface);
	return (1);
}

static int          libui_component_text_draw(t_libui_component *text,
                    void *args)
{
    t_libui_asset_font  *font;

    font = libui_asset_get_font(text->window->env, text->props.style.fontFamily);
    if (!font)
        return (0);
    if (!libui_component_text_render("HELLO",
        font->fonts[0],
        &text->props.render_image, 0xFFFFFF))
        return (0);
    libui_draw_image_blit(text->window->main_image,
        &text->props.render_image,
        (t_rect){.x=200, .y=200});
    // ft_sdl_image_disc(text->window->main_image, (t_point){100, 100},
    // 50, 0xFFFFFF);
    return (1);
}

t_libui_component   *libui_component_text_new(t_libui_component_props props)
{
    t_libui_component   *new_component;

    if (!(new_component = ft_memalloc(sizeof(t_libui_component))))
        return (NULL);
    ttslist_init(&new_component->children);
    new_component->props = props;
    new_component->draw = &libui_component_text_draw;
    return (new_component);
}

t_libui_component   *libui_create_text_default(void)
{
    t_libui_component_props props;

    ft_bzero(&props, sizeof(t_libui_component_props));
    props.style.fontSize = 22;
    props.style.fontFamily = ft_strdup("./assets/fonts/Roboto-Regular.ttf");
    return (libui_component_text_new(props));
}