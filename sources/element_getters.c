/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:09:21 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 16:43:01 by abiri            ###   ########.fr       */
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

t_libui_component   *libui_window_get_active_component(t_libui_window *window,
    int mouse_x, int mouse_y)
{
    if (!libui_helpers_is_point_in_rect(
        (t_rect){window->props.height, window->props.width,
        window->props.pos_x, window->props.pos_y}, mouse_x, mouse_y))
        return (NULL);

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