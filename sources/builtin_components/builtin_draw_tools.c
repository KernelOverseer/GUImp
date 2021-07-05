/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_draw_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:27:36 by abiri             #+#    #+#             */
/*   Updated: 2021/07/06 00:29:58 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_builtin_draw_background(t_libui_component *component)
{
    ft_sdl_image_rect(component->window->main_image, (t_rect){
        component->style.pos_x, component->style.pos_y,
        component->style.width, component->style.height
    }, component->style.background_color);
    return (0);
}