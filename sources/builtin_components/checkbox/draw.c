/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:22:41 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 13:40:50 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int  draw_checkbox(t_libui_component *component)
{
    if (component->data)
    {
        ft_sdl_image_rect(component->image, (t_rect){
            component->style.width/2 - component->style.width/4,
            component->style.height/2 - component->style.height/4,
            component->style.width/2,
            component->style.height/2
        }, component->style.color);
    }
    return (0);
}

int libui_checkbox_draw(t_libui_component *component)
{
    libui_component_recalculate_image(component);
    ft_bzero(component->image->pixels, sizeof(Uint32) *
        component->image->width * component->image->height);
    libui_builtin_draw_background(component);
    draw_checkbox(component);
    return (0);
}