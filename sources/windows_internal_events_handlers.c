/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_internal_events_handlers.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:27:28 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 19:32:41 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_windows_event_handler_focus_lost(t_libui_env *env,
    t_libui_window *window, SDL_Event *e)
{
    (void)env;
    (void)window;
    (void)e;

    SDL_SetWindowTitle(window->sdl_window, "unfocused");
    return (1);
}

int libui_windows_event_handler_focus_gained(t_libui_env *env,
    t_libui_window *window, SDL_Event *e)
{
    (void)env;
    (void)window;
    (void)e;

    SDL_SetWindowTitle(window->sdl_window, "[FOCUSED]");
    return (1);
}

int libui_windows_event_handler_size_changed(t_libui_env *env,
    t_libui_window *window, SDL_Event *e)
{
    (void)env;

    libui_window_resize(window, e->window.data1, e->window.data2);
    return (1);
}