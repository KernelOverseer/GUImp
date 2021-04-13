/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:09:21 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 17:35:16 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
**  Findinf if mouse is in a rectangle
*/

int                 libui_helpers_is_point_in_rect(t_rect   rect, int x, int y)
{
    if (x < rect.x || x > rect.x + rect.w || y < rect.y || y > rect.y + rect.h)
        return (0);
    return (1);
}

/*
**  Finding the component under the mouse cursor
**  TO DO:
**      - do a bfs in the component tree and find which component the cursor is on
**      - find a way to organise components like a z-index
**      - check display property, and ignore display: none;
**      - should parent be the one selected, or child, or both.

**      Will be back after a correction
*/

t_libui_component   *libui_event_get_hovered_sub_component(
    t_libui_component *parent, int mouse_x, int mouse_y)
{
    t_list_head         children;
    t_libui_component   *child;
    t_libui_component   *result;

    children = parent->children;
    children.iterator = children.first;
    while ((child = ttslist_iter_content(&children)))
    {
        if ((result = libui_event_get_hovered_sub_component(child,
            mouse_x, mouse_y)))
            return (result);
    }
    if (libui_helpers_is_point_in_rect((t_rect){
        .h=parent->props.height, .w=parent->props.width,
        .x=parent->props.posX, .y=parent->props.posY}, mouse_x, mouse_y))
        return (parent);
    return (NULL);
}

t_libui_component   *libui_event_get_hovered_component_in_window(
    t_libui_window *window, int mouse_x, int mouse_y)
{
    t_list_head         components;
    t_libui_component   *component;
    t_libui_component   *result;

    components = window->components;
    components.iterator = components.first;
    while ((component = ttslist_iter_content(&components)))
    {
        if ((result = libui_event_get_hovered_sub_component(component,
            mouse_x, mouse_y)))
            return (result);
    }
    return (NULL);
}

t_libui_window  *libui_window_get_by_index(t_libui_env *env, int id)
{
    t_list_head     windows;
    t_libui_window  *window;

    windows = env->windows;
    windows.iterator = windows.first;
    while ((window = ttslist_iter_content(&windows)))
    {
        if (SDL_GetWindowID(window->sdl_window) == id)
            return (window);
    }
    return (NULL);
}

/*
**  Doing binary search to find the dispatcher for the event, since they are sorted
*/

t_libui_event_dispatcher    libui_event_get_dispatcher_from_type(Uint32 type)
{
    int first;
    int last;
    int mid;

    first = 0;
    last = LIBUI_NATIVE_EVENT_COUNT - 1;

    while (first <= last)
    {
        mid = (last + first) / 2;
        if (type == g_libui_event_dispatcher_map[mid].event_type)
            return (g_libui_event_dispatcher_map[mid].dispatcher);
        else if (g_libui_event_dispatcher_map[mid].event_type < type)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return (NULL);
}