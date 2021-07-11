/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:45:49 by abiri             #+#    #+#             */
/*   Updated: 2021/07/11 03:09:42 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int process_relative(t_libui_raw_style_prop child,
    int parent_value)
{
    int result;

    result = child.value.integer;
    if (child.type == STYLE_RELATIVE)
        result = parent_value * child.value.decimal;
    return (result);
}

static void compute_dimentions(t_libui_style *style,
    t_libui_component *parent, t_libui_raw_style *raw)
{
    if (parent)
    {
        style->width = process_relative(raw->width, parent->style.width);
        style->height = process_relative(raw->height, parent->style.height);
    }
    if (raw->position == STYLE_RELATIVE)
    {
        style->pos_x += raw->pos_x;
        style->pos_y += raw->pos_y;
    }
    else if (raw->position == STYLE_ABSOLUTE)
    {
        style->pos_x = raw->pos_x;
        style->pos_y = raw->pos_y;
    }
}

static float inherit_decimal(t_libui_raw_style_prop prop, float parent_value)
{
    if (prop.type == STYLE_INHERIT)
        return (parent_value);
    return prop.value.decimal;
}

static Uint32 inherit_integer(t_libui_raw_style_prop prop, Uint32 parent_value)
{
    if (prop.type == STYLE_INHERIT)
        return (parent_value);
    return prop.value.integer;
}

static void compute_inherit(t_libui_style *style, t_libui_style *parent,
    t_libui_raw_style *raw)
{
    style->background_color = inherit_integer(raw->background_color,
        parent->background_color);
    style->border_color = inherit_integer(raw->border_color,
        parent->border_color);
    style->border_weight = inherit_integer(raw->border_weight,
        parent->border_weight);
    style->border_opacity = inherit_decimal(raw->border_opacity,
        parent->border_opacity);
    style->border_radius = inherit_integer(raw->border_radius,
        parent->border_radius);
    style->box_shadow_color = inherit_integer(raw->box_shadow_color,
        parent->box_shadow_color);
    style->box_shadow_weight = inherit_integer(raw->box_shadow_weight,
        parent->box_shadow_weight);
    style->box_shadow_opacity = inherit_decimal(raw->box_shadow_opacity,
        parent->box_shadow_opacity);
    style->font_size = inherit_integer(raw->font_size,
        parent->font_size);
    style->font_weight = inherit_integer(raw->font_weight,
        parent->font_weight);
    style->opacity = inherit_decimal(raw->opacity,
        parent->opacity);
    style->color = inherit_integer(raw->color,
        parent->color)
}

static void compute_basic(t_libui_style *style, t_libui_raw_style *raw)
{
    style->background_color = raw->background_color.value.integer;
    style->border_color = raw->border_color.value.integer;
    style->border_weight = raw->border_weight.value.integer;
    style->border_opacity = raw->border_opacity.value.decimal;
    style->border_radius = raw->border_radius.value.integer;
    style->box_shadow_color = raw->box_shadow_color.value.integer;
    style->box_shadow_weight = raw->box_shadow_weight.value.integer;
    style->box_shadow_opacity = raw->box_shadow_opacity.value.decimal;
    style->font_size = raw->font_size.value.integer;
    style->font_weight = raw->font_weight.value.integer;
    style->opacity = raw->opacity.value.decimal;
    style->color = raw->color.value.integer;
}

static void compute_from_raw(t_libui_style *style,
    t_libui_component *parent, t_libui_raw_style *raw)
{
    compute_dimentions(style, parent, raw);
    compute_basic(style, raw);
    if (parent)
        compute_inherit(style, &parent->style, raw);
}

void    libui_component_style_compute(t_libui_component *component)
{
    t_libui_style   old_style;

    old_style = component->style;
    if (component->status.active)
        compute_from_raw(&component->style, component->parent,
            &component->raw_styles.active);
    else if (component->status.hovered)
        compute_from_raw(&component->style, component->parent,
            &component->raw_styles.hovered);
    else if (component->status.focused)
        compute_from_raw(&component->style, component->parent,
            &component->raw_styles.focused);
    else
        compute_from_raw(&component->style, component->parent,
            &component->raw_styles.regular);
    if (ft_memcmp(&old_style, &component->style, sizeof(t_libui_style)))
        component->status.re_render = TRUE;
}