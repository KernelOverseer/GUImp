/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:57:14 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 19:07:01 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int     libui_component_button_event_on_mouse_move(void *component,
    t_libui_event event_data, void *args)
{
    t_libui_component   *button;

    button = component;
    if (button->props.state != LIBUI_COMPONENT_STATE_ACTIVE)
        button->props.state = LIBUI_COMPONENT_STATE_HOVERED;
    return (1);
}