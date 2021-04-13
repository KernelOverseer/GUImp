/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_click.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:44:50 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 19:07:50 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int     libui_component_button_event_on_mouse_click(void *component,
    t_libui_event event_data, void *args)
{
    t_libui_component   *button;

    button = component;
    button->props.state = LIBUI_COMPONENT_STATE_ACTIVE;
    return (1);
}