/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:22:41 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 16:49:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_div_draw(t_libui_component *component)
{
    libui_component_recalculate_image(component);
    ft_bzero(component->image->pixels, sizeof(Uint32) *
        component->image->width * component->image->height);
    libui_builtin_draw_background(component);
    return (0);
}