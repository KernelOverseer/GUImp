/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:11:53 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 16:54:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void set_default_regular_style(t_libui_component *div)
{
    div->raw_styles.regular = (t_libui_raw_style){
        .width.value.integer = div->style.width,
        .height.value.integer = div->style.height,
        .pos_x = div->style.pos_x,
        .pos_y = div->style.pos_y,
        .background_color.value.integer = DEFAULT_COLOR_BACKGROUND_PRIMARY,
    };
}

static void set_default_hovered_style(t_libui_component *div)
{
    div->raw_styles.hovered = div->raw_styles.regular;
    div->raw_styles.hovered.background_color.value.integer = 
        DEFAULT_COLOR_BACKGROUND_SECONDARY;
}

static void set_default_active_style(t_libui_component *div)
{
div->raw_styles.active = div->raw_styles.regular;
    div->raw_styles.active.background_color.value.integer = 
        DEFAULT_COLOR_BACKGROUND_TERTIARY;
}

static void set_default_focused_style(t_libui_component *div)
{
    div->raw_styles.focused = div->raw_styles.regular;
}

void    libui_div_load_style(t_libui_component *div)
{
    set_default_regular_style(div);
    set_default_active_style(div);
    set_default_focused_style(div);
    set_default_hovered_style(div);
}