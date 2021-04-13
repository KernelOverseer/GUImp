/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:21:24 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 19:10:20 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
**  TODO:
**      Make hovering outside the window disable all hovered components
**      OR make it so that every frame the status is reset
*/

int     libui_event_dispatcher_on_mouse_click(t_libui_env *env, t_libui_window *window,
                        SDL_Event *e)
{
    t_libui_component   *active_component;

    active_component = libui_event_get_hovered_component_in_window(window,
        e->button.x, e->button.y);
    if (!active_component)
        return (0);
    window->focused_component = active_component;
    libui_component_apply_event(active_component,
        active_component->events.on_click,
        libui_event_create_from_sdl(e));
    return (1);
}

int     libui_event_dispatcher_on_mouse_release(t_libui_env *env, t_libui_window *window,
                        SDL_Event *e)
{
    t_libui_component   *active_component;

    if (!(active_component = window->focused_component))
        return (0);
    libui_component_apply_event(active_component,
        active_component->events.on_release,
        libui_event_create_from_sdl(e));
    return (1);
}

int     libui_event_dispatcher_on_mouse_move(t_libui_env *env, t_libui_window *window,
                        SDL_Event *e)
{
    t_libui_component   *active_component;
    t_libui_event       event;

    event = libui_event_create_from_sdl(e);
    active_component = libui_event_get_hovered_component_in_window(window,
        e->motion.x, e->motion.y);
    if (window->hovered_component)
    {
        libui_component_apply_event(window->hovered_component,
            window->hovered_component->events.on_mouse_move,
            event);
    }
    if (window->hovered_component != active_component)
    {
        if (window->hovered_component)
            libui_component_apply_event(window->hovered_component,
            window->hovered_component->events.on_mouse_out,
            event);
        if (active_component)
        {
            libui_component_apply_event(active_component,
            active_component->events.on_mouse_enter,
            event);
            libui_component_apply_event(active_component,
            active_component->events.on_mouse_move,
            event);
        }
        window->hovered_component = active_component;
    }
    return (0);
}