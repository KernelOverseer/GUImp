/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:59:58 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:27:03 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void         constructor_init(t_libui_component *checkbox)
{
    checkbox->status.name = ft_strdup("checkbox");
    checkbox->draw = libui_checkbox_draw;
    libui_checkbox_load_keyboard_events(checkbox);
    libui_checkbox_load_mouse_events(checkbox);
    libui_checkbox_load_wheel_events(checkbox);
    libui_checkbox_load_style(checkbox);
}

t_libui_component   *libui_new_checkbox(t_libui_style props)
{
    t_libui_component    *result;

    if (!(result = malloc(sizeof(t_libui_component))))
        return (NULL);
    libui_component_init(result);
    result->style = props;
    constructor_init(result);
    return (result);
}