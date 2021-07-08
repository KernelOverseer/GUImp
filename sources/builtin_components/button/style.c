/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:11:53 by abiri             #+#    #+#             */
/*   Updated: 2021/07/07 22:34:26 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void set_default_regular_style(t_libui_component *button)
{
    button->raw_styles.regular = (t_libui_raw_style){
        .width = button->style.width,
        .height = button->style.height,
        .pos_x = button->style.pos_x,
        .pos_y = button->style.pos_y,
        .background_color = DEFAULT_COLOR_BACKGROUND_PRIMARY
    };
}

static void set_default_hovered_style(t_libui_component *button)
{
    button->raw_styles.hovered = (t_libui_raw_style){
        .width = button->style.width,
        .height = button->style.height,
        .pos_x = button->style.pos_x,
        .pos_y = button->style.pos_y,
        .background_color = DEFAULT_COLOR_BACKGROUND_SECONDARY
    };
}

static void set_default_active_style(t_libui_component *button)
{
    button->raw_styles.active = (t_libui_raw_style){
        .width = button->style.width,
        .height = button->style.height,
        .pos_x = button->style.pos_x,
        .pos_y = button->style.pos_y,
        .background_color = DEFAULT_COLOR_BACKGROUND_TERTIARY
    };
}

static void set_default_focused_style(t_libui_component *button)
{
    button->raw_styles.focused = (t_libui_raw_style){
        .width = button->style.width,
        .height = button->style.height,
        .pos_x = button->style.pos_x,
        .pos_y = button->style.pos_y,
        .background_color = DEFAULT_COLOR_BACKGROUND_PRIMARY
    };
}

void    libui_button_load_style(t_libui_component *button)
{
    set_default_regular_style(button);
    set_default_active_style(button);
    set_default_focused_style(button);
    set_default_hovered_style(button);
}