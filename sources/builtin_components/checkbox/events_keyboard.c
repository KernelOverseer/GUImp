/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:59:25 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 15:04:13 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     focus(t_libui_component *button,
    SDL_Event *e)
{
    (void)button;
    (void)e;
    button->status.focused = TRUE;
    return (1);
}

static int     lose_focus(t_libui_component *button,
    SDL_Event *e)
{
    (void)button;
    (void)e;
    button->status.focused = FALSE;
    return (1);
}
static int     key_down(t_libui_component *button,
    SDL_Event *e)
{
    (void)button;
    (void)e;
    if (e->key.keysym.scancode == SDL_SCANCODE_KP_ENTER ||
        e->key.keysym.scancode == SDL_SCANCODE_RETURN)
        button->status.active = TRUE;
    return (1);
}

static int     key_up(t_libui_component *button,
    SDL_Event *e)
{
    (void)button;
    (void)e;
    if (e->key.keysym.scancode == SDL_SCANCODE_KP_ENTER ||
        e->key.keysym.scancode == SDL_SCANCODE_RETURN)
    {
        libui_component_user_event_call(button->user_events.on_click,
            button->data);
        button->status.active = FALSE;
    }
    return (1);
}

void    libui_button_load_keyboard_events(t_libui_component *component)
{
    component->events.focus = focus;
    component->events.lose_focus = lose_focus;
    component->events.key_down = key_down;
    component->events.key_up = key_up;
}