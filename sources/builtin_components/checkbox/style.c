/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:11:53 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 13:21:32 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void set_default_regular_style(t_libui_component *checkbox)
{
    checkbox->raw_styles.regular = (t_libui_raw_style){
        .width.value.integer = 25,
        .height.value.integer = 25,
        .pos_x = checkbox->style.pos_x,
        .pos_y = checkbox->style.pos_y,
        .background_color.value.integer = 0x0,
        .border_color.value.integer = 0xFF000000,
        .border_radius.value.integer = 2,
        .border_weight.value.integer = 2,
        .color.value.integer = 0xFF000000
    };
}

static void set_default_hovered_style(t_libui_component *checkbox)
{
    checkbox->raw_styles.hovered = checkbox->raw_styles.regular;
}

static void set_default_active_style(t_libui_component *checkbox)
{
    checkbox->raw_styles.active = checkbox->raw_styles.regular;
}
static void set_default_focused_style(t_libui_component *checkbox)
{
    checkbox->raw_styles.focused = checkbox->raw_styles.regular;
}

void    libui_checkbox_load_style(t_libui_component *checkbox)
{
    set_default_regular_style(checkbox);
    set_default_active_style(checkbox);
    set_default_focused_style(checkbox);
    set_default_hovered_style(checkbox);
}