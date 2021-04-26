/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:39:50 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 11:46:43 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_draw_image_blit(t_sdl_image *canvas, t_sdl_image *to_draw, t_rect off)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < to_draw->height && i + off.y < canvas->height)
    {
        while (j < to_draw->width && j + off.x < canvas->width)
        {
            ft_sdl_set_image_pixel(canvas, j+off.x, i+off.y,
                ft_sdl_get_image_pixel(to_draw, j, i));
            j++;
        }
        i++;
    }
    return (0);
}