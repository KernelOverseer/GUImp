/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_internal_events_handlers.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:27:28 by abiri             #+#    #+#             */
/*   Updated: 2021/07/05 20:24:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_windows_event_handler_focus_lost(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    (void)e;
    env = window->env;
    env->focused_component = window->focused_component;
    env->active_window = window;
    return (1);
}

int libui_windows_event_handler_focus_gained(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    (void)e;
    env = window->env;
    env->focused_component = window->focused_component;
    env->active_window = window;
    return (1);
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
    t_libui_env *env;

    (void)env;
    (void)window;
    (void)e;
    env = window->env;
    return (1);
}

int libui_windows_event_handler_close(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    (void)env;
    (void)window;
    (void)e;
    env = window->env;
    return (1);
}

int libui_windows_event_handler_moved(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    (void)env;
    (void)window;
    (void)e;
    env = window->env;
    return (1);
}

int libui_windows_event_handler_exposed(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    (void)env;
    (void)window;
    (void)e;
    env = window->env;
    return (1);
}

int libui_windows_event_handler_minimized(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    (void)env;
    (void)window;
    (void)e;
    env = window->env;
    return (1);
}

int libui_windows_event_handler_restored(t_libui_window *window, SDL_Event *e)
{
    t_libui_env *env;

    (void)env;
    (void)window;
    (void)e;
    env = window->env;
    return (1);
}

int libui_windows_event_handler_size_changed(t_libui_window *window, SDL_Event *e)
{
    libui_window_resize(window, e->window.data1, e->window.data2);
    return (1);
}