/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:59:58 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 15:02:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void         constructor_init(t_libui_component *button)
{
    button->draw = libui_button_draw;
    libui_button_load_keyboard_events(button);
    libui_button_load_mouse_events(button);
    libui_button_load_wheel_events(button);
    libui_button_load_style(button);
}

t_libui_component   *libui_new_button(t_libui_style props)
{
    t_libui_component    *result;

    if (!(result = malloc(sizeof(t_libui_component))))
        return (NULL);
    libui_component_init(result);
    result->style = props;
    constructor_init(result);
    return (result);
}