/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   css_prop_handler_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 02:59:09 by abiri             #+#    #+#             */
/*   Updated: 2021/07/11 03:19:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int  libui_css_prop_set_colors(t_css_prop *prop, t_libui_raw_style *style)
{
    if (ft_strequ(prop->key, "background-color"))
        style->background_color = css_parse_color(prop->value);
    else if (ft_strequ(prop->key, "border-color"))
        style->border_color = css_parse_color(prop->value);
    else if (ft_strequ(prop->key, "box-shadow-color"))
        style->box_shadow_color = css_parse_color(prop->value);
    else if (ft_strequ(prop->key, "color"))
        style->color = css_parse_color(prop->value);
    return (1);
}

static int  libui_css_prop_set_numbers(t_css_prop *prop, t_libui_raw_style *style)
{
    if (ft_strequ(prop->key, "width"))
        style->width = css_parse_size(prop->value);
    else if (ft_strequ(prop->key, "height"))
        style->height = css_parse_size(prop->value);
    else if (ft_strequ(prop->key, "border-weight"))
        style->border_weight = css_parse_size(prop->value); 
    else if (ft_strequ(prop->key, "border-opacity"))
        style->border_opacity = css_parse_size(prop->value); 
    else if (ft_strequ(prop->key, "border-radius"))
        style->border_radius = css_parse_size(prop->value);
    else if (ft_strequ(prop->key, "bos-shadow-weight"))
        style->box_shadow_weight = css_parse_size(prop->value);
    else if (ft_strequ(prop->key, "box-shadow-opacity"))
        style->box_shadow_opacity = css_parse_size(prop->value);
    else if (ft_strequ(prop->key, "font-size"))
        style->font_size = css_parse_size(prop->value); 
    else if (ft_strequ(prop->key, "font-weight"))
        style->font_weight = css_parse_size(prop->value);
    else if (ft_strequ(prop->key, "top"))
        style->pos_x = css_parse_size(prop->value).value.integer;
    else if (ft_strequ(prop->key, "left"))
        style->pos_y = css_parse_size(prop->value).value.integer;
    else if (ft_strequ(prop->key, "opacity"))
        style->opacity = css_parse_size(prop->value);
    return (1);
}

const t_libui_css_prop_handler_map  g_libui_css_prop_handlers[] = 
{
    {.name="background-color", .handler=libui_css_prop_set_colors},
    {.name="border-color", .handler=libui_css_prop_set_colors},
    {.name="box-shadow-color", .handler=libui_css_prop_set_colors},
    {.name="color", .handler=libui_css_prop_set_colors},
    {.name="width", .handler=libui_css_prop_set_numbers},
    {.name="height", .handler=libui_css_prop_set_numbers},
    {.name="border-weight", .handler=libui_css_prop_set_numbers},
    {.name="border-opacity", .handler=libui_css_prop_set_numbers},
    {.name="border-radius", .handler=libui_css_prop_set_numbers},
    {.name="box-shadow-weight", .handler=libui_css_prop_set_numbers},
    {.name="box-shadow-opacity", .handler=libui_css_prop_set_numbers},
    {.name="font-size", .handler=libui_css_prop_set_numbers},
    {.name="font-weight", .handler=libui_css_prop_set_numbers},
    {.name="top", .handler=libui_css_prop_set_numbers},
    {.name="left", .handler=libui_css_prop_set_numbers},
    {.name="opacity", .handler=libui_css_prop_set_numbers},
    {.name=NULL, .handler=NULL}
}