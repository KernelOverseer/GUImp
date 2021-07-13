/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_draw_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:27:36 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 20:36:42 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static float    square_distance(t_point center, t_point point)
{
    return ((float)point.x - (float)center.x) * ((float)point.x - (float)center.x)
        + ((float)point.y - (float)center.y) * ((float)point.y - (float)center.y);
}

static int  in_border_corner(int x, int y, t_libui_component *component)
{
    t_point corner;
    float   distance;

    if (((y <= component->style.border_radius ||
        y >= component->style.height - component->style.border_radius) &&
        (x <= component->style.border_radius ||
        x >= component->style.width - component->style.border_radius)))
    {
        if (x <= component->style.border_radius)
            corner.x = component->style.border_radius;
        else
            corner.x = component->style.width - component->style.border_radius;
        if (y <= component->style.border_radius)
            corner.y = component->style.border_radius;
        else
            corner.y = component->style.height - component->style.border_radius;
        distance = square_distance(corner, (t_point){x, y});
        if (distance <=
            (float)(component->style.border_radius * component->style.border_radius))
        {
        //     if (distance >=
        //         (float)((component->style.border_radius - component->style.border_weight)
        //         * (component->style.border_radius - component->style.border_weight)))
        //     {
        //         ft_sdl_set_image_pixel(component->image, x, y, component->style.border_color);
        //         return (1);
        //     }
            return (0);
        }
        return (1);
    }
    return (0);
}

static void draw_background(t_libui_component *component)
{
    int y;
    int x;

    y = 0;
    while (y < component->style.height)
    {
        x = 0;
        while (x < component->style.width)
        {
            if (!in_border_corner(x, y, component))
                ft_sdl_set_image_pixel(component->image,
                    x, y, component->style.background_color);
            x++;
        }
        y++;
    }
}

int libui_builtin_draw_background(t_libui_component *component)
{
    draw_background(component);
    // draw_background_border_radius(component);
    libui_builtin_draw_border(component);
    return (0);
}