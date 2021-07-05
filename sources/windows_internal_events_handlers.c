/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_internal_events_handlers.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:27:28 by abiri             #+#    #+#             */
/*   Updated: 2021/07/05 23:58:45 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_windows_event_handler_call(t_libui_window_event_handler handler,
    t_libui_window *window, SDL_Event *e)
{
    if (!handler)
        return (0);
    return (handler(window, e));
}

int libui_windows_event_handler_focus_lost(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    env = window->env;
    env->focused_component = window->focused_component;
    env->active_window = window;
    return (libui_windows_event_handler_call(
            window->events.lose_focus, window, e));
}

int libui_windows_event_handler_focus_gained(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    env = window->env;
    env->focused_component = window->focused_component;
    env->active_window = window;
    return (libui_windows_event_handler_call(
            window->events.focus, window, e));
}

int libui_windows_event_handler_mouse_leave(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    env = window->env;
    if (env->hovered_component)
        libui_component_call_event(
            env->hovered_component->events.mouse_leave,
            env->hovered_component, e);
    env->hovered_component = NULL;
    return (1);
}

int libui_windows_event_handler_mouse_enter(t_libui_window *window, SDL_Event *e)
{
    (void)window;
    (void)e;
    return (1);
}

int libui_windows_event_handler_close(t_libui_window *window, SDL_Event *e)
{
    return (libui_windows_event_handler_call(
            window->events.close, window, e));
}

int libui_windows_event_handler_moved(t_libui_window *window, SDL_Event *e)
{
    return (libui_windows_event_handler_call(
            window->events.moved, window, e));
}

int libui_windows_event_handler_exposed(t_libui_window *window, SDL_Event *e)
{
    return (libui_windows_event_handler_call(
            window->events.exposed, window, e));
}

int libui_windows_event_handler_minimized(t_libui_window *window, SDL_Event *e)
{
    return (libui_windows_event_handler_call(
            window->events.minimized, window, e));
}

int libui_windows_event_handler_restored(t_libui_window *window, SDL_Event *e)
{
    return (libui_windows_event_handler_call(
            window->events.restored, window, e));
}

int libui_windows_event_handler_size_changed(t_libui_window *window, SDL_Event *e)
{
    libui_window_resize(window, e->window.data1, e->window.data2);
    return (libui_windows_event_handler_call(
            window->events.resize, window, e));
}