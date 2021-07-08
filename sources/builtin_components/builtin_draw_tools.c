/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_draw_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:27:36 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 14:36:32 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int  in_border_corner(int x, int y, t_libui_component *component)
{
    return (((y < component->style.border_radius ||
        y > component->style.height - component->style.border_radius) &&
        (x < component->style.border_radius ||
        x > component->style.width - component->style.border_radius)));
}

static void draw_background_border_radius(t_libui_component *component)
{
    ft_sdl_image_disc(component->window->main_image,
    (t_point){component->style.pos_x + component->style.border_radius,
    component->style.pos_y + component->style.border_radius},
    component->style.border_radius, component->style.background_color);
    ft_sdl_image_disc(component->window->main_image,
    (t_point){component->style.pos_x + component->style.width - 2 - component->style.border_radius,
    component->style.pos_y + component->style.border_radius},
    component->style.border_radius, component->style.background_color);
    ft_sdl_image_disc(component->window->main_image,
    (t_point){component->style.pos_x + component->style.border_radius,
    component->style.pos_y + component->style.height - 1 - component->style.border_radius},
    component->style.border_radius, component->style.background_color);
    ft_sdl_image_disc(component->window->main_image,
    (t_point){component->style.pos_x + component->style.width - 2 - component->style.border_radius,
    component->style.pos_y + component->style.height - 1 - component->style.border_radius},
    component->style.border_radius, component->style.background_color);
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
                ft_sdl_image_pixel(component->window->main_image,
                    component->style.pos_x + x,
                    component->style.pos_y + y,
                    component->style.background_color);
            x++;
        }
        y++;
    }
}

int libui_builtin_draw_background(t_libui_component *component)
{
    // ft_sdl_image_rect(component->window->main_image, (t_rect){
    //     component->style.pos_x, component->style.pos_y,
    //     component->style.width, component->style.height
    // }, component->style.background_color);
    draw_background(component);
    draw_background_border_radius(component);
    libui_builtin_draw_border(component);
    return (0);
}