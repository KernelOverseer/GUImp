/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:11:53 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 15:27:33 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void set_default_regular_style(t_libui_component *button)
{
    button->raw_styles.regular = (t_libui_raw_style){
        .width.value.integer = button->style.width,
        .height.value.integer = button->style.height,
        .pos_x = button->style.pos_x,
        .pos_y = button->style.pos_y,
        .background_color.value.integer = DEFAULT_COLOR_BACKGROUND_PRIMARY,
        .border_weight.value.integer = 2,
        .border_radius.value.integer = 20
    };
}

static void set_default_hovered_style(t_libui_component *button)
{
    button->raw_styles.hovered = button->raw_styles.regular;
    button->raw_styles.hovered.background_color.value.integer = 
        DEFAULT_COLOR_BACKGROUND_SECONDARY;
}

static void set_default_active_style(t_libui_component *button)
{
button->raw_styles.active = button->raw_styles.regular;
    button->raw_styles.active.background_color.value.integer = 
        DEFAULT_COLOR_BACKGROUND_TERTIARY;
}
static void set_default_focused_style(t_libui_component *button)
{
    button->raw_styles.focused = button->raw_styles.regular;
}

void    libui_button_load_style(t_libui_component *button)
{
    set_default_regular_style(button);
    set_default_active_style(button);
    set_default_focused_style(button);
    set_default_hovered_style(button);
}