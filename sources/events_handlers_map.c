/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:41:28 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 15:43:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

const    t_libui_event_dispatcher_map   g_libui_event_dispatcher_map[LIBUI_NATIVE_EVENT_COUNT] = {
    {.event_type=SDL_MOUSEMOTION, .dispatcher=&libui_event_dispatcher_on_mouse_move},
    {.event_type=SDL_MOUSEBUTTONDOWN, .dispatcher=&libui_event_dispatcher_on_mouse_click},
    {.event_type=SDL_MOUSEBUTTONUP, .dispatcher=&libui_event_dispatcher_on_mouse_release}
};