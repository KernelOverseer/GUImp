/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:11:53 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:33:45 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void set_default_regular_style(t_libui_component *checkbox)
{
    checkbox->raw_styles.regular = (t_libui_raw_style){
        .width.value.integer = 20,
        .height.value.integer = 20,
        .pos_x = checkbox->style.pos_x,
        .pos_y = checkbox->style.pos_y,
        .background_color.value.integer = DEFAULT_COLOR_BACKGROUND_PRIMARY,
    };
}

static void set_default_hovered_style(t_libui_component *checkbox)
{
    checkbox->raw_styles.hovered = checkbox->raw_styles.regular;
    checkbox->raw_styles.hovered.background_color.value.integer = 
        DEFAULT_COLOR_BACKGROUND_SECONDARY;
}

static void set_default_active_style(t_libui_component *checkbox)
{
checkbox->raw_styles.active = checkbox->raw_styles.regular;
    checkbox->raw_styles.active.background_color.value.integer = 
        DEFAULT_COLOR_BACKGROUND_TERTIARY;
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