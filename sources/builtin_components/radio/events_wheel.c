/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_wheel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:01:48 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 14:05:13 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int             libui_radio_group_switch(t_libui_component *active)
{
    t_list_head         radios;
    t_libui_component   *component;

    if (!active->parent)
        return (0);
    radios = active->parent->children;
    radios.iterator = radios.first;
    while ((component = ttslist_iter_content(&radios)))
    {
        if (component != active && ft_strequ(component->status.name, "radio"))
        {
            component->data = NULL;
            component->status.re_render = 1;
        }
    }
    active->data = (void *)0xFF;
    return (1);
}

static int     scroll(t_libui_component *radio,
    SDL_Event *e)
{
    (void)radio;
    (void)e;
    return (1);
}

void    libui_radio_load_wheel_events(t_libui_component *component)
{
    component->events.scroll = scroll;
}