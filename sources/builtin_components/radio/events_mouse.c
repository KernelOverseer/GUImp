/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:54:00 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 13:55:50 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     mouse_enter(t_libui_component *radio,
    SDL_Event *e)
{
    (void)radio;
    (void)e;
    radio->status.hovered = TRUE;
    return (1);
}

static int     mouse_leave(t_libui_component *radio,
    SDL_Event *e)
{
    (void)radio;
    (void)e;
    radio->status.hovered = FALSE;
    return (1);
}
static int     active(t_libui_component *radio,
    SDL_Event *e)
{
    (void)radio;
    (void)e;
    radio->status.active = TRUE;
    return (1);
}

static int     release(t_libui_component *radio,
    SDL_Event *e)
{
    (void)radio;
    (void)e;
    radio->status.active = FALSE;
    if (radio->status.hovered)
    {
        libui_radio_group_switch(radio);
        radio->status.re_render = 1;
        libui_component_user_event_call(radio->user_events.on_click,
            radio->data);
    }
    return (1);
}

void    libui_radio_load_mouse_events(t_libui_component *component)
{
    component->events.mouse_enter = mouse_enter;
    component->events.mouse_leave = mouse_leave;
    component->events.active = active;
    component->events.release = release;
}