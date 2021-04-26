/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:06:26 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 11:39:28 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int  libui_draw_render_image(t_libui_window *window)
{
    SDL_UpdateTexture(window->sdl_texture, NULL, window->main_image->pixels,
        window->main_image->width * sizeof(Uint32));
    SDL_RenderClear(window->sdl_renderer);
    SDL_RenderCopy(window->sdl_renderer, window->sdl_texture, NULL, NULL);
    SDL_RenderPresent(window->sdl_renderer);
    return (1);
}

static int  libui_draw_component(t_libui_component *component)
{
    t_list_head         children;
    t_libui_component   *child;

    if (!component->draw)
        return (0);
    component->draw(component, NULL);
    children = component->children;
    children.iterator = children.first;
    while ((child = ttslist_iter_content(&children)))
    {
        if (component->window)
            child->window = component->window;
        libui_draw_component(child);
    }
    return (1);
}

static int  libui_draw_window(t_libui_window *window)
{
    t_list_head         components;
    t_libui_component   *comp;

    components = window->components;
    components.iterator = components.first;
    while ((comp = ttslist_iter_content(&components)))
        libui_draw_component(comp);
    libui_draw_render_image(window);
    return (1);
}

int	libui_draw_loop(t_libui_env *env)
{
	t_list_head		windows;
	t_libui_window	*win;

	windows = env->windows;
	windows.iterator = windows.first;
	while ((win = ttslist_iter_content(&windows)))
        libui_draw_window(win);
    return (1);
}