/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_internal_events.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:54:52 by abiri             #+#    #+#             */
/*   Updated: 2021/07/05 19:28:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

const t_libui_component_event_handler_map   g_component_internal_events[] = {
    {.type=SDL_MOUSEMOTION,
        .handler=libui_components_event_handler_mouse_motion},
    {.type=SDL_MOUSEBUTTONDOWN,
        .handler=libui_components_event_handler_mouse_down},
    {.type=SDL_MOUSEBUTTONUP,
        .handler=libui_components_event_handler_mouse_up},
    {.type=SDL_MOUSEWHEEL,
        .handler=libui_components_event_handler_scroll},
    {.type=SDL_KEYDOWN,
        .handler=libui_components_event_handler_key_down},
    {.type=SDL_KEYUP,
        .handler=libui_components_event_handler_key_up},
    {.type=0, .handler=NULL},
};

int     libui_components_event_dispatcher(t_libui_env *env, SDL_Event *e)
{
    t_libui_event_handler handler;

    if (!(handler = libui_component_event_get_handler(
        g_component_internal_events, e->type)))
        return (0);
    return (handler(env, e));
}

static t_libui_component   *libui_components_get_child_from_mouse(
    t_libui_component *parent, int x, int y)
{
    t_rect              component_rect;
    t_list_head         component_list;
    t_libui_component   *component;

    component_list = parent->children;
    component_list.iterator = component_list.first;
    component_rect = (t_rect){parent->style.pos_x, parent->style.pos_y,
        parent->style.width, parent->style.height};
    while ((component = ttslist_iter_content(&component_list)))
    {
        if ((component =
            libui_components_get_child_from_mouse(component, x, y)))
            return (component);
    }
    if (libui_mouse_is_in_rect(x, y, component_rect))
        return (parent);
    return (NULL);
}

t_libui_component   *libui_components_get_from_mouse(t_libui_window *window,
    int x, int y)
{
    t_list_head         component_list;
    t_libui_component   *component;

    component_list = window->components;
    component_list.iterator = component_list.first;
    while ((component = ttslist_iter_content(&component_list)))
    {
        if ((component = libui_components_get_child_from_mouse(component,
            x, y)))
            return (component);
    }
    return (NULL);
}