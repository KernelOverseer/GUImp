/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:59:25 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:35:58 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     focus(t_libui_component *checkbox,
    SDL_Event *e)
{
    (void)checkbox;
    (void)e;
    checkbox->status.focused = TRUE;
    return (1);
}

static int     lose_focus(t_libui_component *checkbox,
    SDL_Event *e)
{
    (void)checkbox;
    (void)e;
    checkbox->status.focused = FALSE;
    return (1);
}
static int     key_down(t_libui_component *checkbox,
    SDL_Event *e)
{
    (void)checkbox;
    (void)e;
    if (e->key.keysym.scancode == SDL_SCANCODE_KP_SPACE ||
        e->key.keysym.scancode == SDL_SCANCODE_SPACE)
        checkbox->status.active = TRUE;
    return (1);
}

static int     key_up(t_libui_component *checkbox,
    SDL_Event *e)
{
    (void)checkbox;
    (void)e;
    if (e->key.keysym.scancode == SDL_SCANCODE_KP_SPACE ||
        e->key.keysym.scancode == SDL_SCANCODE_SPACE)
    {
        checkbox->data = (void*)(~((unsigned long long)checkbox->data));
        checkbox->status.re_render = 1;
        libui_component_user_event_call(checkbox->user_events.on_click,
            checkbox->data);
        checkbox->status.active = FALSE;
    }
    return (1);
}

void    libui_checkbox_load_keyboard_events(t_libui_component *component)
{
    component->events.focus = focus;
    component->events.lose_focus = lose_focus;
    component->events.key_down = key_down;
    component->events.key_up = key_up;
}