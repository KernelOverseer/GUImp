/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:54:00 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 15:01:51 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     mouse_enter(t_libui_component *button,
    SDL_Event *e)
{
    (void)button;
    (void)e;
    button->status.hovered = TRUE;
    return (1);
}

static int     mouse_leave(t_libui_component *button,
    SDL_Event *e)
{
    (void)button;
    (void)e;
    button->status.hovered = FALSE;
    return (1);
}
static int     active(t_libui_component *button,
    SDL_Event *e)
{
    (void)button;
    (void)e;
    button->status.active = TRUE;
    return (1);
}

static int     release(t_libui_component *button,
    SDL_Event *e)
{
    (void)button;
    (void)e;
    button->status.active = FALSE;
    if (button->status.hovered)
        libui_component_user_event_call(button->user_events.on_click,
            button->data);
    return (1);
}

void    libui_button_load_mouse_events(t_libui_component *component)
{
    component->events.mouse_enter = mouse_enter;
    component->events.mouse_leave = mouse_leave;
    component->events.active = active;
    component->events.release = release;
}