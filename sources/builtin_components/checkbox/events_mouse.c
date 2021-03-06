/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:54:00 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:36:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     mouse_enter(t_libui_component *checkbox,
    SDL_Event *e)
{
    (void)checkbox;
    (void)e;
    checkbox->status.hovered = TRUE;
    return (1);
}

static int     mouse_leave(t_libui_component *checkbox,
    SDL_Event *e)
{
    (void)checkbox;
    (void)e;
    checkbox->status.hovered = FALSE;
    return (1);
}
static int     active(t_libui_component *checkbox,
    SDL_Event *e)
{
    (void)checkbox;
    (void)e;
    checkbox->status.active = TRUE;
    return (1);
}

static int     release(t_libui_component *checkbox,
    SDL_Event *e)
{
    (void)checkbox;
    (void)e;
    checkbox->status.active = FALSE;
    if (checkbox->status.hovered)
    {
        checkbox->data = (void*)(~((unsigned long long)checkbox->data));
        checkbox->status.re_render = 1;
        libui_component_user_event_call(checkbox->user_events.on_click,
            checkbox->data);
    }
    return (1);
}

void    libui_checkbox_load_mouse_events(t_libui_component *component)
{
    component->events.mouse_enter = mouse_enter;
    component->events.mouse_leave = mouse_leave;
    component->events.active = active;
    component->events.release = release;
}