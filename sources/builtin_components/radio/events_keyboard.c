/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:59:25 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 13:55:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     focus(t_libui_component *radio,
    SDL_Event *e)
{
    (void)radio;
    (void)e;
    radio->status.focused = TRUE;
    return (1);
}

static int     lose_focus(t_libui_component *radio,
    SDL_Event *e)
{
    (void)radio;
    (void)e;
    radio->status.focused = FALSE;
    return (1);
}
static int     key_down(t_libui_component *radio,
    SDL_Event *e)
{
    (void)radio;
    (void)e;
    if (e->key.keysym.scancode == SDL_SCANCODE_KP_SPACE ||
        e->key.keysym.scancode == SDL_SCANCODE_SPACE)
        radio->status.active = TRUE;
    return (1);
}

static int     key_up(t_libui_component *radio,
    SDL_Event *e)
{
    (void)radio;
    (void)e;
    if (e->key.keysym.scancode == SDL_SCANCODE_KP_SPACE ||
        e->key.keysym.scancode == SDL_SCANCODE_SPACE)
    {
        libui_radio_group_switch(radio);
        radio->status.re_render = 1;
        libui_component_user_event_call(radio->user_events.on_click,
            radio->data);
        radio->status.active = FALSE;
    }
    return (1);
}

void    libui_radio_load_keyboard_events(t_libui_component *component)
{
    component->events.focus = focus;
    component->events.lose_focus = lose_focus;
    component->events.key_down = key_down;
    component->events.key_up = key_up;
}