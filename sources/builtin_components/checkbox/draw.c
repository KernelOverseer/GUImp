/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:22:41 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 14:39:18 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_button_draw(t_libui_component *component)
{
    libui_component_style_compute(component);
    libui_builtin_draw_background(component);
    return (0);
}