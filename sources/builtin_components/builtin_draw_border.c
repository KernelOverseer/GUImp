/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_draw_border.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:09:49 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 19:27:49 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"


static void draw_border_arcs(t_libui_component *component)
{
    int i;

    i = 0;
    while (i < component->style.border_weight)
    {
        ft_sdl_image_arc_left_top(component->image,
        (t_point){component->style.border_radius,
        component->style.border_radius},
        component->style.border_radius - i, component->style.border_color);
        ft_sdl_image_arc_right_top(component->image,
        (t_point){component->style.width - 2 - component->style.border_radius,
        component->style.border_radius},
        component->style.border_radius - i, component->style.border_color);
        ft_sdl_image_arc_left_bottom(component->image,
        (t_point){component->style.border_radius,
        component->style.height - 1 - component->style.border_radius},
        component->style.border_radius - i, component->style.border_color);
        ft_sdl_image_arc_right_bottom(component->image,
        (t_point){component->style.width - 2 - component->style.border_radius,
        component->style.height - 1 - component->style.border_radius},
        component->style.border_radius - i, component->style.border_color);
        i++;
    }
}

static void draw_horizontal_border(t_libui_component *component)
{
    int i;
    int j;

    i = component->style.border_radius;
    while (i < component->style.height - component->style.border_radius)
    {
        j = 0;
        while (j < component->style.border_weight)
        {
            ft_sdl_set_image_pixel(component->image,
                j, i, component->style.border_color);
            ft_sdl_set_image_pixel(component->image, component->style.width
                - 1 - j, i, component->style.border_color);
            j++;
        }
        i++;
    }
}

static void draw_vertical_border(t_libui_component *component)
{
    int i;
    int j;

    i = component->style.border_radius;
    while (i < component->style.width - component->style.border_radius)
    {
        j = 0;
        while (j < component->style.border_weight)
        {
            ft_sdl_set_image_pixel(component->image, i, j,
                component->style.border_color);
            ft_sdl_set_image_pixel(component->image,
                i, component->style.height - 1 - j,
                component->style.border_color);
            j++;
        }
        i++;
    }
}

int libui_builtin_draw_border(t_libui_component *component)
{
    draw_vertical_border(component);
    draw_horizontal_border(component);
    draw_border_arcs(component);
    return (0);
}