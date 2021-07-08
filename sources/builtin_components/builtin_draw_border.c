/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_draw_border.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:09:49 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 13:32:01 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

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
            ft_sdl_image_pixel(component->window->main_image,
                component->style.pos_x + j,
                component->style.pos_y + i,
                component->style.border_color);
            ft_sdl_image_pixel(component->window->main_image,
                component->style.pos_x + component->style.width - 1 - j,
                component->style.pos_y + i,
                component->style.border_color);
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
            ft_sdl_image_pixel(component->window->main_image,
                component->style.pos_x + i,
                component->style.pos_y + j,
                component->style.border_color);
            ft_sdl_image_pixel(component->window->main_image,
                component->style.pos_x + i,
                component->style.pos_y + component->style.height - 1 - j,
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
    return (0);
}