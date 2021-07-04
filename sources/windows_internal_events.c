/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_internal_events.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:07:20 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 19:29:23 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

const t_libui_event_handler_map  g_windows_internal_events[] = {
    {.type=SDL_WINDOWEVENT_SIZE_CHANGED,
        .handler=libui_windows_event_handler_size_changed},
    {.type=SDL_WINDOWEVENT_FOCUS_GAINED,
        .handler=libui_windows_event_handler_focus_gained},
    {.type=SDL_WINDOWEVENT_FOCUS_LOST,
        .handler=libui_windows_event_handler_focus_lost},
    {.type=0, .handler=NULL},
};

t_libui_window  *libui_windows_event_get_window(t_libui_env *env, Uint32 window_id)
{
    t_libui_window  *window;
    t_list_head     window_list;

    window_list = env->windows;
    window_list.iterator = window_list.first;
    while ((window = ttslist_iter_content(&window_list)))
    {
        if (SDL_GetWindowID(window->sdl_window) == window_id)
            return (window);
    }
    return (NULL);
}

int libui_windows_event_dispatcher(t_libui_env *env, SDL_Event *e)
{
    t_libui_window                  *window;
    t_libui_internal_event_handler  handler;

    if (!(handler = libui_event_get_handler(g_windows_internal_events, e->window.event)))
        return (0);
    if (!(window = libui_windows_event_get_window(env, e->window.windowID)))
        return (0);
    handler(env, window, e);
    return (1);
}