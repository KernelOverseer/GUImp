/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_wheel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:01:48 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:07:34 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int     scroll(t_libui_component *div,
    SDL_Event *e)
{
    (void)div;
    (void)e;
    return (1);
}

void    libui_div_load_wheel_events(t_libui_component *component)
{
    component->events.scroll = scroll;
}