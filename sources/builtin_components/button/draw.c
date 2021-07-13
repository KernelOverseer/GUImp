/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:22:41 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 15:25:08 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_button_draw(t_libui_component *component)
{
    libui_component_recalculate_image(component);
    ft_bzero(component->image->pixels, sizeof(Uint32) *
        component->image->width * component->image->height);
    libui_builtin_draw_background(component);
    return (0);
}