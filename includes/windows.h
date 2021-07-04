/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:49:24 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 18:36:41 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOWS_H
# define WINDOWS_H
# include "libui.h"

struct  s_libui_window_props
{
    char            *title;
    int             width;
    int             height;
    int             pos_x;
    int             pos_y;
    int             flags;
};

struct  s_libui_window
{
    t_libui_window_props    props;
    SDL_Window              *sdl_window;
    SDL_Renderer            *sdl_renderer;
    SDL_Texture             *sdl_texture;
    t_sdl_image             *main_image;
    struct s_libui_env      *env;
    t_libui_component       *focused_component;
    t_list_head             components;
};

/*
**  Window API
*/

void        libui_window_init(t_libui_window *win);
int         libui_window_create(t_libui_env *env, t_libui_window *win);
int         libui_window_insert_component(t_libui_window *window,t_libui_component *component);

/*
**  Internal Window API
*/

void        libui_draw_window(t_libui_window *window);
void        libui_window_draw(t_libui_window *window);
int         libui_window_resize(t_libui_window *win, int width, int height);
#endif