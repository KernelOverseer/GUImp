/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:59:58 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 13:18:50 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void         constructor_init(t_libui_component *radio)
{
    radio->status.name = ft_strdup("radio");
    radio->draw = libui_radio_draw;
    libui_radio_load_keyboard_events(radio);
    libui_radio_load_mouse_events(radio);
    libui_radio_load_wheel_events(radio);
    libui_radio_load_style(radio);
}

t_libui_component   *libui_new_radio(t_libui_style props)
{
    t_libui_component    *result;

    if (!(result = malloc(sizeof(t_libui_component))))
        return (NULL);
    libui_component_init(result);
    result->style = props;
    constructor_init(result);
    return (result);
}