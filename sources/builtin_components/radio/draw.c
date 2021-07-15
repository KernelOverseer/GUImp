/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:22:41 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 13:18:57 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int  draw_radio(t_libui_component *component)
{
    if (component->data)
    {
        ft_sdl_image_disc(component->image, (t_point){
            component->style.width/2,
            component->style.height/2
        },
            ft_int_min(component->style.width/2, component->style.height/2) * 0.5,
            component->style.color);
    }
    return (0);
}

int libui_radio_draw(t_libui_component *component)
{
    libui_component_recalculate_image(component);
    ft_bzero(component->image->pixels, sizeof(Uint32) *
        component->image->width * component->image->height);
    libui_builtin_draw_background(component);
    draw_radio(component);
    return (0);
}