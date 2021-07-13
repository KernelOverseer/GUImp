/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:59:25 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:08:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     focus(t_libui_component *div,
    SDL_Event *e)
{
    (void)div;
    (void)e;
    div->status.focused = TRUE;
    return (1);
}

static int     lose_focus(t_libui_component *div,
    SDL_Event *e)
{
    (void)div;
    (void)e;
    div->status.focused = FALSE;
    return (1);
}
static int     key_down(t_libui_component *div,
    SDL_Event *e)
{
    (void)div;
    (void)e;
    if (e->key.keysym.scancode == SDL_SCANCODE_SPACE ||
        e->key.keysym.scancode == SDL_SCANCODE_KP_SPACE)
        div->status.active = TRUE;
    return (1);
}

static int     key_up(t_libui_component *div,
    SDL_Event *e)
{
    (void)div;
    (void)e;
    if (e->key.keysym.scancode == SDL_SCANCODE_KP_ENTER ||
        e->key.keysym.scancode == SDL_SCANCODE_RETURN)
    {
        libui_component_user_event_call(div->user_events.on_click,
            div->data);
        div->status.active = FALSE;
    }
    return (1);
}

void    libui_div_load_keyboard_events(t_libui_component *component)
{
    component->events.focus = focus;
    component->events.lose_focus = lose_focus;
    component->events.key_down = key_down;
    component->events.key_up = key_up;
}