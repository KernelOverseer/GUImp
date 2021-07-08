/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_wheel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:01:48 by abiri             #+#    #+#             */
/*   Updated: 2021/07/07 20:08:36 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     scroll(t_libui_component *button,
    SDL_Event *e)
{
    (void)button;
    (void)e;
    return (1);
}

void    libui_button_load_wheel_events(t_libui_component *component)
{
    component->events.scroll = scroll;
}