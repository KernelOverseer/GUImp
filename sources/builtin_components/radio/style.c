/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:11:53 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 13:21:47 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void set_default_regular_style(t_libui_component *radio)
{
    radio->raw_styles.regular = (t_libui_raw_style){
        .width.value.integer = 25,
        .height.value.integer = 25,
        .pos_x = radio->style.pos_x,
        .pos_y = radio->style.pos_y,
        .background_color.value.integer = 0x0,
        .border_color.value.integer = 0xFF000000,
        .border_radius.value.decimal = 0.5,
        .border_radius.type = STYLE_RELATIVE,
        .border_weight.value.integer = 2,
        .color.value.integer = 0xFF000000
    };
}

static void set_default_hovered_style(t_libui_component *radio)
{
    radio->raw_styles.hovered = radio->raw_styles.regular;
}

static void set_default_active_style(t_libui_component *radio)
{
    radio->raw_styles.active = radio->raw_styles.regular;
}
static void set_default_focused_style(t_libui_component *radio)
{
    radio->raw_styles.focused = radio->raw_styles.regular;
}

void    libui_radio_load_style(t_libui_component *radio)
{
    set_default_regular_style(radio);
    set_default_active_style(radio);
    set_default_focused_style(radio);
    set_default_hovered_style(radio);
}