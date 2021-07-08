/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_internal_events_handlers.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:19:50 by abiri             #+#    #+#             */
/*   Updated: 2021/07/07 20:37:46 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_component_call_event(t_libui_component_event_handler handler,
    t_libui_component *component, SDL_Event *e)
{
    if (handler)
        return (handler(component, e));
    return (0);
}

int libui_components_event_handler_mouse_down(t_libui_env *env, SDL_Event *e)
{
    t_libui_window      *window;
    t_libui_component   *component;

    (void)env;
    (void)e;

    if (!(window = libui_windows_event_get_window(env, e->button.windowID)))
        return (0);
    component = libui_components_get_from_mouse(window,
        e->button.x, e->button.y);
    env->active_component = component;
    if (env->focused_component && env->focused_component != component)
    {
        libui_component_call_event(env->focused_component->events.lose_focus,
            env->focused_component, e);
    }
    if (component)
    {
        libui_component_call_event(component->events.active, component, e);
        if (env->focused_component != component)
            libui_component_call_event(component->events.focus, component, e);
    }
    env->focused_component = component;
    window->focused_component = component;
    return (1);
}

int libui_components_event_handler_mouse_up(t_libui_env *env, SDL_Event *e)
{
    (void)env;
    (void)e;

    if (env->active_component)
        libui_component_call_event(env->active_component->events.release,
        env->active_component, e);
    env->active_component = NULL;
    return (1);
}

int libui_components_event_handler_scroll_parent(t_libui_component *component,
    SDL_Event *e)
{
    if (!component)
        return (0);
    if (!libui_component_call_event(component->events.scroll, component, e))
        return (libui_components_event_handler_scroll_parent(component->parent, e));
    return (1);
}

int libui_components_event_handler_scroll(t_libui_env *env, SDL_Event *e)
{
    t_libui_window      *window;
    t_libui_component   *component;
    int                 x;
    int                 y;

    (void)env;
    (void)e;

    if (!(window = libui_windows_event_get_window(env, e->wheel.windowID)))
        return (0);
    SDL_GetMouseState(&x, &y);
    component = libui_components_get_from_mouse(window, x, y);
    return (libui_components_event_handler_scroll_parent(component, e));
}

int libui_components_event_handler_key_down(t_libui_env *env, SDL_Event *e)
{
    (void)e;
    (void)env;

    if (env->focused_component)
        return (libui_component_call_event(env->focused_component->events.key_down,
            env->focused_component, e));
    return (1);
}

int libui_components_event_handler_key_up(t_libui_env *env, SDL_Event *e)
{
    (void)e;
    (void)env;
    if (env->focused_component)
        return (libui_component_call_event(env->focused_component->events.key_up,
            env->focused_component, e));
    return (1);
}

int libui_components_event_handler_mouse_motion(t_libui_env *env, SDL_Event *e)
{
    t_libui_window      *window;
    t_libui_component   *component;

    (void)env;
    (void)e;
    if (!(window = libui_windows_event_get_window(env, e->motion.windowID)))
        return (0);
    component = libui_components_get_from_mouse(window,
        e->motion.x, e->motion.y);
    if (component != env->hovered_component)
    {
        if (component)
            libui_component_call_event(component->events.mouse_enter,
                component, e);
        if (env->hovered_component)
            libui_component_call_event(
                env->hovered_component->events.mouse_leave,
                env->hovered_component, e);
        env->hovered_component = component;
    }
    return (1); 
}