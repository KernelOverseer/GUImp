/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 23:04:16 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 16:42:21 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "windows.h"

int         libui_window_resize(t_libui_window *win, int width, int height)
{
    win->props.width = width;
    win->props.height = height;
    free(win->main_image->pixels);
    free(win->main_image);
    if (!(win->main_image = newimage(width, height)))
    {
        libui_set_error("Cannot resize image for window\n");
        return (0);
    }
    SDL_DestroyTexture(win->sdl_texture);
    if (!(win->sdl_texture = SDL_CreateTexture(win->sdl_renderer,
        SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC,
        win->props.width, win->props.height)))
    {
        libui_set_error("Cannot resize texture for window\n");
        return (0);
    } 
    return (1);
}

void        libui_window_init(t_libui_window *win)
{
    ft_bzero(win, sizeof(t_libui_window));
    win->props = (t_libui_window_props){
        .title=NULL,
        .width=500,
        .height=500,
        .pos_x=SDL_WINDOWPOS_UNDEFINED,// hmmm
        .pos_y=SDL_WINDOWPOS_UNDEFINED,
        .flags=SDL_WINDOW_SHOWN
    };
    ttslist_init(&win->components);
}

static int  libui_window_create_render_texture(t_libui_window *win)

{
    if (!(win->sdl_renderer = SDL_CreateRenderer(win->sdl_window, -1,
        SDL_RENDERER_ACCELERATED))) // SDL_RENDERER_PRESENTVSYNC makes events slower ???
    {
        libui_set_error("Cannot create renderer for window");
        return (0);
    }
    if (!(win->sdl_texture = SDL_CreateTexture(win->sdl_renderer,
        SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC,// hmmm
        win->props.width, win->props.height)))
    {
        libui_set_error("Cannot create texture for window\n");
        return (0);
    }
    return (1);
}

int         libui_window_create(t_libui_env *env, t_libui_window *win)
{
    win->sdl_window = SDL_CreateWindow(win->props.title, win->props.pos_x,
        win->props.pos_y, win->props.width, win->props.height, win->props.flags);
    if (!win->sdl_window)
    {
        libui_set_error("Cannot create new window\n");
        return (0);
    }
    if (!libui_window_create_render_texture(win))
    {
        libui_set_error("Cannot get texture from window\n");
        return (0);
    }
    win->main_image = newimage(win->props.width, win->props.height);
    if (!win->main_image)
    {
        libui_set_error("Cannot allocate image for window\n");
        return (0);
    }
    win->env = env;
    env->windows.push(&(env->windows), win);
    return (1);
}

int         libui_window_insert_component(t_libui_window *window, t_libui_component *component)
{
    if (!component || !window)
        return (0);
    component->window = window;
    window->components.push(&(window->components), component);
    return (1);
}