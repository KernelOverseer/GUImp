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

static void set_default_regular_style(t_libui_component *text)
{
    text->raw_styles.regular = (t_libui_raw_style){
        .width.value.integer = text->style.width,
        .height.value.integer = text->style.height,
        .pos_x = text->style.pos_x,
        .pos_y = text->style.pos_y,
        .background_color.value.integer = DEFAULT_COLOR_BACKGROUND_PRIMARY,
    };
}

static void set_default_hovered_style(t_libui_component *text)
{
    text->raw_styles.hovered = text->raw_styles.regular;
    text->raw_styles.hovered.background_color.value.integer = 
        DEFAULT_COLOR_BACKGROUND_SECONDARY;
}

static void set_default_active_style(t_libui_component *text)
{
text->raw_styles.active = text->raw_styles.regular;
    text->raw_styles.active.background_color.value.integer = 
        DEFAULT_COLOR_BACKGROUND_TERTIARY;
}

static void set_default_focused_style(t_libui_component *text)
{
    text->raw_styles.focused = text->raw_styles.regular;
}

void    libui_text_load_style(t_libui_component *text)
{
    set_default_regular_style(text);
    set_default_active_style(text);
    set_default_focused_style(text);
    set_default_hovered_style(text);
}