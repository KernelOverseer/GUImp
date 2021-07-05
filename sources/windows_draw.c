/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:30:02 by abiri             #+#    #+#             */
/*   Updated: 2021/07/05 19:03:23 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    libui_window_components_draw(t_libui_window *window)
{
    t_libui_component   *component;
    t_list_head         component_list;

    component_list = window->components;
    component_list.iterator = component_list.first;
    while ((component = ttslist_iter_content(&component_list)))
        libui_components_draw(component);
}

int     libui_draw_render_image(t_sdl_image *image,
    SDL_Texture *texture, SDL_Renderer *renderer)
{
    SDL_UpdateTexture(texture, NULL, image->pixels,
        image->width * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    return (1);
}

void    libui_draw_window(t_libui_window *window)
{
    libui_window_draw(window);
    libui_window_components_draw(window);
    libui_draw_render_image(window->main_image, window->sdl_texture,
        window->sdl_renderer);
}

void    libui_window_draw(t_libui_window *window)
{
    // WILL CLEAR WINDOW WITH A BACKGROUND COLOR
    ft_sdl_image_rect(window->main_image, (t_rect){
        0, 0,
        window->props.width, window->props.height
    }, 0x000000);
}