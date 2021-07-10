/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:12:07 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 18:10:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void        libui_draw_blit_image(t_rect pos, t_sdl_image *canvas,
    t_sdl_image *image)
{
    int x;
    int y;

    y = 0;
    while (y < pos.h)
    {
        x = 0;
        while (x < pos.w)
        {
            ft_sdl_set_image_pixel(canvas, pos.x + x, pos.y + y,
                ft_sdl_get_image_pixel(image, x, y));
            x++;
        }
        y++;
    }
}

static void libui_draw_windows(t_libui_env *env)
{
    t_list_head     windows_list;
    t_libui_window  *window;

    windows_list = env->windows;
    windows_list.iterator = windows_list.first;
    while ((window = ttslist_iter_content(&windows_list)))
        libui_draw_window(window);
}

void            libui_draw(t_libui_env *env)
{
    libui_draw_windows(env);
}