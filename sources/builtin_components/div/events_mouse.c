/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:54:00 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:08:40 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     mouse_enter(t_libui_component *div,
    SDL_Event *e)
{
    (void)div;
    (void)e;
    div->status.hovered = TRUE;
    return (1);
}

static int     mouse_leave(t_libui_component *div,
    SDL_Event *e)
{
    (void)div;
    (void)e;
    div->status.hovered = FALSE;
    return (1);
}
static int     active(t_libui_component *div,
    SDL_Event *e)
{
    (void)div;
    (void)e;
    div->status.active = TRUE;
    return (1);
}

static int     release(t_libui_component *div,
    SDL_Event *e)
{
    (void)div;
    (void)e;
    div->status.active = FALSE;
    if (div->status.hovered)
        libui_component_user_event_call(div->user_events.on_click,
            div->data);
    return (1);
}

void    libui_div_load_mouse_events(t_libui_component *component)
{
    component->events.mouse_enter = mouse_enter;
    component->events.mouse_leave = mouse_leave;
    component->events.active = active;
    component->events.release = release;
}